#include "ConsoleStringGetter.h"

std::string ConsoleStringGetter::GetString()
{
    std::string result = "";
    std::getline(std::cin, result);
    return result;
}
