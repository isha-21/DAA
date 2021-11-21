#include<bits/stdc++.h>
using namespace std;
void path(vector<int>&parent,int j)
{
    if(parent[j]==-1){
    cout<<j;
    return;
    }
printf("%d",j);
path(parent,parent[j]);
}

int main()
{
int n,e;
cout<<"enter no of nodes and edges";
cin>>n>>e;
vector<vector<pair<int,int>>> graph(n+1);
for(int i=0;i<e;i++)
{
int s,d,w;
cout<<"Enter source,dest and weight";
cin>>s>>d>>w;
graph[s].push_back({d,w});
graph[d].push_back({s,w});
}
vector<int> arr(n+1,INT_MAX);
set<pair<int,int>> s;
int source;
cout << " Enter source node to find shortest path :";
cin>>source;
arr[source]=0;
s.insert({0,source});
vector<int> parent(n+1,-1);
while(!s.empty()){
auto x=*(s.begin());
s.erase(x);
for(auto it:graph[x.second]){
if(arr[it.first]>arr[x.second]+it.second)
    {s.erase({arr[it.first],it.first});
arr[it.first]=arr[x.second]+it.second;
s.insert({arr[it.first],it.first});
parent[it.first]=x.second;
}
}
}
for(int i=1;i<n+1;i++)
    {path(parent,i);
    cout<<":"<<arr[i]<<endl;
}
return 0;
}

