set(Component "GeometryComponent")

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

#Создание псевдонима для библиотеки
add_library(${PROJECT_NAME}::${Component}
        ALIAS ${Component}
)
