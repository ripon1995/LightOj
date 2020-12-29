#include<bits/stdc++.h>
using namespace std;

bool rightAngleTriangle(int arr[])
{
    return (arr[0]*arr[0])+(arr[1]*arr[1])==arr[2]*arr[2];
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int arr[3];
        scanf("%d %d %d", &arr[0],&arr[1],&arr[2]);
        sort(arr,arr+3);
        cout<<"Case "<<t<<": ";
        if(rightAngleTriangle(arr))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}

