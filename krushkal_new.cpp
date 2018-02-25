#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

class min_span_tree{
private:
    int N, E;
    vector<pair<int, pair<int, int> > >edges;
    vector<int> ar;
    void add_edges(int a, int b, int cost);
    void create_graph();
    int root(int a);
    void union1(int a, int b);

public:
    min_span_tree(){
        N = 5; E = 7;
        //edges.resize(E);
        ar.resize(N+1);
        create_graph();
        for ( int i = 0; i< N+1; i++){
            ar[i] = i;
        }
    }
    void krushkal();
    void prims();
};

void min_span_tree::add_edges(int a, int b, int cost){
    edges.push_back(make_pair(cost, make_pair(a, b)));
    edges.push_back(make_pair(cost, make_pair(b, a)));
}

int min_span_tree::root(int a){
    while(ar[a]!=a){
        ar[a] = ar[ar[a]];
        a = ar[a];
    }
    return a;
}

void min_span_tree::union1(int a, int b){
    int root_a = root(a);
    int root_b = root(b);
    ar[root_a] = root_b;
}


void min_span_tree::create_graph(){
    add_edges(1, 2, 1);
    add_edges(2, 3, 5);
    add_edges(1, 3, 7);
    add_edges(2, 4, 4);
    add_edges(2, 5, 3);
    add_edges(4, 5, 2);
    add_edges(3, 5, 6);
    sort(edges.begin(), edges.end());
    /*
    for (int i = 0; i<edges.size(); i++){
        cout<<edges[i].first<<" "<<edges[i].second.first<<" "<<edges[i].second.second<<endl;
    }
    */
}

void min_span_tree::krushkal(){
    int min_cost  = 0;
    for (int i = 0; i<edges.size(); i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int cost = edges[i].first;
        if (root(a)!=root(b)){
            union1(a, b);
            min_cost+=cost;
        }
    }
    cout<<min_cost<<endl;
}

int main(){
    min_span_tree mst;
    mst.krushkal();
    return 0;
}