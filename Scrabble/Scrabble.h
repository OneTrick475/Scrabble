/**
*
* Solution to course project #8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Ivan Bukev
* @idnumber 2MI0600196
* @compiler VC
*
* header file for the Scrabble struct
*
*/

#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <unordered_set>
#include <vector>

struct Scrabble {
	private:
		std::unordered_set<std::string> words;
		std::vector<char> letters;
		std::unordered_set<std::string> usedWords;
		int numOfLetters = 10;
		int numOfRounds = 10;
		int score = 0;

		void initializeWords();
		void generateRandomLetters();
		void addWord(std::string const& word);
		bool wordExists(std::string const& word);
		void printMenu();
		void printLetters();
		void settings();
		int getInput(int min, int max);
		bool lettersAreInvalid(const std::string& word);
		bool wordIsUsed(const std::string& word);
		std::string getWord();
		void startGame();

	public:
		void play();
	
};

#endif