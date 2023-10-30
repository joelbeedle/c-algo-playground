# Ensure the Criterion package is found
find_package(Criterion REQUIRED)

# Include the Criterion headers
include_directories(${CRITERION_INCLUDE_DIRS})

# Gather your source files
file(GLOB_RECURSE DATA_STRUCTURE_SOURCES ${CMAKE_SOURCE_DIR}/src/data_structures/*.c)
file(GLOB_RECURSE UTIL_SOURCES ${CMAKE_SOURCE_DIR}/src/utils/*.c)

list(APPEND PROJECT_SOURCES ${DATA_STRUCTURE_SOURCES})
list(APPEND PROJECT_SOURCES ${UTIL_SOURCES})

file(GLOB TEST_SOURCES "./*.c")

# Create your test executable
add_executable(runTests ${TEST_SOURCES} ${PROJECT_SOURCES})
target_include_directories(runTests PRIVATE ${CRITERION_INCLUDE_DIRS})
target_link_libraries(runTests PRIVATE ${CRITERION_LIBRARIES})

# Link your test executable against your libraries and Criterion
#target_link_libraries(runTests ${Criterion_LIBRARIES} data_structures utils)

# Register tests
add_test(NAME runTests COMMAND runTests)