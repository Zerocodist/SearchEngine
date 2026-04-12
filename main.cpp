#include "InvertedIndex.h"
#include "SearchServer.h"
#include "ConverterJSON.h"

int main(){
    std::cout << "--- Search Engine Started ---" << std::endl;

    ConverterJSON converter;
    std::vector<std::string> docs = converter.GetTextDocuments();

    if(docs.empty()){
        std::cerr << "No documents found to item!" << std::endl;
        return 1;
    }
    InvertedIndex index;
    index.UpdateDocumentsBase(docs);

    SearchServer server(index);

    std::vector<std::string> requests = converter.GetRequests();
    if(requests.empty()){
        std::cerr << "No requests found!" << std::endl;
        return 1;
    }
    auto results = server.search(requests);

    converter.pushAnswers(results);

    std::cout << "--- Done! Check answer.json file ---" << std::endl;

    return 0;
}