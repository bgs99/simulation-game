add_subdirectory(sdl)
add_subdirectory(engine)

add_executable(main)

target_link_libraries(main engine)

target_sources(main PRIVATE main)