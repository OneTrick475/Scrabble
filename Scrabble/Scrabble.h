#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <unordered_set>
#include <vector>

struct Scrabble {
	private:
		std::unordered_set<std::string> words;
		std::vector<char> letters;
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
		std::string getWord();
		void startGame();

	public:
		void play();
	
};

#endif