#pragma once
#include "IStringGetter.h"
#include <iostream>
#include <string>
class ConsoleStringGetter :
    public IStringGetter
{
public:
    std::string GetString() override;
private:

};

