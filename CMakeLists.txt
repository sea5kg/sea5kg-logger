cmake_minimum_required(VERSION 3.5)

project(sea5kg-logger)

# include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${sea5kg-logger_SOURCE_DIR})

# Sources

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")
list (APPEND WSJCPP_INCLUDE_DIRS "src/sea5kg/logger")

list (APPEND WSJCPP_SOURCES "src/sea5kg/logger/sea5kg_logger.cpp")

list (APPEND WSJCPP_SOURCES "src/main.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("sea5kg-logger" ${WSJCPP_SOURCES})

target_link_libraries("sea5kg-logger" -lpthread ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        "sea5kg-logger"
    RUNTIME DESTINATION
        /usr/bin
)


