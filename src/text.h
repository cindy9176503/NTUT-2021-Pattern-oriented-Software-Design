class Text : public Article {
   public:
    Text(std::string text) {}

    std::string getText() const override {}

    Iterator* createIterator() override {}

    void accept(ArticleVisitor* visitor) override {}
};