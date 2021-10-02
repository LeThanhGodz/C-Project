#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Nhap vao ba so nguyen: ";
    cin >> a >> b >> c;

    if(a == b && b == c)
    {
        cout << "Khong co gia tri max" << endl;
    }
    else
    {
        int max = a;
        if(b > max);{
            max = b;
    }
    if(c > max)
    {
        max = c;
    }
    cout << "Gia Tri Max = " << max << endl;

    }
}