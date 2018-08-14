cmake_minimum_required(VERSION 3.5.1)
project(detect)

find_package(OpenCV REQUIRED)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -fopenmp -std=c++11")
set(CMAKE_SYSTEM_VERSION 1)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)

set(SRC jni/mtcnn.cpp jni/network.cpp jni/pBox.cpp jni/pikaqiu.cpp)

include_directories(${OpenCV_INCLUDE_DIRS} /usr/lib/jvm/java-8-oracle/include
                        /usr/lib/jvm/java-8-oracle/include/linux)
link_directories(/usr/lib/jni)

#add_library(detect SHARED ${SRC})
add_executable (detect ${SRC})

target_link_libraries(detect ${OpenCV_LIBS} openblas)
