#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++)
    {
        int stick;
        scanf("%d", &stick);
        vector<int>v;
        for(int i=0;i<stick;i++)
        {
            int valueStick;
            scanf("%d",&valueStick);
            v.push_back(valueStick);
        }
        sort(v.begin(),v.end());
        int triangleCounter=0;
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                int sum=v[i]+v[j];
                triangleCounter+=(lower_bound(v.begin(),v.end(),sum)-v.begin())-j-1;
            }
        }
        printf("Case %d: %d\n", t,triangleCounter);
        v.clear();
    }
    return 0;
}

