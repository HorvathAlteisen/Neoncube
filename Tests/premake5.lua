project "Tests"
    kind "ConsoleApp"
    language "C++"

    characterset "MBCS"

    targetdir ("%{wks.location}/Tests/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Tests/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "src",
        "vendor",
        "../Browser/src",
        "%{wks.location}/Resources"
    }

    files {
        "src/*.h", 
        "src/*.cpp",
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