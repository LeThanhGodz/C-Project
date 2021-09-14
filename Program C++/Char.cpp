#include <iostream>
using namespace std;

int main()
{
    int n, i;
    char a [100000];

    cout <<"Nhap N: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap A:" << i << " ";
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++ )
    {
        cout << "KQ: " << a[i] << "\n" ;
    }
}