#pragma once
#include<string>
/*Interface for recieving strings (strings can be inputed by console, or read from file)*/
class IStringGetter
{
public:
	virtual std::string GetString() = 0;
};

