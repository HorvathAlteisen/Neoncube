workspace "Hermes Tests"
    configurations {"Debug", "Release"}
    architecture "x86"
    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    flags
	{
		"MultiProcessorCompile"
	}

include "ConfigIni"
include "WindowsWindow"