#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pi  2*acos (0.0)


int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        double rad;
        cin>>rad;
        double aCircle=pi*rad*rad;
        double aSquare=(rad*2)*(rad*2);
        printf("Case %d: %.2lf\n",t,(aSquare-aCircle)+10e-9);
    }
    return 0;
}

