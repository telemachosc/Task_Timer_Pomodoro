
#include <iostream>
#include <windows.h>
#include <string>
#include "time_func.h"


int main() {


	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << "Welcome!\n" <<
		"This is a program to calculate the estimated time for doing tasks\n" <<
		"using the pomodoro technique with a little twist.\n" <<
		"Have fun!\n";

	int s;
	while (true) {
		while (true) {
			std::cout << "\nInsert number of sessions (30 min): ";
			std::cin >> s;
			if (s < 21)
				break;
			std::cerr << "\nOverload!!!\n";
			std::cerr << "Insert again a realistic number of sessions.\n";
		}
		//////small break///////
		std::cout << "\nInsert size of the small breaks(min)[We recommend 5-10 minutes]: ";
		int b;
		std::cin >> b;

		//////big break //////
		std::cout << "\nInsert size of the big breaks(min)[We recommend 15-20 minutes]: ";
		int bb;
		std::cin >> bb;

		//////Psycological factor//////
		std::cout << "\nFrom 1-5 (1:lowest, 5:highest) how do you feel about doing things today: ";
		int psy;
		std::cin >> psy;
		
		/*
	////// Starting time///////
		cout << "Insert what time you are planning on starting reading: ";
		int st;
		cin >> st;
		*/
		
		double t{ time(s, b, bb)*pf(psy)};


		double dt{ t / 60.0 };
		std::cout << "\n\nThe total time you must spend on your tasks is: " << t << " minutes" << "=" << dt << " hours\n"
			<< "With " << b << " min. breaks between sessions and " << bb << " min. break after 4 sessions\n"
			<< "Good luck!\n"
			<< "Do you want to calculate time again? (y/n)";
		char yn;
		std::cin >> yn;
		if (yn == 'n')
			break;
	}
}
