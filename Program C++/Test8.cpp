#include<iostream>

using namespace std;

int main()
{
    float a, b;
    cout << "Nhap vao he so a,b: ";
    cin >> a >> b;
    //Giai Phuong Trinh
    if(a==0)
    {
        if(b==0)
        {
            cout << "Phuong trinh vo so nghiem" << endl;
        }
        else 
        {
        cout << "Phuong trinh vo nghiem" << endl;
        }
    }
    else
    {
        float x = -b / a;
        cout << "Nghiem x = " << x << endl;
    }
}