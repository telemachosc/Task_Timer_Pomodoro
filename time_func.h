#pragma once

double time(int s, int b, int bb) {
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

double pf(int a) {
	double b{ 0 };
	if (a == 1) b = 1.8;
	if (a == 2) b = 1.6;
	if (a == 3) b = 1.4;
	if (a == 4) b = 1.2;
	if (a == 5) b = 1.;

	return b;
}
