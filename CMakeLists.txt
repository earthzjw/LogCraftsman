cmake_minimum_required(VERSION 3.0)

project(MyLog)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Add source files to the project
set(SOURCES
    FileUtil.cpp
    LogFile.cpp
    Logger.cpp
    Logging.cpp
    test.cpp
)

# Add header files to the project
set(HEADERS
    FileUtil.h
    LogFile.h
    Logger.h
    LogStream.h
    Logging.h
    Timestamp.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

