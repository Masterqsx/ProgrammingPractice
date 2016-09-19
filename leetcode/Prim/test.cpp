#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void dijkstra(unordered_map<int, unordered_map<int, double> > &);
void prim(unordered_map<int, unordered_map<int, double> > &);

int main(int argc, char **argv){
  unordered_map<int, unordered_map<int, double> > graph;
  ifstream input;
  input.open(argv[1], ios::in);
  if (input.fail()) return 0;
  string buff;
  int header = 2, src = 0, dest = 0;
  double dis = 0;
  while (getline(input, buff)){
    if (header > 0){
      header--;
      continue;
    }
    stringstream ss(buff);
    ss>>src>>dest>>dis;
    if (graph.count(src) == 0)
      graph[src] = unordered_map<int, double>({{dest, dis}});
    else
      graph[src][dest] = dis;
  }
  prim(graph);
  return 0;
} 
