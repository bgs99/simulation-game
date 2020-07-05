add_subdirectory(sdl)
add_subdirectory(engine)

add_executable(main)

target_link_libraries(main sdl engine)

target_sources(main PRIVATE main.cpp)