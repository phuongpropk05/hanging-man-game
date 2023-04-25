#include <iostream>
#include <string>
#include "Menu.h"
#include "Game.h"

using namespace std;

enum actionType {
	PLAY_GAME,
	EXIT_GAME,
	HINT,
	FAIL,
	WORD,
	ADD,
	RESET,
	SHOWH,
	SHOWF,
	SHOWW,
	SHOWNW,
	BACK
};

void main() {
	Menu* mainMenu = new Menu("Main Menu", "The game main menu");
	Menu* settingMenu = new Menu("Game setting menu", "Manage game play");
	Menu* wordBankMenu = new Menu("Word bank menu", "Manage word bank");
	Menu* playMenu = new Menu("Play Game", "Let's play", PLAY_GAME);
	Menu* ExitMenu = new Menu("Exit", "See you again!", EXIT_GAME);
	
	mainMenu->addSubMenu(settingMenu);
	mainMenu->addSubMenu(wordBankMenu);
	mainMenu->addSubMenu(playMenu);
	mainMenu->addSubMenu(ExitMenu);

	Menu* hint = new Menu("Hint setting", "set the max hint can be used");
	Menu* fail = new Menu("Fail setting", "set the max failure in the game");
	Menu* word = new Menu("Word setting", "set the number of word in the game");

	settingMenu->addSubMenu(word);
	settingMenu->addSubMenu(hint);
	settingMenu->addSubMenu(fail);
	settingMenu->addSubMenu(mainMenu);

	Menu* setHint = new Menu("Hint setting", "set the max hint can be used", HINT);
	Menu* setFail = new Menu("Fail setting", "set the max failure in the game", FAIL);
	Menu* setWord = new Menu("Word setting", "set the number of word in the game", WORD);
	Menu* curHint = new Menu("Current Hint", "Show the max hint can be used", SHOWH);
	Menu* curFail = new Menu("Current Fail", "Show the max failure in the game", SHOWF);
	Menu* curWord = new Menu("Current Word", "Show the number of word in the game", SHOWW);

	hint->addSubMenu(setHint);
	hint->addSubMenu(curHint);
	hint->addSubMenu(settingMenu);
	curHint->addSubMenu(settingMenu);
	setHint->addSubMenu(settingMenu);

	fail->addSubMenu(setFail);
	fail->addSubMenu(curFail);
	fail->addSubMenu(settingMenu);
	curFail->addSubMenu(settingMenu);
	setFail->addSubMenu(settingMenu);

	word->addSubMenu(setWord);
	word->addSubMenu(curWord);
	word->addSubMenu(settingMenu);
	curWord->addSubMenu(settingMenu);
	setWord->addSubMenu(settingMenu);

	Menu* addWord = new Menu("Word setting", "Add a new word", ADD);
	Menu* resetWord = new Menu("Reset", "reset the word bank", RESET);
	Menu* curNumWord = new Menu("Current Number Word", " ", SHOWNW);

	wordBankMenu->addSubMenu(addWord);
	wordBankMenu->addSubMenu(curNumWord);
	wordBankMenu->addSubMenu(resetWord);
	wordBankMenu->addSubMenu(mainMenu);

	curNumWord->addSubMenu(wordBankMenu);
	addWord->addSubMenu(wordBankMenu);
	resetWord->addSubMenu(wordBankMenu);
	
	tt:

	Menu* currentMenu = mainMenu;

	Game* currentGame = new Game();

	Word newWord;
	string nWord;
	string hWord;
	int num = 0;

	currentMenu->displayMenu();
	while (true) {
		int option = currentMenu->promtOption();
		currentMenu = currentMenu->getSubMenu(option);
		currentMenu->displayMenu();
		switch (currentMenu->getAction()) {
		case -1:
			break;
		case PLAY_GAME:
			cout << "Play game" << endl;
			currentGame->shuffleWordBank();
			char guess;
			for (int i = 0; i < currentGame->getWordLimit(); i++) {
				cout << "The word number " << i + 1 << ": " << endl;
				currentGame->getOneWord(i).displayWord();
				do {
					cout << "Enter your guess: ";
					cin >> guess;
					cout << "There are " << currentGame->getOneWord(i).checkGuess(guess) << " character " << guess << " in this word" << endl;
					currentGame->getOneWord(i).displayWord();
					if (currentGame->getOneWord(i).checkGuess(guess) == 0) {
						num++;
						cout << "You have " << currentGame->getFailLimit() - num << " times left to guess" << endl;
					}
					if (currentGame->getFailLimit() - num == 0) {
						cout << "Game Over" << endl;
						goto tt;
					}
				} while (currentGame->getOneWord(i).checkGuess(guess) < currentGame->getOneWord(i).getTextLength());
			}
			break;
		case FAIL:
			currentGame->setFailLimit();
			break;
		case HINT:
			currentGame->setHintLimit();
			break;
		case WORD:
			currentGame->setWordLimit();
			break;
		case ADD:
			cout << "input the word that you want to add: ";
			cin >> nWord;
			cout << "input the hint for this word: ";
			cin >> hWord;
			cin.ignore();
			newWord.setHint(hWord);
			newWord.setText(nWord);
			currentGame->addWord(newWord);
			break;
		case SHOWW:
			cout << "The number of word in this game is: " << currentGame->getWordLimit() << endl;
			break;
		case SHOWH:
			cout << "The max hint can be used is: " << currentGame->getHintLimit() << endl;
			break;
		case SHOWF:
			cout << "The max failure in this game is: " << currentGame->getFailLimit() << endl;
			break;
		case SHOWNW:
			cout << "The number of word in the word bank is: " << currentGame->getNumberWord() << endl;
			break;
		case RESET:
			cout << "Do you want to clear the word bank?(Y/N): ";
			char choice;
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				currentGame->resetWordBank();
				cout << "Reset complete!" << endl;
			}
			else {
				cout << "The word bank still remains" << endl;
			}
			break;
		case EXIT_GAME:
			cout << "Exit the game" << endl;
			break;
		default:
			cout << "default action" << endl;
		}
	}


}