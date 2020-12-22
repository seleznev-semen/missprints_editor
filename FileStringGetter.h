#pragma once
#include <fstream>
#include "IStringGetter.h"

class FileStringGetter :
    public IStringGetter
{
public:
    FileStringGetter();
    std::string GetString() override;
    void SetPath(const std::string & Path);
private:
    std::string Path;
};
