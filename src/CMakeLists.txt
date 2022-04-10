set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML REQUIRED  # SFML - lib, REQUIRED - если не нашло, то краш; COMPONENTS - части либы
        COMPONENTS
    graphics
)



file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/inclde/*.hpp" )
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        sfml-graphics
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
)

