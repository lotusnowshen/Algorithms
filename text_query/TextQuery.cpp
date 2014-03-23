#include "TextQuery.h"

void TextQuery::store_file(std::ifstream &is)
{
    std::string text_line;
    while(getline(is, text_line))
    {
       lines_no_text.push_back(text_line); 
    }
}

void TextQuery::build_map()
{
    for()

}
