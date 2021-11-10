#include "./article_visitor.h"
#include "./markdown_visitor.h"
#include "../text.h"
#include "../list_item.h"
#include "../paragraph.h"


void MarkdownVisitor::visitListItem(ListItem* li) {
     _result += li->getText(); 
};