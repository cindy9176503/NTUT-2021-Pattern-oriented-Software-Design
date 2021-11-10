class Paragraph : public Article {
   public:
    Paragraph(int level, std::string text) {}

    ~Paragraph() {}

    std::string getText() const override {}

    int getLevel() const override {}

    Iterator* createIterator() override {}

    void add(Article* content) override {}

    void accept(ArticleVisitor* visitor) override {}
};