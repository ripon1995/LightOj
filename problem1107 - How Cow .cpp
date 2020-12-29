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
        int x1,x2,y1,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x3>>y3;
        x2=x1;x4=x3;
        y2=y3;y4=y1;

        int m;
        cin>>m;
        cout<<"Case "<<t<<":"<<endl;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            if((x>x1&&x<x3) && (y>y1 && y<y3))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}

