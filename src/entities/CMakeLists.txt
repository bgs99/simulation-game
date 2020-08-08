add_library(entities)

target_link_libraries(entities PUBLIC engine util)

target_sources(entities PRIVATE Human Tree)
