workspace "CloudQ"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CloudQ"
	location "CloudQ"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.26100.0"
		
		defines
		{
			"CQ_PLATFORM_WINDOWS",
			"CQ_BUILD_DLL"
		}
		

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CQ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CQ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CloudQ/vendor/spdlog/include",
		"CloudQ/src"
	}

	links
	{
		"CloudQ"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.26100.0"
		defines
		{
			"CQ_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "CQ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CQ_DIST"
		optimize "On"