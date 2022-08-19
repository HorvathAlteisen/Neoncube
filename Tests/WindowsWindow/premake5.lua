project "WindowsWindowTest"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/%{prj.name}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}//%{prj.name}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/*.*",
        "../../Neoncube/src/Platform/Windows/WindowsWindow.*",
        "../../Neoncube/src/Hermes/Core/Window.*",
        "../../Neoncube/src/Hermes/Core/Application.*"
    }

    includedirs {
        "../../Neoncube/src",
        "../../Neoncube/src/Hermes"
    }

    links {
        "comctl32.lib"
    }