add_library(engine SHARED)

target_link_libraries(engine PUBLIC sdl)

target_sources(engine PRIVATE Entity Engine Manager TextureManager Vector2d Sprite)
