//
// Created by Kylian Lee on 2021/08/16.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<queue<int>>> circuit_list;

void findCircuit(int next, int orig, queue<int> q);
bool isEulerianCircuit();

int main(){
  int size;
  cin >> size;
  graph.resize(size);
  circuit_list.resize(size);
  for (int i = 0; i < size; ++i) {
    graph[i].resize(size);
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cin >> graph[i][j];
    }
  }
  if(isEulerianCircuit()){
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if(graph[i][j] != 0){
          graph[i][j]--;
          queue<int> q;
          q.push(i);
          findCircuit(j, i, q);
        }
      }
    }
  }
  else
    cout << -1 << endl;
  return 0;
}

void findCircuit(int next, int orig, queue<int> q){
  q.push(next);
  int size = graph.size();
  for (int i = 0; i < size; ++i) {
    if(graph[next][i] != 0){
      graph[next][i]--;
      if(i == orig){
        q.push(i);
        circuit_list[orig].push_back(q);

        break;
      }
      else{
        findCircuit(i, orig, q);
      }
    }
  }
}

bool isEulerianCircuit(){
  bool flag = true;
  int size = graph.size();
  for (int i = 0; i < size; ++i) {
    int count = 0;
    for (int j = 0; j < size; ++j) {
      if(graph[i][j] != 0){
        count++;
      }
    }
    if(count % 2 != 0){
      flag = false;
      break;
    }
  }
  return flag;
}