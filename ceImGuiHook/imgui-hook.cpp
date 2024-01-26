#define WIN32_LEAN_AND_MEAN
#define DEFAULT_KEY VK_RSHIFT

#include <windows.h>
#include <cocos2d.h>
#include <format>
#include "imgui-hook.hpp"
#include "ModUtils.hpp"

using namespace cocos2d;

int toggleKey = DEFAULT_KEY;

void _stub() {}
std::function<void()> g_drawFunc = _stub;
std::function<void()> g_toggleCallback = _stub;
std::function<void()> g_initFunc = _stub;

void ImGuiHook::setRenderFunction(std::function<void()> func) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"({})", func.target_type().name()));
    g_drawFunc = func;
}

void ImGuiHook::setToggleCallback(std::function<void()> func) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"({})", func.target_type().name()));
    g_toggleCallback = func;
}

void ImGuiHook::setInitFunction(std::function<void()> func) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"({})", func.target_type().name()));
    g_initFunc = func;
}

void ImGuiHook::setToggleKey(int key) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"({})", key));
    toggleKey = key;
}


bool g_inited = false;

void(__thiscall* CCEGLView_swapBuffers)(CCEGLView*);
void __fastcall CCEGLView_swapBuffers_H(CCEGLView* self) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"((bool){})", (bool)self));
    auto window = self->getWindow();

    if (!g_inited) {
        if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" reached !g_inited block"));
        g_inited = true;
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::GetIO();
        auto hwnd = WindowFromDC(*reinterpret_cast<HDC*>(reinterpret_cast<uintptr_t>(window) + 0x244));
        ImGui_ImplWin32_Init(hwnd);
        ImGui_ImplWin32_InitForOpenGL(hwnd);
        ImGui_ImplOpenGL3_Init();
        if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" !g_inited block: call g_initFunc"));
        g_initFunc();
    }

    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" OpenGL3_NewFrame"));
    ImGui_ImplOpenGL3_NewFrame();
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" Win32_NewFrame"));
    ImGui_ImplWin32_NewFrame();
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" ImGui::NewFrame"));
    ImGui::NewFrame();

    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" g_drawFunc"));
    g_drawFunc();

    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" EndFrame"));
    ImGui::EndFrame();
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" Render"));
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" glFlush"));
    glFlush();

    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" call org((bool){}).", (bool)CCEGLView_swapBuffers));
    CCEGLView_swapBuffers(self);
}

// why is this an extern
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void(__thiscall* CCEGLView_pollEvents)(void*);
void __fastcall CCEGLView_pollEvents_H(void* self) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"((bool){})", (bool)self));

    if (!g_inited)
    {
        if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" reached !g_inited block"));
        // Call original function
        if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" ret org((bool){}).", (bool)CCEGLView_pollEvents));
        CCEGLView_pollEvents(self);
        return;
    }

    auto& io = ImGui::GetIO();
    bool block_input = false;
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);

        // Block input if ImGui wants to capture it
        if (io.WantCaptureMouse)
        {
            switch (msg.message)
            {
            case WM_LBUTTONDBLCLK:
            case WM_LBUTTONDOWN:
            case WM_LBUTTONUP:
            case WM_MBUTTONDBLCLK:
            case WM_MBUTTONDOWN:
            case WM_MBUTTONUP:
            case WM_MOUSEACTIVATE:
            case WM_MOUSEHOVER:
            case WM_MOUSEHWHEEL:
            case WM_MOUSELEAVE:
            case WM_MOUSEMOVE:
            case WM_MOUSEWHEEL:
            case WM_NCLBUTTONDBLCLK:
            case WM_NCLBUTTONDOWN:
            case WM_NCLBUTTONUP:
            case WM_NCMBUTTONDBLCLK:
            case WM_NCMBUTTONDOWN:
            case WM_NCMBUTTONUP:
            case WM_NCMOUSEHOVER:
            case WM_NCMOUSELEAVE:
            case WM_NCMOUSEMOVE:
            case WM_NCRBUTTONDBLCLK:
            case WM_NCRBUTTONDOWN:
            case WM_NCRBUTTONUP:
            case WM_NCXBUTTONDBLCLK:
            case WM_NCXBUTTONDOWN:
            case WM_NCXBUTTONUP:
            case WM_RBUTTONDBLCLK:
            case WM_RBUTTONDOWN:
            case WM_RBUTTONUP:
            case WM_XBUTTONDBLCLK:
            case WM_XBUTTONDOWN:
            case WM_XBUTTONUP:
                block_input = true;
            }
        }

        if (io.WantCaptureKeyboard)
        {
            switch (msg.message)
            {
            case WM_HOTKEY:
            case WM_KEYDOWN:
            case WM_KEYUP:
            case WM_KILLFOCUS:
            case WM_SETFOCUS:
            case WM_SYSKEYDOWN:
            case WM_SYSKEYUP:
                block_input = true;
            }
        }
        else if (msg.message == WM_KEYDOWN && msg.wParam == toggleKey)
        {
            g_toggleCallback();
        }

        if (!block_input)
            DispatchMessage(&msg);

        ImGui_ImplWin32_WndProcHandler(msg.hwnd, msg.message, msg.wParam, msg.lParam);
    }

    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" call org((bool){}).", (bool)CCEGLView_pollEvents));
    // Call original function
    CCEGLView_pollEvents(self);
}

void(__thiscall* setupWindow)(void* self, float a2, float a3, float a4, float a5);
void __fastcall setupWindow_H(void* self, float a2, float a3, float a4, float a5) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCSIG__"((bool){}, {}, {}, {}, {})", (bool)self, a2, a3, a4, a5));

    // Call original function
    if (ImGuiHook::consoleLogs) 
        ModUtils::log(std::format("call org of __FUNCTION__"
                "((bool){}, {}, {}, {}, {})", 
          (bool)self, a2, a3, a4, a5));
    setupWindow(self, a2, a3, a4, a5);

    if (!g_inited) if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__" reached !g_inited block, retutn before DestroyContext() etc"));
    if (!g_inited) return;

    //ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    
    g_inited = false;
}

void ImGuiHook::setupHooks(std::function<void(void*, void*, void**)> hookFunc) {
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__));
    LPVOID targ;
    targ = GetProcAddress(GetModuleHandleA("libcocos2d.dll"), "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ");
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__": swapBuffers hook at {}", (DWORD)targ));
    hookFunc(
        targ,
        CCEGLView_swapBuffers_H,
        reinterpret_cast<void**>(&CCEGLView_swapBuffers)
    );
    targ = GetProcAddress(GetModuleHandleA("libcocos2d.dll"), "?pollEvents@CCEGLView@cocos2d@@QAEXXZ");
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__": pollEvents hook at {}", (DWORD)targ));
    hookFunc(
        targ,
        CCEGLView_pollEvents_H,
        reinterpret_cast<void**>(&CCEGLView_pollEvents)
    );
    targ = GetProcAddress(GetModuleHandleA("libcocos2d.dll"), "?setupWindow@CCEGLView@cocos2d@@IAEXVCCRect@2@@Z");
    if (ImGuiHook::consoleLogs) ModUtils::log(std::format(__FUNCTION__": setupWindow hook at {}", (DWORD)targ));
    hookFunc(
        targ,
        setupWindow_H,
        reinterpret_cast<void**>(&setupWindow)
    );
}