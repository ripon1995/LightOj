#include<bits/stdc++.h>
using namespace std;

#define infinity 10e18
#define LIM 10005
#define lli long long int



struct Node
{
    lli u,cost;
    Node(lli temp_u,lli temp_cost)
    {
        u=temp_u;
        cost=temp_cost;
    }
};


bool operator <(Node A,Node B)
{
    return A.cost>B.cost;
}

void addEdge(vector<lli>graph[],vector<lli>cost[],lli node1,lli node2,lli costs)
{
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
    cost[node1].push_back(costs);
    cost[node2].push_back(costs);
}

bool shortestPath2(vector<lli>prev,lli destination)
{
      if(prev[destination]==-1)return false;
      else return true;
}



void dijkstra(vector<lli>graph[],vector<lli>cost[],lli totalNode,lli source,vector<lli>&prev)
{
    lli distance[totalNode+1];///because 1 theke counting start

    for(lli i=1;i<=totalNode;i++)distance[i]=infinity;

    priority_queue<Node>pq;

    pq.push(Node(source,0));
    distance[source]=0;

    while(!pq.empty())
    {
        Node top=pq.top();
        pq.pop();

        lli u=top.u;
        for(lli i=0;i<graph[u].size();i++)
        {
            lli v=graph[u][i];
            if(distance[u]+cost[u][i]<distance[v])
            {
                distance[v]=distance[u]+cost[u][i];
                pq.push(Node(v,distance[v]));
                prev[graph[u][i]]=u;
            }
        }
    }

    if(shortestPath2(prev,totalNode))cout<<distance[totalNode]<<endl;
    else cout<<"Impossible"<<endl;
}

int main()
{
    lli nodes,edges;
    int tc;
    cin>>tc;
    for(int j=1;j<=tc;j++)

    {
        cin>>nodes>>edges;
        vector<lli>graph[LIM],cost[LIM];
        for(lli i=0;i<edges;i++)
        {
            lli node1,node2,costs;///cost or weight
            cin>>node1>>node2>>costs;
            addEdge(graph,cost,node1,node2,costs);
        }
        vector<lli>prev(nodes+1,-1);
        cout<<"Case "<<j<<": ";
        dijkstra(graph,cost,nodes,1,prev);
        //shortestPath(prev,nodes);
    }

    return 0;
}

