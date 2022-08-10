project "Browser"
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
    }
    
    filter "system:windows"
        systemversion "latest"
    
        defines {
            "_WINDOWS",
            "WIN32",
            "_WIN32",
        }

    filter "configurations:Debug"
        staticruntime "on"
        runtime "Debug"
        symbols "on"

        defines {"_DEBUG"}

    filter "configurations:Release"
        staticruntime "on"
        runtime "Release"
        optimize "on"

        defines {"NDEBUG"}