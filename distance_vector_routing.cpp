#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#define INF 999
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>>cost,int n)
{
    for (int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][k]+cost[k][j]<cost[i][j])
                {
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
    return cost;
}

void addConnection(vector<vector<int>>&topology,int u,int v)
{
    topology[u][v]=1;
    topology[v][u]=1;
}

void Print(vector<vector<int>>cost,int n)
{
    char names[n];
    for(int i=0;i<n;i++)
    {
        names[i]=i+'A';
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Router table of Router "<<names[i]<<" :"<<endl;
        cout<<"_______________"<<endl;
        cout<<"router|hopcount"<<endl;
        for(int j=0;j<n;j++)
        {
            if((i!=j)&&(cost[i][j]!=INF))
            {
                cout<<names[j]<<"     |"<<cost[i][j]<<endl;
            }
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Enter number of routers:  "<<endl;
    int n;
    cin>>n;
    vector<vector<int>>topology(n,vector<int>(n,INF));
    for(int i=0;i<n;i++)topology[i][i]=0;
    char names[n];
    for(int i=0;i<n;i++)
    {
        names[i]=i+'A';
    }
    int x;
    for(int i=0;i<n;i++)
    {
        while(true)
        {
            cout<<"Enter routers to which router "<<names[i]<<" is connected to or enter -1 to stop"<<endl;
            cin>>x;
            if(x==-1)break;
            addConnection(topology,i,x);
        }
        
    }
    addConnection(topology,0,1);
    addConnection(topology,0,2);
    addConnection(topology,2,3);
    addConnection(topology,2,4);

    vector<vector<int>>cost=floydWarshall(topology,n);
    Print(cost,n);
    return 0;
}