{
    files = {
        "build/.objs/csg2d/macosx/arm64/release/src/csg2d/shape.cpp.o",
        "build/.objs/csg2d/macosx/arm64/release/src/csg2d/rectangle.cpp.o",
        "build/.objs/csg2d/macosx/arm64/release/src/csg2d/circle.cpp.o",
        "build/.objs/csg2d/macosx/arm64/release/src/csg2d/complex_shape.cpp.o",
        "build/.objs/csg2d/macosx/arm64/release/src/csg2d/functions.cpp.o",
        "build/.objs/csg2d/macosx/arm64/release/src/csg2d/main.cpp.o"
    },
    values = {
        "/usr/bin/clang++",
        {
            "-L/Users/mkepka/.xmake/packages/s/sfml/2.6.0/ab598ffd5a37402ebafd12d5130b2a72/lib",
            "-L/opt/homebrew/opt/freetype/lib",
            "-L/opt/homebrew/Cellar/flac/1.4.3/lib",
            "-L/opt/homebrew/Cellar/libvorbis/1.3.7/lib",
            "-L/opt/homebrew/Cellar/libogg/1.3.5/lib",
            "-L/Users/mkepka/.xmake/packages/o/openal-soft/1.23.1/1db38dd509e845668f16768dd4f0c098/lib",
            "-Wl,-x",
            "-Wl,-dead_strip",
            "-lpthread",
            "-lsfml-graphics",
            "-lsfml-window",
            "-lsfml-audio",
            "-lsfml-network",
            "-lsfml-system",
            "-lfreetype",
            "-lz",
            "-lFLAC",
            "-lvorbisfile",
            "-lvorbisenc",
            "-lvorbis",
            "-logg",
            "-lopenal",
            "-framework",
            "Cocoa",
            "-framework",
            "CoreAudio",
            "-framework",
            "CoreFoundation",
            "-framework",
            "AudioToolbox"
        }
    }
}