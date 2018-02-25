#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    int N, E;
    vector<vector<pair<int, int> > > graph;
    vector<int> dist;
    void add_edges(int a, int b, int cost);
    void create_graph();
public:
    Graph(){
        N = 5; E = 7;
        graph.resize(N+1);
        dist.resize(N+1, 2e9);
        create_graph();
    }
    void bellman_ford(int start);
};

void Graph::add_edges(int a, int b, int cost){
    graph[a].push_back(make_pair(b, cost));
    graph[b].push_back(make_pair(a, cost));
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

void Graph::bellman_ford(int start){
    //Initialize
    dist[start] = 0;
    for (int i = 0; i < graph[start].size(); ++i){
        dist[graph[start][i].first] = graph[start][i].second;
    }

    bool flag = 1;
    int count = 0;
    while(flag){
        flag = 1;
        for (int i  = 1; i<N+1; ++i){
            for (int j = 0; j<graph[i].size(); j++){
                if (dist[graph[i][j].first]>(graph[i][j].second+dist[i])){
                    flag = 0;
                    dist[graph[i][j].first]  = graph[i][j].second+dist[i];
                }
            }
        }
        if (flag){
            break;
        }
        count++;
    }

    cout<<count<<endl;
    for (int i = 1; i< dist.size(); ++i){
        cout<<dist[i]<<" ";
    }
}


int main(){
    Graph sp;
    sp.bellman_ford(4); 
    cout<<endl;
    return 0;
}