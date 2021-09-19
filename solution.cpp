//
// Created by Kylian Lee on 2021/08/16.
//

#include <iostream>
#include <vector>
#define SIZE 1001
using namespace std;

//vector<vector<int>> graph;
//vector<int> node;
int graph[SIZE][SIZE];
int node[SIZE];
int node_num;

void dfs(int prev);

int main(){
//  int node_num;
//  cin >> node_num;
  scanf("%d", &node_num);
//  graph.resize(node_num);
//  node.resize(node_num);
//  for (int i = 0; i < node_num; ++i) {
//    graph[i].resize(node_num);
//  }
  for (int i = 0; i < node_num; ++i) {
    for (int j = 0; j < node_num; ++j) {
//      cin >> graph[i][j];
      scanf("%d", &graph[i][j]);
      if(graph[i][j] != 0){
        node[i] += graph[i][j];
        node[j] += graph[i][j];
      }
    }
  }
  bool is_eulerian = true;
  for (int i = 0; i < node_num; ++i) {
    node[i] /= 2;
    if(node[i] % 2) {
      is_eulerian = false;
      break;
    }
  }
  if(is_eulerian){
    dfs(0);
  }
  else{
//    cout << -1 << endl;
    printf("%d\n", -1);
  }
  return 0;
}

void dfs(int prev){
  if(!node[prev]){
    printf("%d ", prev + 1);
    return;
  }
//  int size = graph.size();
  int size = node_num;
  for (int i = 0; i < size; ++i) {
    if(graph[prev][i] != 0){
      graph[prev][i]--;
      graph[i][prev]--;
      node[i]--;
      node[prev]--;
      dfs(i);
    }
  }
//  cout << prev + 1 << ' ';
  printf("%d ", prev + 1);
}