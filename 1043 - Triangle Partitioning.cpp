#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>

using namespace std;


double areaOfTriangle(double first,double second,double third)
{
    double s=(first+second+third)/2.0;
    return sqrt(s*(s-first)*(s-second)*(s-third));
}



void binarySearch1(double lowAB1,double highAB2,double lowAC1,double highAC2,double lowBC1,double highBC2,double rat,double totalArea)
{

    double ad;
    int counter=100;
    while(counter--)
    {
        ad=(lowAB1+highAB2)/2.0;
        double ae=(lowAC1+highAC2)/2.0;
        double de=(lowBC1+highBC2)/2.0;
        double area=areaOfTriangle(ad,ae,de);
        double tempRat=area/(totalArea-area);
        if(tempRat>rat)
        {
            highAB2=ad;
            highAC2=ae;
            highBC2=de;
        }
        else if(tempRat<rat)
        {
            lowAB1=ad;
            lowAC1=ae;
            lowBC1=de;
        }
    }
    cout<<setprecision(10)<<fixed<<ad;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++)
    {
        double first,second,third,rat;
        scanf("%lf %lf %lf %lf", &first,&second,&third,&rat);
        double totalArea=areaOfTriangle(first,second,third);
        printf("Case %d: ",t);
        binarySearch1(0.0,first,0.0,second,0.0,third,rat,totalArea);
        printf("\n");
    }
    return 0;
}

