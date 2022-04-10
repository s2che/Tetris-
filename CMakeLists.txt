#Установка минимальной версии CMake
cmake_minimum_required(VERSION 3.0.0)

#Установка ИмениПроекта\Версии\Языка
project(Tetramino VERSION 0.1 LANGUAGES CXX)

#Куда компилятся:   BINARY_DIR - корневая папка build
#                   SOURCE_DIR - корневая папка src
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin") #Исполняемый
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") #Либы
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") #Архивы

#CmakeModules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

#Установка данной папки как CURRENT_SOURCE && BINARY_DIR
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#Проверь эту папку на наличие CMAKE
add_subdirectory(src)


