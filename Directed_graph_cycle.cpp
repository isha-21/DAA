#include<iostream>
#include<bits/stdc++.h>
using namespace std;
set<int>white;
set<int>grey;
set<int>black;
int flag=0;
void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}

void find_cycle(int u,vector<int>adj[]){
    white.erase(u);
    grey.insert(u);
    for(int i=0;i<adj[u].size();i++){
      if(white.find(adj[u][i])!=white.end())
      {
      find_cycle(adj[u][i],adj);
        }
      if(grey.find(adj[u][i])!=grey.end()){
        flag=1;
      }
    }
    black.insert(u);
    grey.erase(u);
}

int main(){
  vector<int>adj[5];

  edge(adj,0,1);
  edge(adj,0,2);
  edge(adj,1,3);
  edge(adj,2,0);
  edge(adj,3,3);
  edge(adj,2,3);
  edge(adj,2,4);
  for(int i=0;i<5;i++){
    white.insert(i);
  }
  find_cycle(0,adj);
  if(flag==0)cout<<"Given Graph is non-cyclic"<<endl;
  else
  cout<<"Given Graph is cyclic"<<endl;
  return 0;
}
