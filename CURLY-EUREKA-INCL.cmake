message("curly-eureka included...\ndir - ${CMAKE_CURRENT_LIST_DIR}")

#configure gdh game ver
if(DEFINED ${GDH_GAME_VERSION})
    message("NEW GDH_GAME_VERSION FOUND - ${GDH_GAME_VERSION}")
else()
    set(GDH_GAME_VERSION "2.113")
endif()

file(GLOB_RECURSE CURLY_EUREKA_SRC 
${CMAKE_CURRENT_LIST_DIR}/*.cpp
${CMAKE_CURRENT_LIST_DIR}/SimpleIni/*
${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/SourceFiles/*
${CMAKE_CURRENT_LIST_DIR}/jute/*
"${CMAKE_CURRENT_LIST_DIR}/kuba--zip/*"
)

set(CURLY_EUREKA_INCL
${CMAKE_CURRENT_LIST_DIR}
${CMAKE_CURRENT_LIST_DIR}/gd.h_${GDH_GAME_VERSION}
${CMAKE_CURRENT_LIST_DIR}/gd.h_${GDH_GAME_VERSION}/include
${CMAKE_CURRENT_LIST_DIR}/minhook/include
${CMAKE_CURRENT_LIST_DIR}/SimpleIni
${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/Includes
${CMAKE_CURRENT_LIST_DIR}/jute
"${CMAKE_CURRENT_LIST_DIR}/kuba--zip"
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cocos-headers cocos-headers-build)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/minhook minhook-build)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/uibuilder uibuilder-build)
include_directories(${CURLY_EUREKA_INCL})
link_libraries(minhook cocos2d)