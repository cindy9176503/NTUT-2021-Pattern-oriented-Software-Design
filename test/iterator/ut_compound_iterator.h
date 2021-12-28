#include "../../src/circle.h"
#include "../../src/compound_shape.h"
#include "../../src/iterator/compound_iterator.h"

TEST(CaseCompoundIterator, Constructor_NoException) {
    CompoundShape cs;
    Iterator* it;
    ASSERT_NO_THROW(it = cs.createIterator());

    delete it;
}

TEST(CaseCompoundIterator, Current) {    
    Circle* c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;
    
    cs -> addShape(c);
    it = cs -> createIterator();

    ASSERT_EQ(c, it -> currentItem());

    delete cs;
    delete it;
}

TEST(CaseCompoundIterator, First) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it; 

    cs -> addShape(c);
    it = cs -> createIterator();
    it -> first();

    ASSERT_EQ(c, it -> currentItem());

    delete cs;
    delete it;
}

TEST(CaseCompoundIterator, Next_NotIsDone_NoException) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;

    cs -> addShape(c);
    it = cs -> createIterator();

    ASSERT_NO_THROW(it -> next());

    delete cs;
    delete it;
}

TEST(CaseCompoundIterator, Next_IsDone_Exception) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;
    
    cs -> addShape(c);
    it = cs -> createIterator();

    it -> next();

    ASSERT_ANY_THROW(it -> next());

    delete cs;
    delete it;
}

TEST(CaseCompoundIterator, IsDone) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;
    
    cs -> addShape(c);
    it = cs -> createIterator();

    it -> next();

    ASSERT_TRUE(it -> isDone());

    delete cs;
    delete it;
}

TEST(CaseCompoundIterator, IsDone_Current_Exception) {    
    Circle *c = new Circle(1.0);
    CompoundShape* cs = new CompoundShape();
    Iterator* it;

    cs -> addShape(c);
    it = cs -> createIterator();

    it -> next();

    ASSERT_ANY_THROW(it -> currentItem());

    delete cs;
    delete it;
}

TEST(CaseCompoundIterator, CompoundIteratorIsIterator){
    CompoundShape* cs = new CompoundShape();
    Iterator* it = cs -> createIterator(); 

    ASSERT_TRUE(typeid(it) == typeid(Iterator*));

    delete cs;
    delete it;
}