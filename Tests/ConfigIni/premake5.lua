project "ConfigTomlTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/*.*",
        "../../Neoncube/src/Config/Config.cpp",
        "../../Neoncube/src/Config/Config.hpp",
        "../../Neoncube/src/Config/ConfigToml.cpp",
        "../../Neoncube/src/Config/ConfigToml.hpp"
    }

    includedirs {
        "../../Neoncube/src",
        "../../Neoncube/vendor/tomlplusplus/include"
    }
