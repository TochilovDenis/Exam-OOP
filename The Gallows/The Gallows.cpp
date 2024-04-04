#include "Game.h"

int ConsoleSetup(int);
int main()
{
	ConsoleSetup(1251);
	srand(time(0));

	Chrono time;
	Game game;

	string guesses = "";
	string wordToGueses;
	wordToGueses = game.LoadRandomWord("words.txt");
	int maxTries = 10;
	int tries = 0;
	bool win = false;
	do {
		system("cls");
		game.PrintMessenge("ВИСЕЛИЦА");
		game.DrawGallow(tries);
		game.PrintAviableLetters(guesses);
		win = game.PrintWordAndCheckWin(wordToGueses, guesses);
		if (win) break;
		game.AttemptsLeft(maxTries, tries);
		tries = game.TriesLeft(wordToGueses, guesses);
		char x;
		cout << ">"; cin >> x;
		if (guesses.find(x) == string::npos) {
			if (islower(x)) { x = toupper(x); }
			guesses += x;
		}
	} while (tries < maxTries);
	win ? game.PrintMessenge("Вы угадали слово.", false) : game.PrintMessenge("Вы не угадали слово.");
	if (!win) {
		game.PrintMessenge("Правильный ответ.", false, false);
		game.PrintMessenge(wordToGueses, false);
	}

	time.elapsed();
	time.PrintTime();
	system("pause");
	getchar();
	return 0;
}

int ConsoleSetup(int CP) {
	SetConsoleCP(CP);
	SetConsoleOutputCP(CP);
	return CP;
}

/*

+---------------------------------+
|           ВИСЕЛИЦА              |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
+---------------------------------+
|        Доступные слова          |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Угадай слово            |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
|        Осталось попыток:        |
|                10               |
+---------------------------------+
>

*/