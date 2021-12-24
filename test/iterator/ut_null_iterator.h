#include "../../src/circle.h"
#include "../../src/iterator/null_iterator.h"

TEST(CaseNullIterator, Constructor_NoException) {
    ASSERT_NO_THROW(new NullIterator());
}

TEST(CaseNullIterator, CurrentItem_Exception) {
    Iterator* it = new NullIterator();
    ASSERT_ANY_THROW(it->currentItem());

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

TEST(CaseNullIterator, NullIteratorIsIterator){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(typeid(it) == typeid(Iterator*));

    delete it;
}