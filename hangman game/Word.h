#pragma once
#include <iostream>
#include < string>

using namespace std;

class Word
{
private:
	string text;
	string hint;
	string displayText;
public:
	Word();
	Word(string text, string hint);
	~Word();
	void setText(string text);
	void setHint(string hint);
	int getTextLength();
	string getText();
	string getHint();
	void displayWord();
	int checkGuess(char n);
};

