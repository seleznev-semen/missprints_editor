#pragma once
#include "IStringGetter.h"
#include <iostream>
#include <string>
/*Child-class of interface. Realizes reading strings from console*/
class ConsoleStringGetter :
    public IStringGetter
{
public:
    std::string GetString() override;           //realization of virtual function.
                                                //returns string which contains all words from consol. 
                                                //Each word must be separated from other with spaces while inputing
};

