#include <iostream>

class Time {
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0)
        : hours(hours), minutes(minutes), seconds(seconds) {}

    Time operator+(const Time& other) const {
        int total_seconds = seconds + other.seconds;
        int total_minutes = minutes + other.minutes + (total_seconds / 60);
        int total_hours = hours + other.hours + (total_minutes / 60);

        return Time(total_hours % 24, total_minutes % 60, total_seconds % 60);
    }

    Time operator-(const Time& other) const {
        int total_seconds = seconds - other.seconds;
        int total_minutes = minutes - other.minutes - (total_seconds < 0 ? 1 : 0);
        int total_hours = hours - other.hours - (total_minutes < 0 ? 1 : 0);

        total_seconds = (total_seconds + 60) % 60;
        total_minutes = (total_minutes + 60) % 60;
        total_hours = (total_hours + 24) % 24;

        return Time(total_hours, total_minutes, total_seconds);
    }

    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << time.hours << "h " << time.minutes << "m " << time.seconds << "s";
        return os;
    }

private:
    int hours, minutes, seconds;
};

int main() {
    Time time1(3, 15, 45);
    Time time2(1, 50, 30);

    std::cout << "Time 1: " << time1 << std::endl;
    std::cout << "Time 2: " << time2 << std::endl;

    Time sum = time1 + time2;
    std::cout << "Sum: " << sum << std::endl;

    Time difference = time1 - time2;
    std::cout << "Difference: " << difference << std::endl;

    bool areEqual = time1 == time2;
    std::cout << "Are equal? " << (areEqual ? "Yes" : "No") << std::endl;

    return 0;
}
