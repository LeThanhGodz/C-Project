#include<iostream>


struct ConNguoi
{
    std::string ho_ten;
    int tuoi;
    float chieu_cao;
    float can_nang;
    int so_do_3_vong[3];
};

std::string chi_so_BMI(ConNguoi nguoi)
{
    float bmi = nguoi.can_nang / (nguoi.chieu_cao * nguoi.chieu_cao);
    std::string ket_qua;
    if (bmi < 18.5)
    {
        ket_qua = "Sao gay qua vay!!!";
    }
    else if (bmi > 25)
    {
        ket_qua = "Bung to lo xo be";
    }
    else
    {
        ket_qua = "Body chuan 6 mui :)";
    }
    return ket_qua;

}

void dong_thoi_gian(ConNguoi nguoi,int nam_troi_qua)
{
    for (int i = 0; i < nam_troi_qua; i = i++)
    {
        nguoi.can_nang = nguoi.can_nang + 2;
    }
    std::string ket_qua = chi_so_BMI(nguoi);
    std::cout << "Ban " << nguoi.ho_ten << nam_troi_qua << " nam troi qua se " << ket_qua << std::endl;
}


int main()
{
    ConNguoi nguoi;
    nguoi.ho_ten = "Le Thanh Godz";
    nguoi.tuoi = 18;
    nguoi.chieu_cao = 1.70;
    nguoi.can_nang = 60;

        std::cout << &nguoi << std::endl;

    system("pause");
    return 0;


}
