#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 999999;
int arr[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        arr[i] = i;
}

int root(int x)
{
    while(arr[x] != x)
    {
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}

void set_union(int x, int y)
{
    int p = root(x);
    int q = root(y);
    arr[p] = arr[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, min_cost = 0;
    for(int i = 0;i < edges;++i)
    {
           x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
          if(root(x) != root(y))
        {
            min_cost += cost;
            set_union(x, y);
        }
    }
    return min_cost;
}

int main()
{
    int x, y;
    long long weight, cost, min_cost;
    initialize();
    cout<<"Enter no of node and edges:";
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
       cout <<"Enter edge source, dest and weight : ";
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    min_cost = kruskal(p);
    cout << min_cost << endl;
    return 0;
}
