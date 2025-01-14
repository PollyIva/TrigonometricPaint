cmake_minimum_required(VERSION 3.5.0)
project(OOP_1 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
# Указываем путь к OpenCV
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
set(OpenCV_DIR "С:/opt/opencv/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/color
    ${PROJECT_SOURCE_DIR}/include/matrix
    ${PROJECT_SOURCE_DIR}/include/shape
)


find_package(OpenCV REQUIRED)
# Включаем заголовочные файлы OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB lib_src
    "src/*/*.cpp"
    # "src/*.cpp"
)

add_library(${PROJECT_NAME} STATIC
    ${lib_src}
)

file(GLOB src_files
    "*.cpp"
)

add_executable(runner ${src_files})

target_link_libraries(runner
    ${PROJECT_NAME}
)

# Линкуем исполнимый файл с библиотеками OpenCV и созданной библиотекой
target_link_libraries(runner ${PROJECT_NAME} ${OpenCV_LIBS})

# Находим все подкаталоги в include/
file(GLOB_RECURSE INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include/*")

