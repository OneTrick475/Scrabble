#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <map>
#include <time.h>
#include <cstdlib>
#include "Scrabble.h"

using namespace std;

void Scrabble::initializeWords() {
	ifstream file;

	file.open("words.txt");

	while (file.is_open()) {
		string word;

		while (!file.eof()) {
			file >> word;
			words.insert(word);
		}
		file.close();
	}
}

void Scrabble::generateRandomLetters() {
	srand(time(0));

	for(int i = 0; i < numOfLetters; ++i){
		char letter = 'a' + (rand() % 26);
		letters.push_back(letter);
	}
}

bool Scrabble::wordExists(string const &word){
	return words.find(word) != words.end();
}

void Scrabble::addWord(string const &word){
	if (!wordExists(word)) {
		ofstream file;

		file.open("words.txt", ios::app);

		file << word << '\n';

		words.insert(word);
	}
}

void Scrabble::printMenu(){
	cout << "1. New Game\n2. Settings\n3. Add Word\n4. Exit\n";
}

void Scrabble::printLetters(){
	cout << "Available letters: ";
	for(char letter : letters){
		cout << letter << ' ';
	}
	cout << '\n';
}

void Scrabble::settings(){
	cout << "1. Change Number of Letters\n2. Change Number of Rounds\n";

	int option = getInput(1, 2);

	if (option == 1) {
		cout << "Enter the number of letters\n";
		numOfLetters = getInput(1, 26);
	}
	else {
		cout << "Enter the number of rounds\n";
		numOfRounds = getInput(1, 30);
	}
}

int Scrabble::getInput(int min, int max){
	int option;

	cin >> option;
	while(cin.fail() || option < min || option > max){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		printf("Invalid option. Enter a number between %d and %d\n", min, max);
		cin >> option;
	}
	return option;
}

bool Scrabble::lettersAreInvalid(const string &word){
	map<char, int> lettersMap;

	for (char letter : letters) {
		if (lettersMap.find(letter) == lettersMap.end())
					lettersMap[letter] = 1;
		else
			++lettersMap[letter];
	}

	for (char letter : word) {
		if (lettersMap.find(letter) == lettersMap.end() || lettersMap[letter] == 0)
			return true;
		--lettersMap[letter];
	}

	return false;
}

string Scrabble::getWord(){
	string word;
	cin >> word;

	while (!wordExists(word) || lettersAreInvalid(word)) {
				cout << "Invalid Word\n";
				printLetters();
				cin >> word;
			}
	return word;
}

void Scrabble::startGame(){
	generateRandomLetters();

	for(int i = 1; i<=numOfRounds; ++i){
				printf("Round %d. ", i);
				printLetters();

				string word = getWord();

				score += word.length();

				if(i != numOfRounds)
					printf("Score: %d\n", score);
			}
	printf("Your total points are %d\n", score);
	letters.clear();
	score = 0;
}


void Scrabble::play(){
	initializeWords();

	printMenu();

	int option = getInput(1 ,4);

	while(option != 4){
		if(option == 1){
			startGame();
		}
		else if(option == 2){
			settings();
		}
		else if (option == 3) {
			string word;

			cout << "Type the word you want to add\n";

			cin >> word;

			addWord(word);
		}
		printMenu();
		option = getInput(1, 4);
	}

}
	

