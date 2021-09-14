#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
     ("TAMGIAC.INP");
     ("TAMGIAC.OUT");

    float xA, xB, xC, xM, yA, yB, yC, yM;
    cin >> xA >> yA >> xB >> yB >> xC >> yC >> xM >> yM;

    float ab = sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
    float ac = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
    float bc = sqrt((xB - xC) * (xB - xC) + (yB - yC) * (yB - yC));

    float p = (ab + ac + bc) / 2;
    float s = sqrt(p * (p - ab) * (p - ac) * (p - bc));

    cout << fixed << setprecision(2) << s;
    return 0;
}