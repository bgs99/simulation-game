add_library(sdl SHARED)

find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)

target_link_libraries(sdl SDL2::SDL2)

target_sources(sdl PRIVATE SDL Events Renderer Window detail)
