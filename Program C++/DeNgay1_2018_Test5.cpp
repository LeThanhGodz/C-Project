#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class SINHVIEN
{
    char maSV[10];
    char tenSV[30];
    char lop[10];
    int khoa;
public:
    void nhap();
    void xuat();
};

class DIEM
{
    char tenmon[20];
    int sotrinh;
    float diem;
public:
    void nhap();
    void xuat();
    friend float DTB(DIEM *a, int n);
};

class PHIEU
{
    SINHVIEN x;
    DIEM *ds;
    int n;
public:
    void nhap();
    void xuat();
};
void SINHVIEN::nhap()
{
    cout << "Ma sinh vien:";
    fflush(stdin);
    gets(maSV);
    cout << "Ten sinh vien:";
    fflush(stdin);
    gets(tenSV);
    cout << "Lop:";
    fflush(stdin);
    gets(lop);
    cout << "Khoa:";
    cin >> khoa;
}

void SINHVIEN::xuat()
{
    cout << "Ma sinh vien:";
    cout << setw(15) << left << maSV;
    cout << "Ten Sinh Vien:";
    cout << setw(15) << left << tenSV;
    cout << endl;
    cout << "Lop:";
    cout << setw(15) << left << lop;
    cout << "Khoa:";
    cout << setw(15) << left << khoa;
}

void DIEM::nhap()
{
    cout << "Ten mon:";
    fflush(stdin);
    gets(tenmon);
    cout << "So trinh:";
    cin >> sotrinh;
    cout << "Diem:";
    cin >> diem;
}
void DIEM::xuat()
{
    cout << setw(15) << left << tenmon;
    cout << "|" << setw(15) << left << sotrinh;
    cout << "|" << setw(15) << left << diem;
    cout << "|";
    cout << endl;
}

float DTB(DIEM *a, int n)
{
    float s=0;
    for(int i=0;i<n;i++)
    {
        s+=(a[i].diem*a[i].sotrinh);
    }
    int dem=0;
    for(int i=0;i<n;i++)
    {
        dem+=a[i].sotrinh;
    }
    return  s/ float(dem);;
}

void PHIEU::nhap()
{
    x.nhap();
    cout << "Nhap so mon :";
    cin >> n;
    ds = new DIEM[n];
    int i=0;
    for(i;i<n;i++)
    {
        ds[i].nhap();
        cout << "----------------\n";
    }
}

void PHIEU::xuat()
{
    cout << "==========================PHIEU BAO DIEM==========================\n";
    x.xuat();
    cout << endl;
    cout << "BANG DIEM:\n";
    cout << "-------------------------------------------------------------------\n";
    cout << setw(15) << left << "Tenmon";
    cout << "|" << setw(15) << left << "So trinh";
    cout << "|" << setw(15) << left << "Diem";
    cout << "|";
     cout << "\n-------------------------------------------------------------------\n";
    for(int i=0;i<n;i++)
    {
        ds[i].xuat();
         cout << "-------------------------------------------------------------------\n";
    }
    cout << setw(15) << " ";
    cout << setw(15) << "Diem trung binh:";
    cout << setw(15) << setprecision(3) << DTB(ds,n) ;
}

int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();
    return 0;
}