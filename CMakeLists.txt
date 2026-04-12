cmake_minimum_required(VERSION 3.19)
project(mainProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Test)
find_package(Threads REQUIRED)

qt_standard_project_setup()

qt_add_executable(mainProject
    main.cpp
    InvertedIndex.h
    SearchServer.h
    ConverterJSON.h
    InvertedIndex.cpp
    SearchServer.cpp
    ConverterJSON.cpp
    json.hpp
)

target_link_libraries(mainProject
    PRIVATE
        Qt6::Core
        Threads::Threads
)

install(TARGETS mainProject
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

enable_testing()

qt_add_executable(SearchEngineTest
    test.cpp
    InvertedIndex.h InvertedIndex.cpp
    SearchServer.h SearchServer.cpp
)
target_link_libraries(SearchEngineTest
    PRIVATE
        Qt6::Core
        Qt6::Test
        Threads::Threads
)

add_test(NAME SearchEngineTest COMMAND SearchEngineTest)