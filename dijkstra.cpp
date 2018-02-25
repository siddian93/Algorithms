#include<bits/stdc++.h>

using namespace std;

class Graph{
private:
    int N, E;
    vector<vector<pair<int, int> > > graph;
    vector<int> dist;
    vector<bool> visted;
    void create_graph();
    void add_edges(int, int, int);
public:
    Graph(){
        N = 5; E = 7;
        graph.resize(N+1);
        dist.resize(N+1, 2e9);
        visted.resize(N+1);
        create_graph();
    }
    void disjkstra(int);
};

void Graph::add_edges(int a, int b, int cost){
    graph[a].push_back(make_pair(cost, b));
    graph[b].push_back(make_pair(cost, a));
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

void Graph::disjkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, start));
    dist[start] = 0;
    while(!q.empty()){
        cout<<q.top().second<<" ";
        int n = q.top().second;
        int c = q.top().first;
        q.pop();
        if (visted[n])
            continue;
        visted[n]  = 1;
        for (int i = 0; i< graph[n].size(); ++i){
            if (dist[graph[n][i].second] > dist[n] + graph[n][i].first){
                dist[graph[n][i].second] = dist[n] + graph[n][i].first;
                q.push(make_pair(dist[graph[n][i].second], graph[n][i].second));
            }    
        }
        cout<<endl;
        for (int i =1 ; i< dist.size(); i++){
            cout<<dist[i]<<" ";
        }

    }
    cout<<endl;
    for (int i =1 ; i< dist.size(); i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    Graph sp;
    sp.disjkstra(1);
    cout<<endl;
    return 0;
}