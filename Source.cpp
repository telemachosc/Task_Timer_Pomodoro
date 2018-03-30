
#include <iostream>
#include <windows.h>
#include<string>



int time (int s, int b, int bb) {
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

void print(std::string s) {

	std::cout << s << '\n';
}

int main() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	print( "Welcome!");
	print("This is a program to calculate the estimated study time");
	print("using the pomodoro technique.");
	print("Just input the number of sessions and the size of the breaks.");
	print("Have fun!\n");

	int s;
	while (true) {
		while (true) {
			print("Insert number of sessions (30 min): ");
			std::cin >> s;
			if (s < 21)
				break;

			std::cerr << "\nStudy overload!!!\n";
			std::cerr << "Insert again a realistic number of sessions.\n";
		}
	//////small break///////
		std::cout << "Insert size of the small breaks(min): ";
		int b;
		std::cin >> b;

	//////big break //////
		std::cout << "Insert size of the big breaks(min): ";
		int bb;
		std::cin >> bb;

		
		int t{ time(s, b, bb) };


		double dt{ static_cast<double>(t) / 60.0 };
		std::cout << "\n\n\n";
		std::cout << "The total time you must spend on reading is: " << t << " minutes" << "=" << dt << " hours\n";
		std::cout << "With " << b << " min. breaks and "<< bb << " min. break after 4 sessions\n";
		std::cout << "Good luck!\n";
		std::cout << "Do you want to calculate time again? (y/n)";
		char yn;
		std::cin >> yn;
		if (yn == 'n')
			break;
	}
	
}
