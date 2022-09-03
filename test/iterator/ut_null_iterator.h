#include "../../src/iterator/null_iterator.h"

TEST(CaseNullIterator, FirstShouldThrow) {
    Iterator* it = new NullIterator();
    ASSERT_ANY_THROW(it->first());
}

TEST(CaseNullIterator, CurrentItemShouldThrow) {
    Iterator* it = new NullIterator();
    Article* art;

    ASSERT_ANY_THROW(art = it->currentItem());

    delete it, art;
}

TEST(CaseNullIterator, NextShouldThrow) {
    Iterator* it = new NullIterator();
    ASSERT_ANY_THROW(it->next());
}

TEST(CaseNullIterator, IsDoneShouldBeTrue){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());

    delete it;
}