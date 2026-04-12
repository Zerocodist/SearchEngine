#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "SearchServer.h"

class ConverterJSON {
public:
    ConverterJSON() = default;

    std::vector<std::string> GetTextDocuments();
    int GetResponseLimit();
    std::vector<std::string> GetRequests();

    void pushAnswers(std::vector<std::vector<RelativeIndex>> answers);
};
