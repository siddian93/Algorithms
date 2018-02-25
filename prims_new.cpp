#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

class Graph{
private:
    int N, E;
    vector<vector<pair<int, int> > > graph;
    vector<bool> visted;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    void create_graph();
    void add_edges(int a, int b, int cost);
public:
    Graph(){
        N = 5; E = 7;
        graph.resize(N+1);
        visted.resize(N+1);
        create_graph(); 
    }
    void prims();
};

void Graph::add_edges(int a, int b, int cost){
    graph[a].push_back(make_pair(cost, b));
    graph[b].push_back(make_pair(cost, a));
}

void Graph::prims(){
    q.push(make_pair(0, 1));
    visted[0] = 1;
    int min_cost = 0;
    while(!q.empty()){
        int node = q.top().second;
        int cost = q.top().first;
        q.pop();
        if (visted[node]  == 1)
            continue;
        visted[node]  = 1;
        min_cost+=cost;
        for (int i = 0; i<graph[node].size(); i++){
            if (!visted[graph[node][i].second])
                q.push(graph[node][i]);
                
        }
    }
    cout<<min_cost<<endl;
}

void Graph::create_graph(){
    add_edges(1, 2, 1);
    add_edges(2, 3, 5);
    add_edges(1, 3, 7);
    add_edges(2, 4, 4);
    add_edges(2, 5, 3);
    add_edges(4, 5, 2);
    add_edges(3, 5, 6);
}

int main(){
    Graph mst;
    mst.prims();
    return 0;
}