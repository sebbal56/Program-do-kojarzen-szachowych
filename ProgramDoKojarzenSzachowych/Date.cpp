#include "Date.h"



std::string Date::writeDate()
{
    return  std::to_string(day) + '-' + std::to_string(month) + '-' + std::to_string(year);
}

int Date::compare(const Date& pattern) const
{
	// jezeli this jest starsze niz pattern return - 1
	if (this->year > pattern.year) return -1;
	if (this->year < pattern.year) return 1;
	if (this->month > pattern.month) return -1;
	if (this->month < pattern.month) return 1;
	if (this->day > pattern.day) return -1;
	if (this->day < pattern.day) return 1;
	return 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

Date::Date(wxString d, wxString m, wxString y) {
	day = std::stoi(d.ToStdString()); 
	month = std::stoi(m.ToStdString());
	year = std::stoi(y.ToStdString());
}

Date::Date(std::string line){
	size_t start = 0, end = 0;

	end = line.find('-', start);
	day = std::stoi(line.substr(start, end - start));
	start = end + 1;

	end = line.find('-', start);
	month = std::stoi(line.substr(start, end - start));
	start = end + 1;

	year = std::stoi(line.substr(start));
}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}

