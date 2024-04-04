#pragma once
#include "Chrono.h"
#include <cctype>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Game {
public:
	void PrintMessenge(string message, bool printTop = true, bool printBottom = true) {
		if (printTop) {
			cout << "+---------------------------------+" << endl;
			cout << "|";
		}
		else {
			cout << "|";
		}
		bool front = true;
		for (int i = message.length(); i < 33; i++) {
			front ? message = " " + message : message = message + " ";
			front = !front;
		}
		cout << message.c_str();
		if (printBottom) {
			cout << "|" << endl;
			cout << "+---------------------------------+" << endl;
		}
		else {
			cout << "|" << endl;
		}
	}
	void DrawGallow(int guessCount = 0) {
		if (guessCount >= 1) {
			PrintMessenge("|", false, false);
		}
		else {
			PrintMessenge("", false, false);
		}
		if (guessCount >= 2) {
			PrintMessenge("|", false, false);
		}
		else {
			PrintMessenge("", false, false);
		}
		if (guessCount >= 3) {
			PrintMessenge("O", false, false);
		}
		else {
			PrintMessenge("", false, false);
		}
		if (guessCount == 4) {
			PrintMessenge("/  ", false, false);
		}
		if (guessCount == 5) {
			PrintMessenge("/| ", false, false);
		}
		if (guessCount >= 6) {
			PrintMessenge("/|\\", false, false);
		}
		else {
			PrintMessenge("", false, false);
		}
		if (guessCount >= 7) {
			PrintMessenge("|", false, false);
		}
		else {
			PrintMessenge("", false, false);
		}
		if (guessCount == 8) {
			PrintMessenge("/ ", false, false);
		}
		if (guessCount >= 9) {
			PrintMessenge("/ \\", false, false);
		}

	}
	void PrintLetters(string input, char from, char to) {
		string s;
		for (char i = from; i <= to; i++) {
			if (input.find(i) == string::npos) {
				s += i;
				s += " ";
			}
			else {
				s += " ";
			}
		}
		PrintMessenge(s, false, false);
	}
	void PrintAviableLetters(string token) {
		PrintMessenge("Доступные слова.");
		PrintLetters(token, 'A', 'M');
		PrintLetters(token, 'N', 'Z');
	}
	bool PrintWordAndCheckWin(string word, string guesses) {
		PrintMessenge("Угадай слово.");
		bool won = true;
		string s;

		for (int i = 0; i < word.length(); i++) {
			if (guesses.find(word[i]) == string::npos) {
				won = false;
				s += "_ ";
			}
			else {
				s += word[i];
				s += " ";
			}
		}
		PrintMessenge(s, false);
		return won;
	}
	int AttemptsLeft(int maxTries, int tries) {
		PrintMessenge("Осталось попыток:", false, false);
		int attemptsLeft = maxTries - tries;
		PrintMessenge(to_string(attemptsLeft), false);
		return attemptsLeft;
	}
	string LoadRandomWord(string path) {
		int lineCount = 0;
		string word;
		vector<string> v;
		ifstream reader(path);
		if (reader.is_open()) {
			while (getline(reader, word)) {
				v.push_back(word);
			}
			int randomLine = rand() % v.size();
			word = v.at(randomLine);
			reader.close();
		}
		return word;
	}
	int TriesLeft(string word, string guessed) {
		int error = 0;
		for (int i = 0; i < guessed.length(); i++) {
			if (word.find(guessed[i]) == string::npos) {
				error++;
			}
		}
		return error;
	}
};