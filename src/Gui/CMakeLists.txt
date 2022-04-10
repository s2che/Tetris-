#Сделаем подпроект, дабы была переменная + обозначение в IDE
project(Tetramino)

#Создаём списки файлов, дабы не переписывать всё вручную
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/inclde/*.hpp" )
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

#Из исходников делаем исполняемый файл
add_executable(${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

#Сообщаем компилятору о том, что все заголовки хранятся в этой папке
target_include_directories(${PROJECT_NAME}
        PUBLIC
          ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#К исполняемому линкуем библиотеки
target_link_libraries(${PROJECT_NAME}
    PUBLIC
     Libs::ControlComponent
)


