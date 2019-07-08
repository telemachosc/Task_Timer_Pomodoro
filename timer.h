#pragma once

#include <iostream>
#include <windows.h>
#include <string>

class Init
{
public:
	Init();
};

class sessions
{
	int s, b, bb, psy;
	double t, dt;
	char yn;
public:
	sessions();
	void calc(int s, int b, int bb, int psy, double t, double dt, char yn);
	double time(int s, int b, int bb);
	double pf(int a);
};

