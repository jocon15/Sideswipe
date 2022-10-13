workspace "Sideswipe"
	architecture "x64"

	configurations{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}"

project "Bonfire"
	location "dependencies/Bonfire/Bonfire"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	files{
		"dependencies/Bonfire/Bonfire/include/**.hpp",
		"dependencies/Bonfire/Bonfire/src/**.cpp"
	}

	-- if system is windows
	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines{
			"BONFIRE_EXPORTS",
			"_WINDOWS",
			"_USRDLL",
			"GE_PLATFORM_WINDOWS",
			"COMPILING_DLL"
		}

		-- you could do postbuilds here but we are not using them

	-- note that MDd and MD need to match the executables build options
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		buildoptions "/MDd"

	filter "configurations:Release"
		runtime  "Release"
		optimize "On"
		buildoptions "/MD"

project "Sideswipe"
	location "Sideswipe"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	files{
		"%{prj.name}/include/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"dependencies/Bonfire/Bonfire/include"
	}

	links{
		"Bonfire"
	}

	libdirs{
		"bin/" .. outputdir
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines{
			"BONFIRE_EXPORTS",
			"_WINDOWS",
			"_USRDLL",
			"GE_PLATFORM_WINDOWS",
			"COMPILING_DLL"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		buildoptions "/MDd"

	filter "configurations:Release"
		runtime  "Release"
		optimize "On"
		buildoptions "/MD"

project "Example"
	location "Example"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	files{
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.cpp"
	}

	includedirs{
		"dependencies/Bonfire/Bonfire/include",
		"Sideswipe/include"
	}

	links{
		"Sideswipe"
	}

	libdirs{
		"bin/" .. outputdir
	}

	-- if system is windows
	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines{
			"_CONSOLE",
			"GE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		buildoptions "/MDd"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		buildoptions "/MD"