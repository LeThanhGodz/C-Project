#include <iostream> 
#include <iomanip>
using namespace std;
 
int main() 
{
   int arr[10000];
   int a, i, total = 0, n;

    cout << "Nhap N";
    cin >> n;

    for(i=1; i<n; i++)
    {
        cout << "Nhap A" << "["<< i <<"]";
        cin >> a[i];
    }

   // tinh tong gia tri cua mang
   for(i = 1; i < n; i++) {
      total = total + arr[i];
    }
   // in tong gia tri cua mang ra man hinh
   printf("Tong cac gia tri cua mang la: %d ", total);
   return 0;
}