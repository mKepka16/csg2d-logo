{
    files = {
        "src/csg2d/functions.cpp"
    },
    values = {
        "/usr/bin/clang",
        {
            "-Qunused-arguments",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++2b",
            "-Isrc",
            "-DMACOS",
            "-DAL_LIBTYPE_STATIC",
            "-framework",
            "Cocoa",
            "-framework",
            "CoreAudio",
            "-framework",
            "CoreFoundation",
            "-framework",
            "AudioToolbox",
            "-isystem",
            "/Users/mkepka/.xmake/packages/s/sfml/2.6.0/ab598ffd5a37402ebafd12d5130b2a72/include",
            "-isystem",
            "/opt/homebrew/opt/freetype/include/freetype2",
            "-isystem",
            "/opt/homebrew/opt/libpng/include/libpng16",
            "-isystem",
            "/opt/homebrew/Cellar/flac/1.4.3/include",
            "-isystem",
            "/opt/homebrew/Cellar/libogg/1.3.5/include",
            "-isystem",
            "/opt/homebrew/Cellar/libvorbis/1.3.7/include",
            "-isystem",
            "/Users/mkepka/.xmake/packages/o/openal-soft/1.23.1/1db38dd509e845668f16768dd4f0c098/include",
            "-Wall",
            "-DNDEBUG"
        }
    },
    depfiles_gcc = "build/.objs/csg2d/macosx/arm64/release/src/csg2d/__cpp_functions.cpp.cpp:   src/csg2d/functions.cpp src/csg2d/functions.h src/csg2d/shape.h   src/csg2d/libincludes.h src/csg2d/circle.h src/csg2d/rectangle.h   src/csg2d/operation.h src/csg2d/complex_shape.h\
"
}