#include<bits/stdc++.h>
using namespace std;


string sum(string str)
{
    string dec;
    int sum=0;
    for(int i=0;i<str.length();i++)
    {
        int a=(int)str[i]-48;
        sum+=(pow(2,(7-i))*a);
    }
    while(sum>0)
    {
        dec.push_back((sum%10)+'0');
        sum=sum/10;
    }
    string f;
    for(int i=dec.length()-1;i>=0;i--)f.push_back(dec[i]);
    if(f.length()==0)f.push_back(0+'0');
    return f;
}


string binaryToDecimal(string binary)
{
    string str1;
    string str2;
    string str3;
    string str4;
    string m;
    for(int i=0;i<binary.length();i++)
    {
        if(i<8)str1.push_back(binary[i]);
        else if(i>=9 && i<=16)str2.push_back(binary[i]);
        else if(i>=18&&i<=25)str3.push_back(binary[i]);
        else if(i>=27)str4.push_back(binary[i]);
    }
    m=sum(str1)+"."+sum(str2)+"."+sum(str3)+"."+sum(str4);
    return m;
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        string str1,str2;
        cin>>str1>>str2;
        string result=binaryToDecimal(str2);
        cout<<"Case "<<t<<": ";
        if(str1==result)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


///00000000.10101000.00000000.11001000

