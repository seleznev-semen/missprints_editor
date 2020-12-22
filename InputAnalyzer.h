#pragma once
#include <string>
#include <vector>
#include "lev_dist_mod.h"

class InputAnalyzer
{
public:
	InputAnalyzer();

	InputAnalyzer(std::string input, std::string dictionary);

	virtual ~InputAnalyzer();

	std::vector <std::string> && Edit();

private:
	std::string input;

	std::string dictionary;

	unsigned DictWordsCount;

	unsigned InpWordsCount;

	std::vector<std::string> Dictionary;
	
	std::vector<std::string> Input;

	void CountWordsInString();

	void SplitWords();

	void AddBrackets(std::string& str);

	std::string FindSimilarWord(const std::string& to_test, const std::vector<std::string>& dictionary);

	void EditWord(std::string& to_edit, const std::vector<std::string>& dictionary);
	
	void EditAllWords();
};

