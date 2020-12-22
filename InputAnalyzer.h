#pragma once
#include <string>
#include <vector>
#include "lev_dist_mod.h"
/* class-analyzer. Realizes main method Edit, which takes 2 string as parametres (input and dictionary)
/* and returns vector of corrected word. vector is recieved by correcting words in @input@ string according to the dictionary.
/* According to task cases, corrected word is pushed to resuting vector. If there are 2 (or more) varianst of corrections, requireing same amont of editions,
/* result of correction must be "{variant1, variant2, ...}". If word cant be corrected with 2 editions, it must be pushed as "{uncorrected_word?}"*/
class InputAnalyzer
{
public:
	InputAnalyzer();

	/* ctor initializes input and dictionary variables, also calls funcions CountWordsInString(), SplitWords()
	/* this functions are filling vectors Dictionary and Input with single words; also functions set vars DictWordsCount and InpWordsCount*/
	InputAnalyzer(std::string input, std::string dictionary);
	
	virtual ~InputAnalyzer();

	/* main (resulting) function, that performs the correction and returns corrected vector;*/
	std::vector <std::string> && Edit();

private:
	std::string input;				//contains words to correct

	std::string dictionary;			//contains words of dictionary

	unsigned DictWordsCount;		//var for amount of ords in dictionary

	unsigned InpWordsCount;			//var for amount of words in Input (to correct)

	std::vector<std::string> Dictionary;	//vector for splited words of dictionary
	
	std::vector<std::string> Input;			//vector for splited words of input (to correct)

	void CountWordsInString();				//method sets vars DictWordsCount, InpWordsCount according to strings recieved in ctor

	void SplitWords();						//method splits strings recieved in ctor, puts singl words into fit vectors

	void AddBrackets(std::string& str);		//adds brackets ({word?}) to word, if it cant be corrected

	/*function searches for most similar word (having less value of levenshtein distance) in dictionary, and returns this word.
	/* if 2 jr more words are fit, function returns {word1 word2 ...}*/
	std::string FindSimilarWord(const std::string& to_test, const std::vector<std::string>& dictionary);	
	
	void EditWord(std::string& to_edit, const std::vector<std::string>& dictionary);		//edits single word according to dictionary
	
	void EditAllWords();					//edit all words in vector according to dictionary.
};

