#include<bits/stdc++.h>
using namespace std;

int liftIsOnHigherFloor(int value2)
{
    return (4*value2)+19;
}

int liftIsOnLowerFloor(int value1,int value2)
{
    return (((value1-value2)+value1)*4)+19;
}
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int value1,value2;
        cin>>value1>>value2;
        int result;
        if(value1>value2)result=liftIsOnLowerFloor(value1,value2);
        else result=liftIsOnHigherFloor(value2);
        cout<<"Case "<<t<<": "<<result<<endl;
    }
    return 0;
}

