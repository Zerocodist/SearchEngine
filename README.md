# 🔍 Search Engine (Final Project)

Console-based search engine that indexes local text files and provides relevant search results based on user queries.

## 🚀 Key Features
*   **Fast Indexing**: Inverted index logic for instant lookups.
*   **Multithreading**: Uses `std::thread` and `std::mutex` for safe, parallel document processing.
*   **JSON Support**: Configuration and queries are handled via `nlohmann/json`.
*   **Relevance Ranking**: Results are sorted using absolute and relative relevance formulas.
*   **Unit Testing**: Covered with **Qt Test** framework.

## 🛠 Tech Stack
*   **Language**: C++17
*   **Framework**: Qt 6 (Core, Test)
*   **Build System**: CMake
*   **Format**: JSON

## 🧪 How to run tests
1. Open the project in Qt Creator.
2. Select the `SearchEngineTest` target.
3. Run the application to see the "Totals: 4 passed" report.

