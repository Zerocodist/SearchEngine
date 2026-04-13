#include "InvertedIndex.h"

void InvertedIndex::UpdateDocumentsBase(std::vector<std::string> input_docs){
    {
    std::lock_guard<std::mutex> lock(mutex);
    freq_dictionary.clear();
    docs = input_docs;
    }

    std::vector<std::thread> threads;

    for(size_t i = 0; i < docs.size(); ++i){
        threads.emplace_back([this, i](){
            std::stringstream ss(docs[i]);
            std::string word;
            while(ss >> word){
                for(auto &c : word) c = std::tolower(c);
                std::lock_guard<std::mutex> lock(mutex);
                auto& entries = freq_dictionary[word];
                bool found = false;
                for(auto &entry : entries){
                    if(entry.doc_id == i){
                        entry.count++;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    entries.push_back({i,1});
                }
            }
        });
    }
    for(auto &t : threads){
        if(t.joinable()) t.join();
}
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word) {
    std::lock_guard<std::mutex> lock(mutex);
    if (freq_dictionary.count(word)) {
        return freq_dictionary.at(word);
    }
    return {};
}
