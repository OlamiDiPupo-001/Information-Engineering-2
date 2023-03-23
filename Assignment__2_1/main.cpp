#include <iostream>
#include "Time.hpp"

using namespace std;

int main()
{

    Time t1(200);
    cout << t1 << endl;

    cout << "\n";

    Time t2;
    cout << "Enter a time in format of (hh:mm:ss)";
    cin >> t2;

    Time t3;
    t3 = t2 - t1;
    cout << t3 << endl;

    int t3s = t3.toSeconds();
    cout << "t3 in seconds = " << t3s;


    return 0;
}
