#include "Game.h"

Game::Game()
{
	failCount = hintCount = wordCount = 0;
	failLimit = hintLimit = wordLimit = 0;
}

Game::~Game()
{
}

void Game::setFailLimit()
{
	cout << "input the limit for failure: ";
	int fl;
	cin >> fl;
	failLimit = fl;
}

void Game::setHintLimit()
{
	int hl;
	do {
		cout << "input the limit for hint: ";
		cin >> hl;
		if (hl > 0 && hl < wordLimit) {
			hintLimit = hl;
		}
		else {
			cout << "Invalid number of hint limit" << endl;
		}
	} while (!(hl > 0 && hl < wordLimit));
}

void Game::setWordLimit()
{
	cout << "input the number of words to  be guess: ";
	int wl;
	cin >> wl;
	wordLimit = wl;
}

int Game::getFailLimit()
{
	return failLimit;
}

int Game::getHintLimit()
{
	return hintLimit;
}

int Game::getWordLimit()
{
	return wordLimit;
}

int Game::getNumberWord()
{
	return wordBank.size();
}

void Game::addWord(Word w)
{
	wordBank.push_back(w);
}

void Game::resetWordBank()
{
	wordBank.clear();
}

void Game::shuffleWordBank()
{
	srand(time(0));
	int count = 0;
	while (true) {
		int ind1 = rand() % wordBank.size();
		int ind2 = rand() % wordBank.size();
		if (ind1 == ind2) {
			continue;
		}
		Word tmp = wordBank[ind1];
		wordBank[ind1] = wordBank[ind2];
		wordBank[ind2] = tmp;
		count++;
		if (count > 10) {
			break;
		}
	}
}

Word Game::getOneWord(int index)
{
	return wordBank[index];
}
