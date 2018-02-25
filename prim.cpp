#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<utility>

using namespace std;

int prim(int, vector<vector<pair<int, int> > >&);

int main(){
    int N, Q, a, b, w, min_cost;
    cin>>N>>Q;
    pair<int, int> p;
    vector<vector<pair<int, int> > > v(N+1);

    for (int i = 0; i < Q; i++){
        cin>>a>>b>>w;
        v[a].push_back(make_pair(w, b));
        v[b].push_back(make_pair(w, a));
    }
    min_cost  = prim(1, v);
    cout<<min_cost<<endl;
    return 0;
}

int prim(int start, vector<vector<pair<int, int> > >& v){
    int min_cost= 0;
    pair<int, int> t;
    vector<bool> visted(v.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
        if (visted[t.second] == true){
            continue;
        }
        min_cost+=t.first;
        visted[t.second] = true;
        for (int i = 0; i<v[t.second].size(); i++){
            if (visted[v[t.second][i].second] == false)
                pq.push(v[t.second][i]);
        }
    } 
    return min_cost;
}