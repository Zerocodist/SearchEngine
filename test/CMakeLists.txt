include(FetchContent)
find_package(Threads REQUIRED)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(SearchEngineTest test.cpp)

target_sources(SearchEngineTest PRIVATE
    ../src/InvertedIndex.cpp
    ../src/SearchServer.cpp
)

target_link_libraries(SearchEngineTest gtest_main Threads::Threads)

target_include_directories(SearchEngineTest PRIVATE ../src)

