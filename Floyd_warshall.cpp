// Floyd-Warshall Algorithm in C++

#include <iostream>
using namespace std;

#define Vertices 7

#define INF 9999

void printMatrix(int arr[][Vertices]);

void floydWarshall(int graph[][Vertices]) {
  int arr[Vertices][Vertices], i, j, k;

  for (i = 0; i < Vertices; i++)
    for (j = 0; j < Vertices; j++)
      arr[i][j] = graph[i][j];

  for (k = 0; k < Vertices; k++) {
    for (i = 0; i < Vertices; i++) {
      for (j = 0; j < Vertices; j++) {
        if (arr[i][k] + arr[k][j] < arr[i][j])
          arr[i][j] = arr[i][k] + arr[k][j];
      }
    }
  }
  printMatrix(arr);
}

void printMatrix(int arr[][Vertices]) {
  for (int i = 0; i < Vertices; i++) {
    for (int j = 0; j < Vertices; j++) {
      if (arr[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int sample_graph[Vertices][Vertices] = {{0, 3, 6, INF, INF, INF, INF},
   {3, 0, 2, 1, INF, INF, INF},
   {6, 2, 0, 1, 4, 2, INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF, INF, 4, 2, 0, 2, 1},
   {INF, INF, 2, INF, 2, 0, 1},
   {INF, INF, INF, 4, 1, 1, 0}};
  floydWarshall(sample_graph);
}
