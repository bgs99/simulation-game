add_library(engine SHARED)

target_link_libraries(engine PUBLIC sdl)

target_sources(engine PRIVATE Engine Manager)
