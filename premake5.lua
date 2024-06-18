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


workspace "ez-stream"
    configurations { "Debug", "Release" }

project "ez-stream-tool"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    objdir "obj/%{cfg.buildcfg}/"
    targetdir "build/%{cfg.buildcfg}"

files {
    "src/**.cpp",
    imgui_params.files
}

includedirs {
    "include",
    imgui_params.includes
}

links {
    "SDL2"
}


filter "system:linux"
    includedirs { "/usr/include/SDL2" }

