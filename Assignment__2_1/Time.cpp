#include "Time.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {

}
Time::Time(int s) : hours(s/3600), minutes((s/60)%60), seconds(s%60){

}
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    if(h)
        hours=h;
    if(m)
        minutes=m;
    if(s)
        seconds=s;
}

int Time::toSeconds()const {
    return (hours*3600) + (minutes*60) + seconds;
}

void Time::fromSeconds(int s) {
    hours = s / 3600;
    minutes = (s / 60) % 60;
    seconds = s % 60;
}

Time operator+(const Time& lhs, const Time& rhs) {
    int totalSeconds = lhs.toSeconds() + rhs.toSeconds();
    return Time(totalSeconds);
}

Time operator-(const Time& lhs, const Time& rhs) {
    int totalSeconds = lhs.toSeconds() - rhs.toSeconds();
    return Time(totalSeconds);
}

Time operator*(const Time& time, int scalar) {
    int totalSeconds = time.toSeconds() * scalar;
    return Time(totalSeconds);
}



std::istream& operator>>(std::istream& is, Time& time) {
    string input;
    getline(is, input);

    stringstream ss(input);

    int h = 0, m = 0, s = 0;
    char colon;

    ss >> h >> colon >> m >> colon >> s;

    time = Time(h, m, s);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << std::setfill('0') << std::setw(2) << time.hours << "h:"
       << std::setw(2) << time.minutes << "m:"
       << std::setw(2) << time.seconds << "s";
    return os;
}

Time::operator int() const {
    return toSeconds();
}
