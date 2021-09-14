#include <iostream>
#include <iomanip> // for std::setprecision()
using namespace std;

int main()
{
    int nDay{0};
    int nMonth{0};
    int nYear{0};

    // thông báo yêu cầu user nhập ngày, tháng, năm sinh
    cout << "Enter your birthday: ";

    // đọc giá trị từ console và lưu vào biến nDay, nMonth, nYear
    cin >> nDay >> nMonth >> nYear;

    // in 3 giá trị vừa nhập lên màn hình
    cout << "Your birthday: " << nDay << "/" << nMonth << "/" << nYear << endl;
    return 0;
}