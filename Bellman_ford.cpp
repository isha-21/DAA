#include<iostream>
#define MAX 10
using namespace std;

typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void bellman_ford(int nv,edge e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];

  for(i=0;i<nv;i++)
  {
    dis[i]=999;
  }

  dis[src_graph]=0;

  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      weight=e[j].wt;


      if(dis[u]!=999 && dis[u]+weight < dis[v])
      {
        dis[v]=dis[u]+weight;
      }
    }
  }

  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;

    if(dis[u]+weight < dis[v])
    {
      cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
      return;
    }
  }

  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<=nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i];
  }

}

int main()
{
  int nv,ne,src_graph;
  edge e[MAX];

  cout<<"Enter the number of vertices and edges: ";
  cin>>nv >> ne;

  printf("Enter the source vertex of the graph: ");
  cin>>src_graph;

   for(int i=0;i<ne;i++)
  {
    cout<<"\n Edge details -  "<<i+1<<"=>";
    cout<<"\nEnter source , destination vertex and weight :";
    cin>>e[i].src>>e[i].dest>>e[i].wt;

  }

  bellman_ford(nv,e,src_graph,ne);

  return 0;
}
