message("curly-eureka included...\n dir - ${CMAKE_CURRENT_LIST_DIR}")

#curly-eureka
file(GLOB_RECURSE curly_eureka_src 
${CMAKE_CURRENT_LIST_DIR}/*.cpp
${CMAKE_CURRENT_LIST_DIR}/SimpleIni/*
${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/SourceFiles/*
${CMAKE_CURRENT_LIST_DIR}/jute/*
)
set(curly_eureka_incl
${CMAKE_CURRENT_LIST_DIR}
${CMAKE_CURRENT_LIST_DIR}/gd.h
${CMAKE_CURRENT_LIST_DIR}/gd.h/include
${CMAKE_CURRENT_LIST_DIR}/minhook/include
${CMAKE_CURRENT_LIST_DIR}/SimpleIni
${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/Includes
${CMAKE_CURRENT_LIST_DIR}/jute
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cocos-headers cocos-headers-build)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/minhook minhook-build)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/uibuilder uibuilder-build)
include_directories(${curly_eureka_incl})
link_libraries(minhook cocos2d)