class ListItem : public Article {
   public:
    ListItem(std::string text) {}

    std::string getText() const override {}

    Iterator* createIterator() override {}

    void accept(ArticleVisitor* visitor) override {}
};