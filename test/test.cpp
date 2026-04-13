#include <gtest/gtest.h>
#include "InvertedIndex.h"
#include "SearchServer.h"

TEST(InvertedIndex, GetWordCount){
    InvertedIndex idx;
    idx.UpdateDocumentsBase({"milk sugar", "sugar coffee"});
    auto result = idx.GetWordCount("sugar");
    ASSERT_EQ(result.size(), 2);
}

TEST(SearchServer, SearchReevance){
    InvertedIndex idx;
    idx.UpdateDocumentsBase({"apple banana","apple apple"});
    SearchServer srv(idx);
    auto result = srv.search({"apple"});
    
    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result[0][0].doc_id, 0);
    EXPECT_NEAR(result[0][0].rank, 1.0f, 0.01);
}
