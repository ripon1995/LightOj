#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pi  2*acos (0.0)

bool palindrome(string str)
{
    string now;
    for(int i=str.length()-1;i>=0;i--)
    {
        now.push_back(str[i]);
    }

    for(int i=0;i<str.length();i++)
    {
        if(str[i]==now[i])continue;
        return false;
    }
    return true;
}


int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        string str;
        cin>>str;
        if(palindrome(str))cout<<"Case "<<t<<": Yes"<<endl;
        else cout<<"Case "<<t<<": No"<<endl;
    }
    return 0;
}

