message("curly-eureka included...\nCURLY_EUREKA_DIR - ${CMAKE_CURRENT_LIST_DIR}")
set(CURLY_EUREKA_DIR ${CMAKE_CURRENT_LIST_DIR})

#configure gdh game ver
if(DEFINED GAME_VERSION)
    message("NEW GAME_VERSION FOUND - ${GAME_VERSION}")
else()
    set(GAME_VERSION "2.1")
    message("GAME_VERSION ISN'T DEFINED, GAME_VERSION - ${GAME_VERSION}")
endif()

file(GLOB_RECURSE CURLY_EUREKA_SRC 
"${CURLY_EUREKA_DIR}/ceMainSrc/*.cpp"
"${CURLY_EUREKA_DIR}/ceGameVersionDependentSrc_${GAME_VERSION}/*.cpp"
"${CURLY_EUREKA_DIR}/SimpleIni/*.c"
"${CURLY_EUREKA_DIR}/DiscordRPCSDK/SourceFiles/*.cpp"
"${CURLY_EUREKA_DIR}/jute/*.cpp"
"${CURLY_EUREKA_DIR}/kuba--zip/*.c"
)
message("CURLY_EUREKA_SRC: ${CURLY_EUREKA_SRC}")
    
set(CURLY_EUREKA_INCL
"${CMAKE_CURRENT_LIST_DIR}"
"${CMAKE_CURRENT_LIST_DIR}/ceMainSrc"
"${CMAKE_CURRENT_LIST_DIR}/ceGameVersionDependentSrc_${GAME_VERSION}"
"${CMAKE_CURRENT_LIST_DIR}/gd.h_${GAME_VERSION}"
"${CMAKE_CURRENT_LIST_DIR}/gd.h_${GAME_VERSION}/include"
"${CMAKE_CURRENT_LIST_DIR}/minhook-multihook/include"
"${CMAKE_CURRENT_LIST_DIR}/SimpleIni"
"${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/Includes"
"${CMAKE_CURRENT_LIST_DIR}/jute"
"${CMAKE_CURRENT_LIST_DIR}/kuba--zip"
"${CMAKE_CURRENT_LIST_DIR}/imgui-hook"
"${CMAKE_CURRENT_LIST_DIR}/imgui-hook/imgui"
)
message("CURLY_EUREKA_INCL: ${CURLY_EUREKA_INCL}")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/cocos-headers_${GAME_VERSION}" cocos-headers-build)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/minhook-multihook" minhook-build)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/uibuilder" uibuilder-build)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/imgui-hook" imgui-hook-build)

include_directories(${CURLY_EUREKA_INCL})

link_libraries(
cocos2d
imgui-hook
minhook
opengl32
)