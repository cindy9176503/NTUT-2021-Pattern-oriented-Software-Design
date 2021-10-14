class ListItem : public Article {
public:
    ListItem(std::string text):_text(text) {}

    ~ListItem() {}

    std::string getText() const override { return "- " + _text; }
    
private:
    std::string _text;
};