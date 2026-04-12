#include <QtTest/QtTest>
#include <vector>
#include <string>
#include "InvertedIndex.h"
#include "SearchServer.h"

class SearchEngineTest : public QObject {
    Q_OBJECT
private slots:
    void test_inverted_index(){
        InvertedIndex idx;
        idx.UpdateDocumentsBase({"milk sugar", "sugar coffee"});
        auto result = idx.GetWordCount("sugar");
        QCOMPARE(result.size(), (size_t)2);
    }
    void test_search_server_relevance(){
        InvertedIndex idx;
        idx.UpdateDocumentsBase({"apple banan", "apple apple"});
        SearchServer srv(idx);
        auto result = srv.search({"apple"});
        QVERIFY(!result.empty());
        QCOMPARE(result[0][0].doc_id, (size_t)0);
        QCOMPARE(result[0][0].rank, 1.0f);
    }
};

QTEST_MAIN(SearchEngineTest);
#include "test.moc"