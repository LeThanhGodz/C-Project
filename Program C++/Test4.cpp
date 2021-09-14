#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float distance(float x1, float y1, float x2, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
float area(float a1, float a2, float b1, float b2,float c1, float c2)
{
    float p;
    p=(distance(a1,a2,b1,b2)+distance(a1,a2,c1,c2)+distance(b1,b2,c1,c2))/2;
    return sqrt(p*(p-distance(a1,a2,b1,b2))*(p-distance(a1,a2,c1,c2))*(p-distance(b1,b2,c1,c2)));
}
int main(int argc, char const *argv[])
{
    float a1,a2,b1,b2,c1,c2,p,m1,m2;
    cin>>a1>>a2;
    cin>>b1>>b2;
    cin>>c1>>c2;
    cin>>m1>>m2;
    cout<<fixed<<setprecision(2)<<area(a1,b2,b1,b2,c1,c2)<<"\n";
    if (area(m1,m2,b1,b2,c1,c2)+area(m1,m2,a1,a2,b1,b2)+area(m1,m2,a1,a2,c1,c2)>area(a1,a2,b1,b2,c1,c2))
        cout<<"NGOAI";
    else if (area(m1,m2,b1,b2,c1,c2)==0 || area(m1,m2,a1,a2,b1,b2)==0 || area(m1,m2,a1,a2,c1,c2)==0)
        cout<<"NGOAI";
    else cout<<"TRONG";
    return 0;
}