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

    print(IncludeDir["browser"])
    print(IncludeDir["libgrf"])
    print(IncludeDir["unrar"])
    print(IncludeDir["zlib"])

    print("%{wks.location}")

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
    kind "ConsoleApp"
    language "C++"

    characterset "MBCS"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    dependson {
        "Browser",
        "zlib",
        "LibGRF",
        "Unrar"
    }

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
        "Unrar"
	}

    files {
        "*.h", 
        "*.cpp"
    }

    defines {
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"	
    }

    filter "configurations:Debug"
        defines {"NDEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"