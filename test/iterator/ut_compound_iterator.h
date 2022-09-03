#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/iterator/iterator.h"

TEST(CaseCompoundIterator, CreateIterator) { 
    Article* t = new Text("text");
    Article* p = new Paragraph(1, "title");
    Article* result;
    Iterator* it;
    
    p->add(t);   
    it = p->createIterator();

    ASSERT_EQ(t, result = it -> currentItem());
    
    delete t;
    delete p;
    delete result;
    delete it;
}

TEST(CaseCompoundIterator, First) { 
    Article* t = new Text("text");
    Article *p = new Paragraph(1, "title");
    Article* result;
    Iterator* it;
    
    p->add(t);   
    it = p->createIterator();

    it->first();

    ASSERT_EQ(t, result = it -> currentItem());
    
    delete t;
    delete p;
    delete result;
    delete it;
}

TEST(CaseCompoundIterator, FirstAndNext) { 
    Article* t = new Text("text");
    Article* li = new ListItem("list");
    Article *p = new Paragraph(1, "title");
    Article* result;
    Iterator* it;
    
    p->add(t);   
    p->add(li);
    it = p->createIterator();

    it->first();
    it->next();

    ASSERT_EQ(li, result = it->currentItem());
    
    delete t;
    delete li;
    delete p;
    delete result;
    delete it;
}

TEST(CaseCompoundIterator, isDoneCallNextShouldThrow) { 
    Article* t = new Text("text");
    Article *p = new Paragraph(1, "title");
    Iterator* it;
    
    p->add(t);   
    it = p->createIterator();

    it->next();

    ASSERT_ANY_THROW(it->next());
    
    delete t;
    delete p;
    delete it;
}

TEST(CaseCompoundIterator, isDoneGetCurrentItemShouldThrow) { 
    Article* t = new Text("text");
    Article *p = new Paragraph(1, "title");
    Article* result;
    Iterator* it;
    
    p->add(t);   
    it = p->createIterator();

    it->next();

    ASSERT_ANY_THROW(result = it->currentItem());
    
    delete t;
    delete p;
    delete result;
    delete it;
}