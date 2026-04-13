
add_executable(SearchEngine
    main.cpp
    InvertedIndex.cpp InvertedIndex.h
    SearchServer.cpp SearchServer.h
    ConverterJSON.cpp ConverterJSON.h
    json.hpp
)

find_package(Threads REQUIRED)
target_link_libraries(SearchEngine PRIVATE Threads::Threads)
