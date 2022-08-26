project "WindowsWindowTest"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/%{prj.name}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}//%{prj.name}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/*.*",
        "../../Neoncube/src/Platform/Windows/*.*",
        "../../Neoncube/src/Hermes/Core/Window.*",
        "../../Neoncube/src/Hermes/Core/Button.*",
        --"../../Neoncube/src/Hermes/Core/Application.*",
        "../../Neoncube/src/Config/*.*"
    }

    includedirs {
        "../../Neoncube/src",
        "../../Neoncube/src/Hermes",
        "../../Neoncube/vendor/tomlplusplus/include"
    }

    links {
        "comctl32.lib"
    }