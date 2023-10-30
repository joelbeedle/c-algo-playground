# src/CMakeLists.txt

# Create a "data_structures" library
file(GLOB_RECURSE DATA_STRUCTURES_SOURCES "data_structures/*.c")
add_library(data_structures STATIC ${DATA_STRUCTURES_SOURCES})

# Create an "algorithms" library
#file(GLOB_RECURSE ALGORITHMS_SOURCES "algorithms/*.c")
#add_library(algorithms STATIC ${ALGORITHMS_SOURCES})

# Create a 'utils' library
file(GLOB_RECURSE UTILS_SOURCES "utils/*.c")
add_library(utils STATIC ${UTILS_SOURCES})

add_executable(main main.c)
target_link_libraries(main PRIVATE data_structures)
target_link_libraries(main PRIVATE utils)