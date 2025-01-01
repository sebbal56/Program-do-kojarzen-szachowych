#pragma once
#include <iostream>
#include <string>

class Date{
	int day;
	int month;
	int year;
public:
	void setDate();
	std::string writeDate();
	int compare(const Date& pattern) const;
	Date(int d, int m, int y);
	Date() = default;
};

