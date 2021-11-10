#pragma once

class MarkdownVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override{ _result = _result + li->getText() + "/n"; };

    void visitText(Text* t) override{ _result = _result + t->getText() + "/n"; }

    void visitParagraph(Paragraph* p) override{ _result = _result + p->getText() + "/n"; }

    std::string getResult() const override { return _result; }

private:
    std::string _result;
};