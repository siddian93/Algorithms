#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

class Graph{
private:
    int N, E;
    vector<vector<int> > graph;
    vector<bool> visted;
    void add_edges(int a, int b);
public:
    Graph(){
        N = 4;
        E = 5;
        graph.resize(N+1);
        visted.resize(N+1);
    }
    void create_graph();
    void dfs(int node);
    void bfs(int node);
};

void Graph::add_edges(int a, int b){
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void Graph::create_graph(){
    add_edges(4, 3);
    add_edges(1, 2);
    //add_edges(2, 3);
    add_edges(2, 4);
    add_edges(1, 3);
    
}

void Graph::dfs(int node){
    visted[node] = 1;
    cout<<node<<" ";
    for (int i = 0; i< graph[node].size(); i++){
        if (visted[graph[node][i]]==0)
            dfs(graph[node][i]);
    }
}

void Graph::bfs(int node){
    fill(visted.begin(), visted.end(), 0);
    visted[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        cout<<n<<" ";
        for (int i = 0 ; i< graph[n].size(); i++){
            if (visted[graph[n][i]]== 0){
                visted[graph[n][i]] = 1;
                q.push(graph[n][i]);
                
            }
        }
    }
}

int main(){
    Graph g;
    g.create_graph();
    g.dfs(1);
    cout<<endl;
    g.bfs(1);
    cout<<endl;
    return 0;
}