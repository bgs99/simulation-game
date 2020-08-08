add_library(sdl SHARED)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED)
pkg_search_module(SDL2IMAGE REQUIRED)

# ${SDL2_LIBRARIES} points to -lSDL instead of -lSDL2 for some reason
target_link_libraries(sdl PUBLIC util ${SDL2IMAGE_LIBRARIES})

target_sources(sdl PRIVATE SDL Events Renderer Window Texture detail)
