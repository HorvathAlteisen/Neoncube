project "LibGRF"
    kind "StaticLib"
    language "C"
    platforms "x86"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}sd")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "../zlib"
    }

    files {
        "*.c",
        "*.h"
    }

    defines {
        "_CRT_SECURE_NO_DEPRECATE",
        "GRF_STATIC",
        "SPR_STATIC",
        "STRICT"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        defines {
            "WIN32",
            "_WIN32",
            "_WINDOWS",
            "ZLIB_WINAPI"
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