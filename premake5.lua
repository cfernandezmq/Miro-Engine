workspace "Miro"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

ouputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Miro"
    location "Miro"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/".. ouputdir .. "/%{prj.name}")
    objdir ("bin-int/".. ouputdir .. "/%{prj.name}")
    
    pchheader "stdafx.h"
    pchsource "Miro/src/stdafx.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs
    {
        "Miro/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MR_PLATFORM_WINDOWS",
            "MR_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. ouputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MR_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
    defines "MR_RELEASE"
    symbols "On"
    
    filter "configurations:Dist"
        defines "MR_DIST"
        symbols "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. ouputdir .. "/%{prj.name}")
    objdir ("bin-int/".. ouputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs
    {
        "Miro/vendor/spdlog/include",
        "Miro/src"
    }

    links
    {
        "Miro"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MR_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "MR_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
    defines "MR_RELEASE"
    symbols "On"
    
    filter "configurations:Dist"
        defines "MR_DIST"
        symbols "On"