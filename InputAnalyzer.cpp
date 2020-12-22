#include "InputAnalyzer.h"


InputAnalyzer::InputAnalyzer() : input(""), dictionary(""), DictWordsCount(0), InpWordsCount(0)
{
}

InputAnalyzer::InputAnalyzer(std::string input, std::string dictionary) : input(input), dictionary(dictionary)
{
    CountWordsInString();
    SplitWords();
}

InputAnalyzer::~InputAnalyzer()
{
}

std::vector<std::string> && InputAnalyzer::Edit()
{
    this->EditAllWords();
    return std::move(Input);
}

void InputAnalyzer::CountWordsInString()
{
    unsigned count = 0;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] == ' ' && input[i + 1] != ' ' && input[i + 1] != '\0')
            ++count;
    }
    this->InpWordsCount = count + 1;
    
    count = 0;
    for (size_t i = 0; i < dictionary.size(); ++i)
    {
        if (dictionary[i] == ' ' && dictionary[i + 1] != ' ' && dictionary[i + 1] != '\0')
            ++count;
    }
    this->DictWordsCount = count + 1;
}

void InputAnalyzer::SplitWords()
{
    std::string tmp;
    tmp.reserve(50);

    Input.reserve(InpWordsCount);
    for (size_t i = 0, prev = 0, curr = 0; i <= input.size(); ++i)
    {
        curr = i;
        if (input[i] == ' ' || input[i] == '\0')
        {
            for (int j = prev; j < curr; ++j)
                tmp += input[j];
            Input.push_back(tmp);
            tmp.clear();
            prev = curr + 1;      //skipping ' '
        }
    }

    Dictionary.reserve(InpWordsCount);
    for (size_t i = 0, prev = 0, curr = 0; i <= dictionary.size(); ++i)
    {
        curr = i;
        if (dictionary[i] == ' ' || dictionary[i] == '\0')
        {
            for (int j = prev; j < curr; ++j)
                tmp += dictionary[j];
            Dictionary.push_back(tmp);
            tmp.clear();
            prev = curr + 1;      //skipping ' '
        }
    }
}

void InputAnalyzer::AddBrackets(std::string& str)
{
    str = "{" + str + "?}";
}

std::string InputAnalyzer::FindSimilarWord(const std::string& to_test, const std::vector<std::string>& dictionary)
{
    int lev_dist_minimal = 9999;
    std::vector<std::string> similar_words;
    for (auto& word : dictionary)
    {
        int current_lev_dist = calculate_lev_dist_mod(word, to_test);
        if (current_lev_dist < lev_dist_minimal)
        {
            lev_dist_minimal = current_lev_dist;
        }
    }
    for (auto& word : dictionary)
    {
        int current_lev_dist = calculate_lev_dist_mod(word, to_test);
        if (current_lev_dist == lev_dist_minimal)
        {
            similar_words.push_back(word);
        }
    }
    if (similar_words.size() == 1)
        return similar_words[0];
    else
    {
        std::string result;
        for (auto& it : similar_words)
            result = result + it + ' ';
        result.pop_back();
        return "{" + result + "}";
    }
}

void InputAnalyzer::EditWord(std::string& to_edit, const std::vector<std::string>& dictionary)
{
    int lev_dist_minimal = 99999;
    for (auto& word : dictionary)
    {
        if (to_edit == word)
            return;
        else
        {
            int lev_dist_current = calculate_lev_dist_mod(word, to_edit);
            if (lev_dist_current < lev_dist_minimal)
                lev_dist_minimal = lev_dist_current;
        }
    }
    if (lev_dist_minimal > 2)
        AddBrackets(to_edit);
    else
    {
        to_edit = FindSimilarWord(to_edit, dictionary);
    }
}

void InputAnalyzer::EditAllWords()
{
    for (auto& word : Input)
    {
        EditWord(word, Dictionary);
    }
}