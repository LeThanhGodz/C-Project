#include <iostream>
using namespace std;

int main()
{
    cout << std::boolalpha; // in "true" hoặc "false" với kiểu bool
    cout << true << endl;   // in "true" ra màn hình
    cout << false << endl;  // in "false" ra màn hình

    cout << std::noboolalpha; // in 1 hoặc 0 với kiểu bool
    cout << true << endl;     // in 1 ra màn hình
    cout << false << endl;    // in 0 ra màn hình

    return 0;
}
