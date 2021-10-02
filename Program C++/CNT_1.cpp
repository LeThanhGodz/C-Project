#include<bits/stdc++.h>
#include<conio.h>

using namespace std;
class HangHoa;
class OTO;
class NhaSX
{
    char Ten_NSX[30];
    char DiaChi[30];
public:
    friend class HangHoa;
    friend void HonDa(OTO *a, int n);
};

class HangHoa
{
protected:
    char NhanHieu[15];
    NhaSX x;
public:
    void nhap();
    void xuat();
};

class OTO:HangHoa
{
    int TrongTai;
    int SoGhe;
    float GiaThanh;
public:
    void nhap();
    void xuat();
    friend void HonDa(OTO *a, int n);
    friend void Sapxeptang(OTO *a, int n);
    friend void Xoa(OTO *a, int &n);
};
void HangHoa::nhap()
{
    cout << "Nhan Hieu:";
    fflush(stdin);
    gets(NhanHieu);
    cout << "Ten NSX:";
    fflush(stdin);
    gets(x.Ten_NSX);
    cout << "Dia Chi:";
    fflush(stdin);
    gets(x.DiaChi);
}

void HangHoa::xuat()
{
    cout << setw(15) << left << NhanHieu;
    cout << setw(15) << left << x.Ten_NSX;
    cout << setw(15) << left << x.DiaChi;
}

void OTO::nhap()
{
    HangHoa::nhap();
    cout << "Trong Tai:";
    cin >> TrongTai;
    cout << "So ghe:";
    cin >> SoGhe;
    cout << "Gia thanh:";
    cin >> GiaThanh;
}

void OTO::xuat()
{
    HangHoa::xuat();
    cout << setw(15) << left << TrongTai;
    cout << setw(15) << left << SoGhe;
    cout << setw(15) << left << GiaThanh;
}

void HonDa(OTO *a, int n)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].x.Ten_NSX,"HONDA")==0)
        {
            a[i].xuat();
            cout << endl;
        }
    }
}

void Sapxeptang(OTO *a, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        if(a[i].GiaThanh > a[j].GiaThanh)
        {
            OTO temp = a[i];
                a[i] = a[j];
                a[j] = temp;
        }
    }
}

void Xoa(OTO *a, int &n)
{
     for(int i=n-1;i>=0;i--){
 	   if(strcmp(a[i].NhanHieu,"OUTLANDER")==0)
 	   {
 	   	  for(int j = i;j<n;j++)
 	   	     a[j] = a[j+1];
 	   	   n--;
		}
	 }
}
int main()
{
    int n,i;
    cout << "Nhap N:";
    cin >> n;
    OTO *ds = new OTO[n];
    for(i=0;i<n;i++)
    {
        ds[i].nhap();
        cout << "------------------\n";
    }
    cout << "Danh sach OTO  vua nhap:\n";
    cout << setw(15) << left << "Nhan Hieu";
    cout << setw(15) << left << "Ten NSX";
    cout << setw(15) << left << "Dia chi";
    cout << setw(15) << left << "Trong Tai";
    cout << setw(15) << left << "So Ghe";
    cout << setw(15) << left << "Gia Thanh";
    cout << endl;
    for(i=0;i<n;i++)
    {
        ds[i].xuat();
        cout << endl;
    }
    cout << "Danh sach OTO cua hang HONDA:\n";
    cout << setw(15) << left << "Nhan Hieu";
    cout << setw(15) << left << "Ten NSX";
    cout << setw(15) << left << "Dia chi";
    cout << setw(15) << left << "Trong Tai";
    cout << setw(15) << left << "So Ghe";
    cout << setw(15) << left << "Gia Thanh";
    cout << endl;
    HonDa(ds,n);
    cout << "Danh sach OTO sap xep:\n";
    cout << setw(15) << left << "Nhan Hieu";
    cout << setw(15) << left << "Ten NSX";
    cout << setw(15) << left << "Dia chi";
    cout << setw(15) << left << "Trong Tai";
    cout << setw(15) << left << "So Ghe";
    cout << setw(15) << left << "Gia Thanh";
    cout << endl;
    Sapxeptang(ds,n);
    for(i=0;i<n;i++)
    {
        ds[i].xuat();
        cout << endl;
    }
    cout << "Danh sach OTO  sau khi xoa:\n";
    cout << setw(15) << left << "Nhan Hieu";
    cout << setw(15) << left << "Ten NSX";
    cout << setw(15) << left << "Dia chi";
    cout << setw(15) << left << "Trong Tai";
    cout << setw(15) << left << "So Ghe";
    cout << setw(15) << left << "Gia Thanh";
    cout << endl;
    Xoa(ds,n);
    for(i=0;i<n;i++)
    {
        ds[i].xuat();
        cout << endl;
    }
    return 0;

}