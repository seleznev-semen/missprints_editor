#include "FileStringGetter.h"

FileStringGetter::FileStringGetter() 
{
}

void FileStringGetter::SetPath(const std::string & Path)
{
    this->Path = Path;
}

std::string FileStringGetter::GetString()
{
    std::string result = "";
    std::fstream fs;
    fs.open(Path, std::fstream::in);
    while (!fs.eof())
    {
        std::string tmp = "";
        fs >> tmp;
        result += (tmp + ' ');
    }
    fs.close();
    return result;
}


