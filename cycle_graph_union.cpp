#include<iostream>
#include<vector>

using namespace std;

int root(vector<int>& v, int node){
    while(v[node]!=node){
        v[node]  = v[v[node]];
        node = v[node];
    }
    return node;
}

void union_1(vector<int>& v, int a, int b){
    int r_a = root(v, a);
    int r_b = root(v, b);
    v[r_a] = r_b;
}

int detect_cycle(vector<pair<int, int> >& edges, vector<int>& v){
    int cc = 0;
    for (int i = 0; i< edges.size(); i++){
        int a = edges[i].first;
        int b = edges[i].second;
        //cout<<a<<" "<<b<<endl;
        if (root(v, a) == root(v, b)){
            cout<<root(v, a)<<" "<<root(v, b)<<endl;
            cc+=1;
        }
        union_1(v, a, b);
            
    }
    for (int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return cc;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int> > graph(n+1);
    vector<int> v(n+1);
    for (int i =0; i< v.size(); i++){
        v[i] = i;
    }
    vector<pair<int, int> > edges;
    for ( int i = 0; i< e; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }

    cout<<"Number of Cyclic Edges: "<<detect_cycle(edges, v)<<endl;
    return 0;
}