#include "../../src/iterator/null_iterator.h"

TEST(CaseNullIterator, Current_Exception) {
    Iterator* it = new NullIterator();
    ASSERT_ANY_THROW(it->next());

    delete it;
}

TEST(CaseNullIterator, First_Exception) {
    Iterator* it = new NullIterator();
    ASSERT_ANY_THROW(it->first());

    delete it;
}

TEST(CaseNullIterator, Next_Exception) {
    Iterator* it = new NullIterator();
    ASSERT_ANY_THROW(it->next());

    delete it;
}

TEST(CaseNullIterator, IsDone_True){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());

    delete it;
}