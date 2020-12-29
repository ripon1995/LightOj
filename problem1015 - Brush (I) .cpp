#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;
        int dust=0;
        for(int i=1;i<=n;i++)
        {
            int value;
            cin>>value;
            if(value>0)dust+=value;
        }
        cout<<"Case "<<t<<": "<<dust<<endl;
    }
    return 0;
}

