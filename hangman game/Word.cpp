#include "Word.h"

Word::Word()
{
	text = "";
	hint = "";
	displayText = "";
}

Word::Word(string text, string hint)
{
	setText(text);
	this->hint = hint;
}

Word::~Word()
{
}

void Word::setText(string text)
{
	this->text = text;
	displayText = text;
	for (int i = 0; i < text.length(); i++) {
		displayText[i] = '_';
	}
}

void Word::setHint(string hint)
{
	this->hint = hint;
}

int Word::getTextLength()
{
	return text.length();
}

string Word::getText()
{
	return text;
}

string Word::getHint()
{
	return hint;
}

void Word::displayWord()
{
	cout << "The word has " << text.size() << " characters" << endl;
	cout << displayText << endl;
}

int Word::checkGuess(char n)
{
	int occurence = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == n) {
			occurence++;
			this->displayText[i] = n;
		}
	}
	return occurence;
}
