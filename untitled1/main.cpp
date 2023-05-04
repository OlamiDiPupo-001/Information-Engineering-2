#include <iostream>

using namespace std;
class Complex{
private:
    int real_part;
    int imag_part;
public:
    Complex(int r_p = 0, int i_p = 0):real_part(r_p),imag_part(i_p){};

    void setim(int r_p){
        real_part = r_p;
    }
    void setip(int i_p){
        imag_part = i_p;
    }

    int getim(){
        return real_part;
    }
    int getip(){
        return imag_part;
    }


    void print(){
        cout<<real_part;
        if(imag_part>0) cout<<"+"<<imag_part<<"i";
        else cout<<imag_part<<"i"<<endl;
    }
    Complex add(Complex x) {
        return Complex(real_part + x.real_part , imag_part + x.imag_part);
    }
    Complex add(int v) {
        return Complex(real_part + v, imag_part + v);
    }
};

int main()
{
    Complex a(1.0, -2); // creates 1-2i
    Complex b(3); // creates 3

    b.add(-5);

    Complex c = a.add(b);

    c.print(); // prints 4-7i

    return 0;
}
