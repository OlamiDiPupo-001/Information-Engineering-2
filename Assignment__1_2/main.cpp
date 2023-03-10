#include <iostream>
using namespace std;

class Complex {
    double real_part;
    double imaginary_part;
public:
    Complex(double re=0, double im=0) : real_part(re), imaginary_part(im) {} // Constructor

    void set_re(double re) {
        real_part = re;
    }
    double get_real_part() const {
        return real_part;
    }

    void set_im(double im) {
        imaginary_part = im;
    }
    double get_imaginary_part() const {
        return imaginary_part;
    }



    //To display the number in readable format
    void print() const {
        cout << real_part;
        if (imaginary_part > 0) cout << "+";
        if (imaginary_part != 0) cout << imaginary_part << "i";
        cout << endl;
    }

    //To add complex or real number to the current one
    Complex add(const Complex& z) const {

        return Complex(real_part + z.real_part, imaginary_part + z.imaginary_part);

    }
    Complex add(double r) const {

        return Complex(real_part + r, imaginary_part);

    }
};



int main() {

    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i

    return 0;
}
