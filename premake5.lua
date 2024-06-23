imgui_params = {
    files = {
        "vendor/imgui/*.cpp",
        "vendor/imgui/*.h",
        "vendor/imgui/backends/imgui_impl_sdlrenderer2.*",
        "vendor/imgui/backends/imgui_impl_sdl2.*",
        "vendor/imgui/misc/cpp/imgui_stdlib.*"
    },
    includes = {
        "vendor/imgui/",
        "vendor/imgui/backends/",
        "vendor/imgui/misc/cpp/"
    }
}

sdl_params = {
    lib_dir = "vendor/sdl2/build/lib",
    include_dir = "vendor/sdl2/build/include/SDL2"
}


workspace "ez-stream"
    configurations { "Debug", "Release" }

project "sdl2"
    kind "Makefile"

    buildcommands {
        "mkdir -p vendor_install",
        "mkdir -p vendor/sdl2/build; cd vendor/sdl2/build; ../configure --prefix=$$(pwd); make -j4; make install"
    }

filter ""

project "ez-stream-tool"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    objdir "obj/%{cfg.buildcfg}/"
    targetdir "build/%{cfg.buildcfg}"
    dependson "sdl2"

files {
    "src/**.cpp",
    imgui_params.files
}

includedirs {
    "include",
    imgui_params.includes,
    sdl_params.include_dir
}

linkoptions "`vendor/sdl2/build/bin/sdl2-config --libs`"

