#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>

using namespace std;

vector<vector<int>> djiktras(vector<vector<pair<int,int>>>&graph,int n,int u)
{
    
    vector<bool>visited(n,false);
    vector<int>min_dis(n,INT_MAX);
    vector<vector<int>>min_path(n);
    for(int i=0;i<n;i++)
    {
        vector<int>tmp_path;
        tmp_path.push_back(i);
        min_path[i]=tmp_path;
    }
   // visited[u]=true;
    min_dis[u]=0;
    visited[0]=true;
    int v;int min_dis_v;

    while(true)
    {
        //cout<<"while entered"<<endl;
        bool all_visited=true;
        min_dis_v=INT_MAX;
        v=1;
        //check for min_dis
        
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i]){
                //cout<<"!visited"<<endl;
                all_visited=false;
                //if(i==1)cout<<min_dis[v]<<"  "<<min_dis_v<<endl;
                if(min_dis[i]<min_dis_v)
                {
                    //cout<<"updating mindis"<<endl;
                    min_dis_v=min_dis[i];
                    v=i;
                }
            }
            
        }
        // cout<<"visited"<<endl;
        // for(int i=0;i<n;i++)cout<<visited[i]<<"  ";
        // cout<<endl;
        if(all_visited){//cout<<"allvisited"<<endl;
        break;}
        //cout<<"v:"<<v<<endl;
        visited[v]=true;
        //update neigbours
        
        for(auto it=graph[v].begin();it!=graph[v].end();it++)
        {
            //cout<<it->first<<"  ";
            if(min_dis[it->first]>(min_dis[v]+it->second))
            {
                min_dis[it->first]=min_dis[v]+it->second;
                min_path[it->first]=min_path[v];
                min_path[it->first].push_back(it->first);
            }
        }
        // cout<<endl;
        // //display mindis
        // for(int i=0;i<n;i++)
        // {
        //     if(min_dis[i]==INT_MAX)cout<<"oo"<<"  ";
        //     else cout<<min_dis[i]<<"  ";
        // }cout<<endl;

        // //displaying minpath
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<"=>  ";
        //     for(auto it=min_path[i].begin();it!=min_path[i].end();it++)
        //     {
        //         cout<<*it<<" ->";
        //     }
        //     cout<<endl;
        // }cout<<endl;
        
    }

    // cout<<endl;
    // cout<<"Final"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     if(min_dis[i]==INT_MAX)cout<<"oo"<<"  ";
    //     else cout<<min_dis[i]<<"  ";
    // }cout<<endl;

    return min_path;

}


void PrintMinPath(vector<vector<int>>min_path,int u,int n)
{
    cout<<"shortest path from"<<endl; 
    for(int i=1;i<n;i++)
    {
        cout<<"router "<<u<<" to router "<<i<<" is: ";
        for(auto it=min_path[i].begin();it!=min_path[i].end();it++)
        {
            cout<<*it<<"->";
        }
        cout<<endl;
    }
}

void addConnection(vector<vector<pair<int,int>>>&topology,int u,int v,int cost)
{
    topology[u].push_back({v,cost});
    topology[v].push_back({u,cost});
}


int main()
{
    int n=7;
    // cout<<"Enter the number of routers: ";
    // cin>>n;
    vector<vector<pair<int,int>>>topology(n);
    addConnection(topology,1,2,1);
    addConnection(topology,2,3,2);
    addConnection(topology,3,4,6);
    addConnection(topology,3,5,3);
    addConnection(topology,4,5,8);
    addConnection(topology,5,6,9);
    addConnection(topology,6,2,3);
    addConnection(topology,1,6,8);

    
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<" -> ";
    //     for(auto it=topology[i].begin();it!=topology[i].end();it++)
    //     {
    //         cout<<it->first<<","<<it->second<<"   ";
    //     }cout<<endl;
    // }
    vector<vector<int>>min_path=djiktras(topology,n,1);
    PrintMinPath(min_path,1,n);
}