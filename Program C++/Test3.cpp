#include <iostream>
#include <fstream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int a[], int l, int r)
{
    int i = l, j = r;
    int mid = a[(l + r) / 2];

    while (i <= j)
    {
        while (a[i] < mid)
        {
            i++;
        }
        while (a[j] > mid)
        {
            j--;
        }

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j)
    {
        quicksort(a, l, j);
    }
    if (r < i)
    {
        quicksort(a, i, r);
    }
}

int main(int argc, char const *argv[])
{
    ifstream f("XEPCAY.INP");
    ofstream g("XEPCAY.OUT");

    int n, x, a[10000];

    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> a[i];
    }
    f >> x;

    quicksort(a, 1, n);

    for (int i = 1; i <= n; i++)
    {
        g << a[i] << " ";
    }

    return 0;
}