#pragma once
#include <iostream>

class Date{
	int day;
	int month;
	int year;
public:
	void setDate();
	void writeDate();
	int compare(const Date& pattern) const;
	Date(int d, int m, int y);
	Date() = default;
};

