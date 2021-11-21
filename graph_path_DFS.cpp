// C++ program to check if there exists a path between two vertices of a graph.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


bool isPathDFS(vector <vector<int>>& graph, int nodes, int source, int end){
       bool visited[nodes];
    for(int i = 0;i<nodes;++i){
        visited[i] = false;
    }

    stack <int> traversal;
    traversal.push(source);
    visited[source-1] = true;

    while(!traversal.empty()){
              source = traversal.top();
        traversal.pop();

        for(int i = 0;i < (int)graph[source-1].size();++i){
            if(graph[source-1][i]==end)
                    return true;

            if(visited[graph[source-1][i]-1]==false){

                traversal.push(graph[source-1][i]);
                visited[graph[source-1][i]-1] = true;
            }
        }
    }

    return false;
}

int main(){
    int nodes;
    cout<<"Enter no of nodes :";
       cin >> nodes;

    int edges;
    cout << "Enter no. of edges in graph = ";
    cin >> edges;

    vector <vector<int>> graph;
    graph.resize(nodes);

    cout << "Edges:\n";
    int source,end;

    while(edges--){
        cin >> source>>end;

          if(source > nodes || end > nodes){
            cout << "Invalid nodes.";
            return 1;
        }

        graph[source-1].push_back(end);
    }

   cout<<"Enter path to find : "<<endl;
        cin >> source>>end;

          if(source > nodes || end > nodes){
            cout << "Invalid nodes.\n";
           // continue;
        }

        if(isPathDFS(graph,nodes,source,end)){
            cout << "Yes"<<"\n";
        }else cout << "No"<<"\n";

    return 0;
}

