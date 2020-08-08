add_library(entities SHARED)

target_link_libraries(entities PUBLIC util)

target_sources(entities PRIVATE Human Tree Food Sprite INTERFACE Entity)
