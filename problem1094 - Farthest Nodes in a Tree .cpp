///Very important thing is that the algorithm to find the farthest node is double dfs/bfs. Both can be used.
///Firstly we can traverse from any starting vertex. And we will get a maximum value;
///Now for this maximum value we will get the vertex.

///And for the second traverse this vertex will be the source



#include<bits/stdc++.h>
using namespace std;

#define LIM 30010
void addEdge(vector<int>adj[],vector<int>cost[],int node1,int node2,int costs)
{
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
    cost[node1].push_back(costs);
    cost[node2].push_back(costs);
}



long long int dfs(vector<int>adj[],vector<int>cost[],int nodes,int visited[],int source)
{
   stack<int>S;
   S.push(source);
   long long int distance[nodes];
   long long int maxDistance=0;
   int localAddress=0;
   memset(distance,0,sizeof(distance));
   while(!S.empty())
   {
       int now=S.top();
       S.pop();

       if(!visited[now])
       {
           //cout<<now<<" ";
           visited[now]=true;
       }

       for(int i=0;i<adj[now].size();i++)
       {
           if(!visited[adj[now][i]])
           {
                S.push(adj[now][i]);
                distance[adj[now][i]]=cost[now][i]+distance[now];
                if(distance[adj[now][i]]>maxDistance) localAddress=adj[now][i];
                maxDistance=max(distance[adj[now][i]],maxDistance);
           }
       }
   }
    if(source==0)return localAddress;
    return maxDistance;
}


void printGraph(vector<int>adj[],int nodes)
{
    for(int i=0;i<nodes;i++)
    {
        cout<<i<<" ";
        for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{

    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        vector<int> adj[LIM];
        vector<int>cost[LIM];
        int nodes;
        cin>>nodes;
        int node1,node2,costs;
        int visited[nodes];

        for(int i=1;i<nodes;i++)
        {
            cin>>node1>>node2>>costs;
            addEdge(adj,cost,node1,node2,costs);
        }

        long long int dis=0;
         memset(visited,0,sizeof(visited));
          dis=dfs(adj,cost,nodes,visited,0);///from this call we will get the vertex which has maximum distance

          memset(visited,0,sizeof(visited));
          dis=dfs(adj,cost,nodes,visited,dis);///from this call we will get the farthest node

        cout<<"Case "<<t<<": "<<dis<<endl;
    }
	return 0;
}

