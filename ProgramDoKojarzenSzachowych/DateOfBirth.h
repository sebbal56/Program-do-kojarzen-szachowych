#pragma once
#include <iostream>

class DateOfBirth
{
	int day;
	int month;
	int year;
public:
	void setDate();
	void writeDate();
	int compare(const DateOfBirth& pattern) const;
	DateOfBirth(int d, int m, int y);
	DateOfBirth() = default;
};

