#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int a[], int first, int last)
{
    int pivot = a[last];
    int left = first;
    int right = last - 1;
    while (true)
    {
        while (left <= right && a[left] < pivot)
            left++;
        while (right >= left && a[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[last]);
    return left;
}
void quickSort(int a[], int first, int last)
{
    if (first < last)
    {
        int pi = partition(a, first, last);
        quickSort(a, first, pi - 1);
        quickSort(a, pi + 1, last);
    }
}
int main()
{
    int n, a[100];
    cin >> n;
    int length = sizeof(a) / sizeof(a[1]);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quickSort(a, 1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}