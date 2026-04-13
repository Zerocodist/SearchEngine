#include "SearchServer.h"

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queries_input){
    std::vector<std::vector<RelativeIndex>> all_results;

    for(const auto &query : queries_input){
        std::set<std::string> unique_words;
        std::vector<RelativeIndex> rel_results;
        std::stringstream ss(query);
        std::string word;
        while(ss>>word){
            for(auto &c : word) c = std::tolower(c);
            unique_words.insert(word);
        }
        std::map<size_t, size_t> abs_relevance;
        for(const auto &w : unique_words){
            auto entries = _index.GetWordCount(w);
            for(const auto &entry : entries){
                abs_relevance[entry.doc_id] += entry.count;
            }
        }
        if(abs_relevance.empty()){
            all_results.push_back({});
            continue;
        }
        size_t max_abs = 0;
        for(const auto &pair : abs_relevance){
            if(pair.second > max_abs) max_abs = pair.second;
            float rank = static_cast<float>(pair.second) / max_abs;
            rel_results.push_back({pair.first, rank});
        }
        std::sort(rel_results.begin(), rel_results.end(), [](const RelativeIndex &a, const RelativeIndex &b){
            if(a.rank != b.rank) return a.rank > b.rank;
            return a.doc_id < b.doc_id;
        });
        all_results.push_back(rel_results);
    }
    return all_results;
}