message("curly-eureka included...\nCURLY_EUREKA_DIR - ${CMAKE_CURRENT_LIST_DIR}")
set(CURLY_EUREKA_DIR ${CMAKE_CURRENT_LIST_DIR})

#configure gdh game ver
if(DEFINED GAME_VERSION)
    message("NEW GAME_VERSION FOUND - ${GAME_VERSION}")
else()
    set(GAME_VERSION "2.113")
    message("GAME_VERSION - ${GAME_VERSION}")
endif()

file(GLOB_RECURSE CURLY_EUREKA_SRC 
${CMAKE_CURRENT_LIST_DIR}/ceMainSrc/*.cpp
${CMAKE_CURRENT_LIST_DIR}/ceGameVersionRelatedSrc_${GAME_VERSION}/*.cpp
${CMAKE_CURRENT_LIST_DIR}/SimpleIni/*.c
${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/SourceFiles/*.cpp
${CMAKE_CURRENT_LIST_DIR}/jute/*.c
"${CMAKE_CURRENT_LIST_DIR}/kuba--zip/*.c"
)
message("CURLY_EUREKA_SRC: ${CURLY_EUREKA_SRC}")
    
set(CURLY_EUREKA_INCL
${CMAKE_CURRENT_LIST_DIR}
${CMAKE_CURRENT_LIST_DIR}/ceMainSrc
${CMAKE_CURRENT_LIST_DIR}/ceGameVersionRelatedSrc_${GAME_VERSION}
${CMAKE_CURRENT_LIST_DIR}/gd.h_${GAME_VERSION}
${CMAKE_CURRENT_LIST_DIR}/gd.h_${GAME_VERSION}/include
${CMAKE_CURRENT_LIST_DIR}/minhook/include
${CMAKE_CURRENT_LIST_DIR}/SimpleIni
${CMAKE_CURRENT_LIST_DIR}/DiscordRPCSDK/Includes
${CMAKE_CURRENT_LIST_DIR}/jute
"${CMAKE_CURRENT_LIST_DIR}/kuba--zip"
)
message("CURLY_EUREKA_INCL: ${CURLY_EUREKA_INCL}")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cocos-headers cocos-headers-build)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/minhook minhook-build)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/uibuilder uibuilder-build)

include_directories(${CURLY_EUREKA_INCL})

link_libraries(minhook cocos2d)