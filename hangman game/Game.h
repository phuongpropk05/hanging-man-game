#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Word.h"

using namespace std;

class Game
{
private:
	int failCount, hintCount, wordCount;
	int failLimit, hintLimit, wordLimit;
	vector<Word> wordBank;
public:
	Game();
	~Game();
	void setFailLimit();
	void setHintLimit();
	void setWordLimit();
	int getFailLimit();
	int getHintLimit();
	int getWordLimit();
	int getNumberWord();
	void addWord(Word w);
	void resetWordBank();
	void shuffleWordBank();
	Word getOneWord(int index);
};

