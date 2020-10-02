workspace "Miro"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder ( solution directory )
IncludeDir = {}
IncludeDir["GLFW"] = "Miro/vendor/GLFW/include"
IncludeDir["Glad"] = "Miro/vendor/Glad/include"
IncludeDir["ImGui"] = "Miro/vendor/ImGui"
IncludeDir["glm"] = "Miro/vendor/glm"




include "Miro/vendor/GLFW"
include "Miro/vendor/Glad"
include "Miro/vendor/ImGui"



project "Miro"
    location "Miro"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .. "/%{prj.name}")
    
    pchheader "stdafx.h"
    pchsource "Miro/src/stdafx.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs
    {
        "Miro/src",
        "Miro/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"


    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MR_PLATFORM_WINDOWS",
            "MR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MR_DEBUG"
        buildoptions "/MDd"
        symbols "On"
        
    filter "configurations:Release"
        defines "MR_RELEASE"
        buildoptions "/MD"
        symbols "On"
    
    filter "configurations:Dist"
        defines "MR_DIST"
        buildoptions "/MD"
        symbols "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",

    }

    includedirs
    {
        "Miro/vendor/spdlog/include",
        "Miro/src",
        "Miro/vendor",
        "%{IncludeDir.glm}"

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
        buildoptions "/MDd"
        symbols "On"
        
    filter "configurations:Release"
    defines "MR_RELEASE"
    buildoptions "/MD"
    symbols "On"
    
    filter "configurations:Dist"
        defines "MR_DIST"
        buildoptions "/MD"
        symbols "On"