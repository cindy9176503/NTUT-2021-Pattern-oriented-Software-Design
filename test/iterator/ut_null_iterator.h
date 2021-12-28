#include "../../src/circle.h"
#include "../../src/iterator/null_iterator.h"

TEST(CaseNullIterator, Constructor_NoException) {
    Iterator* it;
    ASSERT_NO_THROW(it = new NullIterator());

    delete it;
}

TEST(CaseNullIterator, CurrentItem_Exception) {
    NullIterator it;
    Shape* result;

    ASSERT_ANY_THROW(result = it.currentItem());
}

TEST(CaseNullIterator, First_Exception) {
    NullIterator it;
    ASSERT_ANY_THROW(it.first());
}

TEST(CaseNullIterator, Next_Exception) {
    NullIterator it;
    ASSERT_ANY_THROW(it.next());
}

TEST(CaseNullIterator, IsDone_True){
    NullIterator it;
    ASSERT_TRUE(it.isDone());
}

TEST(CaseNullIterator, NullIteratorIsIterator){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(typeid(it) == typeid(Iterator*));

    delete it;
}