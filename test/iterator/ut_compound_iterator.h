#include "../../src/text.h"
#include "../../src/paragraph.h"
#include "../../src/iterator/iterator.h"

TEST(CaseCompoundIterator, CreateIterator) { 
    Text* t = new Text("text");
    Paragraph *p = new Paragraph(1, "title");
    Iterator* it;
    
    p->add(t);   
    it = p->createIterator();

    ASSERT_EQ("# title\n", it -> currentItem() -> getText());
    
    delete t, p, it;
}


