#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "game.hpp"
#include "global.hpp"

class Menu {

	private:
		void startGame();
		void showScores();
		void printMenu();
		void input(int err);

	public:
		void startMenu(int err = 0);

};

void Menu::startMenu(int err) {

	clear();

	drawAscii();
	std::cout << "  Welcome to 2048!"; endl(2);
	std::cout << "  	1. Play a New Game"; endl();
	std::cout << "  	2. View Highscores"; endl(2);

	input(err);

}

void Menu::input(int err) {

	if (err)
		std::cout << "  Invalid input. Please try again."; endl(2);

	std::cout << "  Enter Choice: ";
	char c;
	std::cin >> c;

	switch(c) {
		case '1':
			startGame();
			break;
		case '2':
			showScores();
			break;
		default:
			startMenu(1);
			break;
	}

}

void Menu::startGame() {

	Game g;
	g.startGame();

}

void Menu::showScores() {

	return;

}