#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <functional>
#include "imgui.h"
#include "backends/imgui_impl_opengl2.h"
#include "backends/imgui_impl_win32.h"

typedef BOOL(WINAPI* swapBuffersType)(HDC hdc);

namespace ImGuiHook {
    void SetupHooks(std::function<void(void*, void*, void**)> hookFunc);
    void SetInitFunction(std::function<void()> func);
    void SetRenderFunction(std::function<void()> func);
    void SetKeyPressHandler(std::function<void(int)> func);
}