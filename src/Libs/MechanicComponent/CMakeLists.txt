#Инициализируем переменную, чтоб удобней было
set(Component "MechanicComponent")

#Создаём списки файлов, дабы не переписывать всё вручную
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

#Создаём из исходников библиотеку
add_library(${Component}
    ${HEADERS}
    ${SOURCES}
)

#Сообщаем компилятору о том, что все заголовки хранятся в этой папке
target_include_directories(${Component}
        PUBLIC
          ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML REQUIRED  # SFML - lib, REQUIRED - если не нашло, то краш; COMPONENTS - части либы
        COMPONENTS
    graphics)


target_link_libraries(${Component}
    PUBLIC
        Libs::GeometryComponent
        sfml-graphics
   )

#Создание псевдонима для библиотеки
add_library(${PROJECT_NAME}::${Component}
        ALIAS ${Component}
)
