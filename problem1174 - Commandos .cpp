#include<bits/stdc++.h>
#define LIM 10005
#define lli long long int
using namespace std;



void addEdge(vector<int>adj[],int node1,int node2)
{
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
}

void BFS(vector<int>adj[],int node,int source,vector<int>&lev)
{

   int visited[node];memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(source);


    lev[source]=0;
    visited[source]=1;

    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++)
        {
            int v=adj[now][i];
            if(visited[v]==0 && v != source)
            {
                visited[v]=1;
                q.push(v);
                lev[v]=lev[now]+1;
            }
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        vector<int>adj[LIM];
        int n,r,building1,building2;
        cin>>n>>r;
        for(int j=1;j<=r;j++)
        {
            cin>>building1>>building2;
            addEdge(adj,building1,building2);
        }
        int source,destination;
        cin>>source>>destination;
        vector<int>dis1(n,0);
        vector<int>dis2(n,0);
        BFS(adj,n,source,dis1);
        BFS(adj,n,destination,dis2);
        int maximum=0;
        for(int j=0;j<n;j++)
        {
            maximum=max(maximum,(dis1[j]+dis2[j]));
        }
        printf("Case %d: %d\n", i,maximum);
    }
    return 0;
}
