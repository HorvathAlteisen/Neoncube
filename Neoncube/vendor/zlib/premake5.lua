project "zlib"
    kind "StaticLib"
    architecture "x86"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "*.c",
        "*.h"
    }

    defines {
        "STRICT",
        "_CRT_SECURE_NO_DEPRECATE",
        "ZLIB_WINAPI"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        defines {
            "WIN32",
            "_WIN32",
            "_WINDOWS"
        }

    filter "configurations:Debug"
        staticruntime "on"
        runtime "Debug"
        defines {"_DEBUG"}
        symbols "On"

    filter "configurations:Release"
        staticruntime "on"
        runtime "Release"
        optimize "On"
        defines {"NDEBUG"}