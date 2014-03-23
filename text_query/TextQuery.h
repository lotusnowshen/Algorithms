#ifndef _TEXT_QUERY_H__
#define _TEXT_QUERY_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdexcept>

class TextQuery
{
    public:
        typedef std::vector<std::string>::size_type line_no;
        
        void read_file(std::ifstream &is)
        {
            store_file(is);
            build_map();
        }
        std::set<line_no> run_query(const std::string&) const;
        std::string text_line(line_no) const;

    private:
        void store_file(std::ifstream&);
        void build_map();

        std::vector<std::string> lines_no_text;
        std::map<std::string, std::set<line_no> > word_map;

};


#endif
