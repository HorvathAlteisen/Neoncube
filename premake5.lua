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
    include "Browser"
    include "Neoncube/vendor/libgrf"
    include "Neoncube/vendor/unrar"
    include "Neoncube/vendor/zlib"
group ""

group "Tests"
    include "Tests"
group ""

include "Neoncube"