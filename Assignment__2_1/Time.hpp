#pragma once

#include <iostream>
#include <string>

class Time {
private:
    int hours, minutes, seconds;

public:
    Time();
    Time(int s);
    Time(int h, int m, int s);

    int toSeconds() const;
    void fromSeconds(int s);

    friend Time operator+(const Time& lhs, const Time& rhs);
    friend Time operator-(const Time& lhs, const Time& rhs);
    friend Time operator*(const Time& time, int scalar);


    friend std::istream& operator>>(std::istream& is, Time& time);
    friend std::ostream& operator<<(std::ostream& os, const Time& time);

    operator int() const;
};
