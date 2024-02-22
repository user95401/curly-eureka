
#configure incl
if(DEFINED IMGUI_HOOK)
    message("FOUND IMGUI_HOOK DEFINTION, WILL INCLUDED")
else()
    set(IMGUI_HOOK_INCL 
        "${CURLY_EUREKA_DIR}/ceImGuiHook"
        "${CURLY_EUREKA_DIR}/ceImGuiHook/imgui"
    )
    set(IMGUI_HOOK_SRC 
        "${CURLY_EUREKA_DIR}/ceImGuiHook/*.cpp"
        "${CURLY_EUREKA_DIR}/ceImGuiHook/imgui/*.cpp"
        "${CURLY_EUREKA_DIR}/ceImGuiHook/imgui/backends/*.cpp"
        "${CURLY_EUREKA_DIR}/ceImGuiHook/imgui/misc/cpp/*.cpp"
        "${CURLY_EUREKA_DIR}/ceImGuiHook/imgui/misc/freetype/*.cpp"
    )
    message("IMGUI_HOOK ISN'T DEFINED, WILL NOT INCLUDED SO")
endif()