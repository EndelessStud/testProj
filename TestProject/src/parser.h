#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

class Parser
{
public:
    Parser();
    static std::string getCountry(std::string json);
};

#endif // PARSER_H
