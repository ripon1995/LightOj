#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#define  pii 3.141592653589

using namespace std;

void binarySearch(double lo,double high,double R,double n)
{
    double tempr;
    int counter=100;
    while(counter--)
    {

        tempr=(lo+high)/2.0;
        double tempN=tempr/(R-tempr);
        if(tempN>n)high=tempr;
        else if(tempN<n)lo=tempr;
    }
    cout<<setprecision(10)<<fixed<<tempr<<"\n";
}


int main()
{
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++)
    {
        double R,n;
        scanf("%lf %lf", &R,&n);
        printf("Case %d: ",t);
        binarySearch(0.0,R,R,sin(pii/n));
    }
    return 0;
}

