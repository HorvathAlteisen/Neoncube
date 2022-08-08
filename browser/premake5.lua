project "Browser"
    kind "StaticLib"
    language "C"
    platforms "x64"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}sd")
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
        runtime "Debug"
        symbols "on"

        defines {
            "_DEBUG"
        }

    filter "configurations:Release"
        runtime "Release"
        optimize "on"