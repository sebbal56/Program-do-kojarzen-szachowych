#pragma once
//#include <iostream>
#include <string>
#include <wx/string.h>

class Date{
	int day;
	int month;
	int year;
public:
	std::string writeDate();
	int compare(const Date& pattern) const;
	Date(int d, int m, int y);
	Date(wxString d, wxString m, wxString y);
	Date() = default;
	int getDay();
	int getMonth();
	int getYear();
};

