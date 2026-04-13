#include "ConverterJSON.h"

using json  = nlohmann::json;

std::vector<std::string> ConverterJSON::GetTextDocuments() {
    std::vector<std::string> contents;
    std::ifstream file("config.json");
    if (!file.is_open()) return contents;

    json j;
    file >> j;
    for (const auto& path : j["files"]) {
        std::ifstream doc(path.get<std::string>());
        if (doc.is_open()) {
            std::string text((std::istreambuf_iterator<char>(doc)), std::istreambuf_iterator<char>());
            contents.push_back(text);
        }
    }
    return contents;
}


int ConverterJSON::GetResponseLimit(){
    std::ifstream file("config.json");
    if(!file.is_open()) return 5;
    json j;
    file >> j;
    return j["config"].value("max_responses", 5);
}

std::vector<std::string> ConverterJSON::GetRequests(){
    std::vector<std::string> requests;
    std::ifstream file("requests.json");
    if(!file.is_open()) return requests;
    json j;
    file >> j;
    for(const auto &request : j["requests"]){
        requests.push_back(request.get<std::string>());
    }
    return requests;
}

void ConverterJSON::pushAnswers(std::vector<std::vector<RelativeIndex>> answers){
    json result_json;
    for(size_t i = 0; i < answers.size(); ++i){
        std::string reqName = "request" + std::to_string(i + 1);
        auto &resObj = result_json["answers"][reqName];
        if(answers[i].empty()){
            resObj["result"] = false;
        }else{
            resObj["result"] = true;
            for(const auto &rel : answers[i]){
                json item;
                item["doc_id"] = rel.doc_id;
                item["rank"] = rel.rank;
                resObj ["relevance"].push_back(item);

            }
        }
    }
    std::ofstream file("answers.json");
    file << result_json.dump(4);
}

