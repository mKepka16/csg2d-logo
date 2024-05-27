-- PPG2
add_rules("mode.release", "mode.debug")

set_languages("cxxlatest")

if is_plat("linux") then
	set_toolchains("gcc")
	add_cxflags("-mavx2")
	add_cxflags("-Wall")
	add_defines("LINUX")
	add_links("pthread")
elseif is_plat("windows") then
	set_toolchains("msvc")
	add_cxflags("/std:c++latest")
	add_cxflags("/Wall")
	add_ldflags("/SUBSYSTEM:CONSOLE")
elseif is_plat("macosx") then
		set_toolchains("clang")
    add_cxflags("-Wall")
    add_defines("MACOS")
    add_frameworks("Cocoa", {force = true}) -- Use add_frameworks instead of add_ldflags
    add_links("pthread")

    -- ... (SFML include and link settings)
    add_links("sfml-graphics", "sfml-window", "sfml-system", "sfml-audio", "sfml-network") 
end

if is_mode("debug") then
	set_symbols("debug")
	set_optimize("none")
	add_defines("_DEBUG")
else
	set_optimize("fastest")
	add_defines("NDEBUG")
end

includes("src")
