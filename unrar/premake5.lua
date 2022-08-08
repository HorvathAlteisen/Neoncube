project "Unrar"
    kind "StaticLib"
    language "C++"
    architecture "x32"
    characterset "MBCS"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}sd")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "archive.cpp",
        "arcread.cpp",
        "cmddata.cpp",
        "consio.cpp",
        "crc.cpp",
        "crypt.cpp",
        "dll.cpp",
        "encname.cpp",
        "errhnd.cpp",
        "extinfo.cpp",
        "extract.cpp",
        "filcreat.cpp",
        "file.cpp",
        "filefn.cpp",
        "filestr.cpp",
        "find.cpp",
        "getbits.cpp",
        "global.cpp",
        "int64.cpp",
        "isnt.cpp",
        "list.cpp",
        "match.cpp",
        "options.cpp",
        "pathfn.cpp",
        "rarvm.cpp",
        "rawread.cpp",
        "rdwrfn.cpp",
        "recvol.cpp",
        "resource.cpp",
        "rijndael.cpp",
        "rs.cpp",
        "savepos.cpp",
        "scantree.cpp",
        "sha1.cpp",
        "smallfn.cpp",
        "strfn.cpp",
        "strlist.cpp",
        "system.cpp",
        "timefn.cpp",
        "ulinks.cpp",
        "unicode.cpp",
        "unpack.cpp",
        "volume.cpp",
        "archive.hpp",
        "array.hpp",
        "cmddata.hpp",
        "coder.hpp",
        "compress.hpp",
        "consio.hpp",
        "crc.hpp",
        "crypt.hpp",
        "dll.hpp",
        "encname.hpp",
        "errhnd.hpp",
        "extinfo.hpp",
        "extract.hpp",
        "filcreat.hpp",
        "file.hpp",
        "filefn.hpp",
        "filestr.hpp",
        "find.hpp",
        "getbits.hpp",
        "global.hpp",
        "headers.hpp",
        "int64.hpp",
        "isnt.hpp",
        "list.hpp",
        "loclang.hpp",
        "log.hpp",
        "match.hpp",
        "model.hpp",
        "options.hpp",
        "os.hpp",
        "pathfn.hpp",
        "rar.hpp",
        "rardefs.hpp",
        "rarfn.hpp",
        "rarlang.hpp",
        "raros.hpp",
        "rartypes.hpp",
        "rarvm.hpp",
        "rawread.hpp",
        "rdwrfn.hpp",
        "recvol.hpp",
        "resource.hpp",
        "rijndael.hpp",
        "rs.hpp",
        "savepos.hpp",
        "scantree.hpp",
        "sha1.hpp",
        "smallfn.hpp",
        "strfn.hpp",
        "strlist.hpp",
        "suballoc.hpp",
        "system.hpp",
        "timefn.hpp",
        "ulinks.hpp",
        "unicode.hpp",
        "unpack.hpp",
        "version.hpp",
        "volume.hpp"
    }

    defines {
        "_CRT_SECURE_NO_DEPRECATE",
        "RARDLL",
        "SILENT",
        "STRICT",
        "_XKEYCHECK_H"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        defines {
            "WIN32",
            "_WIN32",
            "_WINDOWS"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        functionlevellinking "on"
        optimize "off"

        defines {
            "_DEBUG"
        }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"