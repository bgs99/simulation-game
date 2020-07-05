add_library(engine)

target_link_libraries(engine PRIVATE sdl)

target_sources(engine PRIVATE Engine.cpp Manager.cpp)
