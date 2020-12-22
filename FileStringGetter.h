#pragma once
#include <fstream>
#include "IStringGetter.h"
/*Child-class of interface. Realizes reading strings from files*/
class FileStringGetter :
    public IStringGetter
{
public:
    FileStringGetter();
    std::string GetString() override;           //realization of virtual function.
                                                //returns string which contains all words from file, each word is separated from other with spaces
    void SetPath(const std::string & Path);     //setter for path location of source file
private:
    std::string Path;                            //containes path to file with source text, which will be converted to string
};
