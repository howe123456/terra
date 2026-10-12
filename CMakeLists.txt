cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(PRODUCTION_BUILD OFF CACHE BOOL "Make this a production build" FORCE)
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
    add_compile_options(/arch:AVX2)
else()
    add_link_options(-static-libstdc++ -static-libgcc)

    add_compile_options(-mavx2 -mfma)
endif()

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Raylib as static libraries" FORCE)
project(game)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# raylib 5.0 (and its bundled glfw) declare cmake_minimum_required below 3.5,
# which CMake 4.x rejects. Raise the floor for these vendored subprojects.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

add_subdirectory(thirdparty/raylib)
add_executable("${CMAKE_PROJECT_NAME}")
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE raylib)

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

if(PRODUCTION_BUILD)
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources")

    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1)

else()
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=0)

endif()

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${SOURCES})
target_sources("${CMAKE_PROJECT_NAME}" PRIVATE "${SOURCES}")
if(MSVC)
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)

    if(PRODUCTION_BUILD)
        set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
        
    endif()

elseif(MINGW)
    if(PRODUCTION_BUILD)
        target_link_options("${CMAKE_PrOJeCT_NAME}" PRIVATE
            -mwindows
        )
    endif()

elseif(APPLE OR UNIX)
    if(PRODUCTION_BUILD)
            target_link_options("${CMAKE_PROJECT_NAME}" PRIVAETE -s)
    endif()    
    
endif()

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
