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

-- sdl_params = {
--     lib_dir = "vendor/sdl2/build/lib",
--     include_dir = "vendor/sdl2/build/include/SDL2"
-- }


workspace "ez-stream"
    configurations { "Debug", "Release" }

-- project "sdl2"
--     kind "Makefile"

--     buildcommands {
--         "mkdir -p vendor/sdl2/build; cd vendor/sdl2/build; ../configure --prefix=\"$$(pwd)\"; make -j4; make install"
--     }

--     filter "system:windows"
--         buildcommands {
--             "cp vendor/sdl2/build/bin/SDL2.dll build/%{cfg.buildcfg}/SDL2.dll"
--         }

-- filter ""

project "ez-stream-tool"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    objdir "obj/%{cfg.buildcfg}/"
    targetdir "build/%{cfg.buildcfg}"
    -- dependson "sdl2"

files {
    "src/**.cpp",
    imgui_params.files
}

includedirs {
    "include",
    imgui_params.includes,
    -- sdl_params.include_dir
}

filter "system:windows"
    linkoptions { "-static-libgcc", "-static-libstdc++" }

filter ""

buildoptions { "`sdl2-config --cflags`", "`pkg-config SDL2_image --cflags`" }
linkoptions  { "`sdl2-config --libs`",  "`pkg-config SDL2_image --libs`"}

filter "configurations:Debug"
    symbols "On"

filter "configurations:Release"
    defines { "EZSTREAM_RELEASE" }

filter "system:windows"
    postbuildcommands {
        "cp $${MINGW_PREFIX}/bin/SDL2.dll build/%{cfg.buildcfg}/SDL2.dll",
        "cp $${MINGW_PREFIX}/bin/SDL2_image.dll build/%{cfg.buildcfg}/SDL2_image.dll"
    }

