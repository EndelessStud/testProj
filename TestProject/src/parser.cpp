#include "parser.h"

Parser::Parser()
{

}

std::string Parser::getCountry(std::string json)
{
    boost::property_tree::ptree pt;
    std::istringstream ss(json);
    boost::property_tree::read_json(ss,pt);
    std::string country = pt.get<std::string>("country");
    return country;
}
