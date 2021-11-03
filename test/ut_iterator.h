#include "../src/circle.h"
#include "../src/compound_shape.h"
#include "../src/iterator/null_iterator.h"

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

TEST(CaseCompoundIterator, OneShape_Current) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;

    cs -> addShape(c);
    it = cs -> createIterator();
    
    ASSERT_EQ(c, it -> currentItem());

    delete c, cs, it;
}

TEST(CaseCompoundIterator, OneShape_First) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it; 
    
    cs -> addShape(c);
    it = cs -> createIterator();
    it -> first();
    ASSERT_EQ(c, it -> currentItem());

    delete c, cs, it;
}

TEST(CaseCompoundIterator, OneShape_Next_Exception) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;
    
    cs -> addShape(c);
    it = cs -> createIterator();

    it -> next();
    ASSERT_ANY_THROW(it -> next());

    delete c, cs, it;
}

TEST(CaseCompoundIterator, OneShape_IsDone) {    
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;
    
    cs -> addShape(c);
    it = cs -> createIterator();

    it -> next();
    ASSERT_TRUE(it -> isDone());

    delete c, cs, it;
}

TEST(CaseCompoundIterator, OneShape_IsDone_Current_Exception) {    
    Circle *c = new Circle(1.0);
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    it = cs -> createIterator();

    it -> next();
    ASSERT_ANY_THROW(it -> currentItem());

    delete c, cs, it;
}

TEST(CaseCompoundIterator, TwoShapes_Current) {    
    Circle *c = new Circle(1.0);
    Circle *c2 = new Circle(2.0); 
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    it = cs -> createIterator();

    ASSERT_EQ(c, it -> currentItem());

    delete c, c2, cs, it;
}

TEST(CaseCompoundIterator, TwoShapes_First) {    
    Circle *c = new Circle(1.0);
    Circle *c2 = new Circle(2.0); 
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    it = cs -> createIterator();

    it -> first();
    ASSERT_EQ(c, it -> currentItem());

    delete c, c2, cs, it;
}

TEST(CaseCompoundIterator, TwoShapes_Next) {    
    Circle *c = new Circle(1.0);
    Circle *c2 = new Circle(2.0); 
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    it = cs -> createIterator();

    it -> next();
    ASSERT_EQ(c2, it -> currentItem());

    delete c, c2, cs, it;
}

TEST(CaseCompoundIterator, TwoShapes_Next2) {    
    Circle *c = new Circle(1.0);
    Circle *c2 = new Circle(2.0); 
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    it = cs -> createIterator();

    it -> next();
    it -> next();
    ASSERT_ANY_THROW(it -> currentItem());

    delete c, c2, cs, it;
}

TEST(CaseCompoundIterator, TwoShapes_IsDone_True) {    
    Circle *c = new Circle(1.0);
    Circle *c2 = new Circle(2.0); 
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    it = cs -> createIterator();

    it -> next();
    it -> next();
    ASSERT_TRUE(it -> isDone());

    delete c, c2, cs, it;
}


TEST(CaseCompoundIterator, TwoShapes_IsDone_Current_Exception) {    
    Circle *c = new Circle(1.0);
    Circle *c2 = new Circle(2.0);
    CompoundShape* cs = new CompoundShape();

    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    it = cs -> createIterator();

    it -> next();
    it -> next();
    ASSERT_ANY_THROW(it -> currentItem());

    delete c, c2, cs, it;
}
