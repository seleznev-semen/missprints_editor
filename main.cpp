#include <iostream>
#include <string>
#include "InputAnalyzer.h"
#include "FileStringGetter.h"
#include "ConsoleStringGetter.h"
using namespace std;

int main()
{
    string dictionary = "";
    string input = "";

    //Case input and dictionary are read from console:
    /*ConsoleStringGetter csg;      
    dictionary = csg.GetString();
    input = csg.GetString();*/

    //Case input and dictionary are read from file:
    string dict_path = "_dictionary.txt";
    string input_path = "_input.txt";
    FileStringGetter fsg;
    fsg.SetPath(dict_path);
    dictionary = fsg.GetString();
    fsg.SetPath(input_path);
    input = fsg.GetString();

    //ia - object-analyzer, method edit return editied vector (with corrected input words);
    InputAnalyzer ia (input, dictionary);
    vector<string> edited = ia.Edit();

    for (auto& it : edited)
        cout << it << ' ';

    return 0;
}
