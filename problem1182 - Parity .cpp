#include<bits/stdc++.h>
using namespace std;
#define lli long long int

bool parity(lli num)
{
    int counter=0;
    while(num>0)
    {
        counter+=num%2;
        num/=2;

    }
    if(counter%2==0)return true;
    return false;
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        lli num;
        cin>>num;
        if(!parity(num))cout<<"Case "<<t<<": odd"<<endl;
        else cout<<"Case "<<t<<": even"<<endl;
    }
    return 0;
}

