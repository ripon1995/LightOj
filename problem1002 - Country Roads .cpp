#include<bits/stdc++.h>
using namespace std;

#define infinity 1000000000
#define LIM 10000

struct Node
{
    int u,cost;
    Node(int temp_u,int temp_cost)
    {
        u=temp_u;
        cost=temp_cost;
    }
};


bool operator <(Node A,Node B)
{
    return A.cost>B.cost;
}

void addEdge(vector<int>graph[],vector<int>cost[],int node1,int node2,int costs)
{
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
    cost[node1].push_back(costs);
    cost[node2].push_back(costs);
}


void dijkstra(vector<int>graph[],vector<int>cost[],int totalNode,int source,vector<int>&distance)
{
    //int distance[totalNode];///because 1 theke counting start


    //for(int i=1;i<=totalNode;i++)distance[i]=infinity;

    priority_queue<Node>pq;

    pq.push(Node(source,0));
    distance[source]=0;

    while(!pq.empty())
    {
        Node top=pq.top();
        pq.pop();

        int u=top.u;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(max(distance[u],cost[u][i])<distance[v])
            {
                distance[v]=max(distance[u],cost[u][i]);
                pq.push(Node(v,distance[v]));
            }
        }
    }

    /*for(int i=0;i<totalNode;i++)
    {
        cout<<source<<" --> "<<i<<" "<<distance[i]<<endl;
    }*/



}


void shortestPath(vector<int>prev,int destination)
{
    vector<int>path;
    for(int i=destination;i!=-1;i=prev[i])path.push_back(i);
    reverse(path.begin(),path.end());
    cout<<"Path:  ";
    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";

}


int main()
{

    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int nodes,edges;
        cin>>nodes>>edges;
        vector<int>graph[LIM],cost[LIM];
        for(int i=0;i<edges;i++)
        {
            int node1,node2,costs;///cost or weight
            cin>>node1>>node2>>costs;
            addEdge(graph,cost,node1,node2,costs);
        }
        vector<int>prev(nodes+1,-1);
        vector<int>distance(nodes,infinity);
        int source;
        cin>>source;
        dijkstra(graph,cost,nodes,source,distance);

        cout<<"Case "<<t<<":"<<endl;
        for(int i=0;i<distance.size();i++)
        {
            if(distance[i]!=infinity)cout<<distance[i]<<endl;
            else cout<<"Impossible"<<endl;
        }
    }




    //shortestPath(prev,nodes);
    return 0;
}

