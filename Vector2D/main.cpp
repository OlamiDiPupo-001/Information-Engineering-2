#include <iostream>

class Vector2D {
public:
    Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    double operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

private:
    double x, y;
};

int main() {
    Vector2D vec1(3.0, 4.0);
    Vector2D vec2(1.0, 2.0);

    std::cout << "Vector 1: " << vec1 << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;

    Vector2D sum = vec1 + vec2;
    std::cout << "Sum: " << sum << std::endl;

    Vector2D difference = vec1 - vec2;
    std::cout << "Difference: " << difference << std::endl;

    double dotProduct = vec1 * vec2;
    std::cout << "Dot product: " << dotProduct << std::endl;

    bool areEqual = vec1 == vec2;
    std::cout << "Are equal? " << (areEqual ? "Yes" : "No") << std::endl;

    return 0;
}
