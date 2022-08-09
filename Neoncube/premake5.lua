workspace "Neoncube"
    configurations {"Debug", "Release"}
    architecture "x86"
    startproject "Neoncube"

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- include Dirs
    IncludeDir = {}
    IncludeDir["browser"] = "%{wks.location}/browser"
    IncludeDir["libgrf"] = "%{wks.location}/libgrf"
    IncludeDir["unrar"] = "%{wks.location}/unrar"
    IncludeDir["zlib"] = "%{wks.location}/zlib"

    flags
	{
		"MultiProcessorCompile"
	}

group "Dependencies"
    include "browser"
    include "libgrf"
    include "unrar"
    include "zlib"
group ""

project "Neoncube"
    kind "WindowedApp"
    language "C++"

    characterset "MBCS"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "%{wks.location}"
    }

    links {
        "comctl32.lib",
        "wininet.lib",
        "shlwapi.lib",
        "zlib",
        "LibGRF",
        "Browser",
        "UnRAR"
	}

    files {
        "*.h", 
        "*.cpp"
    }

    defines {
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS",
        "STRICT",
        "ZLIB_WINAPI",
        "GRF_STATIC"
    }

    filter "system:Windows"
        defines {
            "WIN32",
            "_WIN32",
            "_WINDOWS"
        }        

    filter "configurations:Debug"
        staticruntime "on"
        runtime "Debug"
        symbols "On"

        defines {"_DEBUG"}

    filter "configurations:Release"
        staticruntime "on"
        runtime "Release"
        optimize "On"

        defines {"NDEBUG"}