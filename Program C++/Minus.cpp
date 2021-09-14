#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cout << "Nhap so thu nhat: ";
    cin >> n1;

    cout << "Nhap so thu hai: ";
    cin >> n2;

    if (n1 < 0)
        {
                    cout << "Vui long nhap so >= 0";
        }
    else if (n2 < 0)
        {
                    cout << "Vui long nhap so >= 0";
        }
    else
        {
            cout << n1 << " - " << n2 << " = " << n1 - n2;
        }
}