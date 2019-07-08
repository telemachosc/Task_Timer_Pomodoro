#include "timer.h"



Init::Init()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << "Welcome!\n" <<
		"This is a program to calculate the estimated time for doing tasks\n" <<
		"using the pomodoro technique with a little twist.\n" <<
		"Have fun!\n";


}

sessions::sessions()
{
	calc(s, b, bb, psy, t, dt, yn);
}

void sessions::calc(int s, int b, int bb, int psy, double t, double dt, char yn)
{
	while (true) {
		while (true) {
			std::cout << "\nInsert number of sessions (30 min): ";
			std::cin >> s;
			if (s < 21)
				break;
			std::cerr << "\nOverload!!!\n Insert again a realistic number of sessions.\n";
		}
		//////small break///////
		std::cout << "\nInsert size of the small breaks(min)[We recommend 5-10 minutes]: ";
		int b;
		std::cin >> b;

		//////big break //////
		std::cout << "\nInsert size of the big breaks(min)[We recommend 20-30 minutes]: ";
		int bb;
		std::cin >> bb;

		//////Psycological factor//////
		while (true) {
			std::cout << "\nFrom 1-5 (1:lowest, 5:highest) how do you feel about doing things today: ";
			int psy;
			std::cin >> psy;
			if (psy >= 1 && psy <= 5)
				break;
			std::cerr << "\n Error! Please provide a number between 1 and 5.\n";

		}

		/*
	////// Starting time///////
		cout << "Insert what time you are planning on starting reading: ";
		int st;
		cin >> st;
		*/


		t =time(s, b, bb)*pf(psy) ;
		dt= t / 60.0;

		std::cout << "\n\nThe total time you must spend on tasks today is: " << t << " minutes" << "=" << dt << " hours\n"
			<< "With " << b << " min. breaks and " << bb << " min. break after 4 sessions\n"
			<< "The calculation was done taking into account your psycological mood today.\nTimes may vary.\n"
			<< "Good luck!\n\n"
			<< "Do you want to run Task Timer again? (y/n)";
		char yn;
		std::cin >> yn;
		if (yn == 'n')
			break;
	}
}


double sessions::time(int s, int b, int bb)
{
	int t{ 0 };
	if (s <= 4) {
		t = 30 * s + b * (s - 1);
	}
	if (s > 4 && s <= 8) {
		t = 30 * s + b * (s - 2) + bb; // (s-2) because we must compensate for the additional term bb (big break)
	}
	if (s > 8 && s <= 12) {
		t = 30 * s + b * (s - 3) + bb * 2;
	}
	if (s > 12 && s <= 16) {
		t = 30 * s + b * (s - 4) + bb * 3;
	}
	if (s > 16 && s <= 20) {
		t = 30 * s + b * (s - 5) + bb * 4;
	}
	return t;
	
}

double sessions::pf(int a) 
{
	double b{ 0 };
	if (a == 1) b = 1.8;
	if (a == 2) b = 1.6;
	if (a == 3) b = 1.4;
	if (a == 4) b = 1.2;
	if (a == 5) b = 1.;

	return b;
}
