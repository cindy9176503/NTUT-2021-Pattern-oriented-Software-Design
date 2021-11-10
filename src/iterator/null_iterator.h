class NullIterator : public Iterator {
   public:
    void first() override {}

    Article* currentItem() const override {}

    void next() override {}

    bool isDone() const override {}
};
