project "LibGRF"
    kind "StaticLib"
    architecture "x86"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
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

        defines {
            "WIN32",
            "_WIN32",
            "_WINDOWS",
            "ZLIB_WINAPI"
        }
    
    filter "configurations:Debug"
        staticruntime "on"
        runtime "Debug"
        symbols "on"
    
        defines {
            "_DEBUG"
        }
    
    filter "configurations:Release"
        staticruntime "on"
        runtime "Release"
        optimize "on"
        
        defines {"NDEBUG"}