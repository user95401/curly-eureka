#include "imgui-hook.hpp"

bool inited = false;

std::function<void()> DrawFunc = []() {};
std::function<void()> InitFunc = []() {};
std::function<void(int)> KeyPressHandler = [](int _) {};
#define _VOID_1(v)	std::function<void(v)>
#define _VOID_2(v)	_VOID_1(_VOID_1(v))

HGLRC g_WglContext = 0;
HWND hWnd;

WNDPROC o_WndProc;
LRESULT CALLBACK h_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Initialisation for ImGui
void InitOpenGL2(
    IN  HDC	  hDc,
    OUT bool* init,
    OUT bool* status)
{
    if (WindowFromDC(hDc) == hWnd && *init) return;
    auto tStatus = true;

    hWnd = WindowFromDC(hDc);
    auto wndProc = (WNDPROC)GetWindowLongPtr(hWnd, GWLP_WNDPROC);
    auto wLPTR = SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)h_WndProc);

    if (*init)
    {
        ImGui_ImplWin32_Init(hWnd);
        ImGui_ImplOpenGL2_Init();
        return;
    }

    if (!wLPTR) return;

    o_WndProc = wndProc;
    g_WglContext = wglCreateContext(hDc);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    tStatus &= ImGui_ImplWin32_Init(hWnd);
    tStatus &= ImGui_ImplOpenGL2_Init();

    *init = true;
    return;
}
// Generic ImGui renderer for Win32 backend
void RenderWin32(
    IN  std::function<void()> render)
{
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    render();

    ImGui::EndFrame();
    ImGui::Render();
}
// Generic ImGui renderer for OpenGL2 backend
void RenderOpenGL2(
    IN  HGLRC 	  WglContext,
    IN  HDC		  hDc,
    IN  _VOID_2() render,
    IN  _VOID_1() render_inner,
    OUT bool* status)
{
    auto tStatus = true;

    auto o_WglContext = wglGetCurrentContext();
    tStatus &= wglMakeCurrent(hDc, WglContext);

    ImGui_ImplOpenGL2_NewFrame();
    render(render_inner);
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    tStatus &= wglMakeCurrent(hDc, o_WglContext);

    return;
}

BOOL(__stdcall* wglSwapBuffers)(HDC);
BOOL  __stdcall wglSwapBuffers_H(HDC hDc) {
    InitOpenGL2(hDc, &inited, nullptr);
    RenderOpenGL2(g_WglContext, hDc, RenderWin32, DrawFunc, nullptr);
    return wglSwapBuffers(hDc);
    /*
    //init
    if (!inited) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        InitFunc();
        HWND hWnd = WindowFromDC(hdc);
        oriWndProñ = (WNDPROC)GetWindowLongPtr(hWnd, GWLP_WNDPROC);
        SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)wndProc_H);
        ImGui_ImplWin32_Init(hWnd);
        ImGui_ImplOpenGL2_Init();
        inited = true;
    }
    //NewFrame
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    //Draw
    DrawFunc();
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    //wha
    glFlush();
    return wglSwapBuffers(hdc);
    */
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK h_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) return true;

    if (uMsg == WM_KEYDOWN && !ImGui::GetIO().WantCaptureKeyboard)
    {
        KeyPressHandler(wParam);
    }

    return CallWindowProc(o_WndProc, hWnd, uMsg, wParam, lParam);
}

void(__thiscall* setupWindow)(void* self, float a2, float a3, float a4, float a5);
void __fastcall setupWindow_H(void* self, float a2, float a3, float a4, float a5) 
{
    setupWindow(self, a2, a3, a4, a5);
    /*if (!inited) return;
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    inited = false;*/
}

void ImGuiHook::SetupHooks(std::function<void(void*, void*, void**)> hookFunc)
{
    hookFunc(
        GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers"),
        wglSwapBuffers_H,
        (void**)&wglSwapBuffers
    );
    hookFunc(
        GetProcAddress(GetModuleHandleA("libcocos2d.dll"), "?setupWindow@CCEGLView@cocos2d@@IAEXVCCRect@2@@Z"),
        setupWindow_H,
        reinterpret_cast<void**>(&setupWindow)
    );
}

void ImGuiHook::SetRenderFunction(std::function<void()> func)
{
    DrawFunc = func;
}

void ImGuiHook::SetKeyPressHandler(std::function<void(int)> func)
{
    KeyPressHandler = func;
}

void ImGuiHook::SetInitFunction(std::function<void()> func) {
    InitFunc = func;
}