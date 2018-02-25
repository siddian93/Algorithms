#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int krushkal(vector <pair<int, pair<int, int> > >&, vector<int>&, int);
int root(vector<int>& , int);
void union1(vector<int>& , int, int);

int main(){
    int a, b, w, N, Q, min_cost;
    cin>>N>>Q;
    pair<int , pair<int, int> > v;
    vector<pair<int, pair<int, int> > > edges;
    vector<int> mst;
    vector<int> pred(N+1);
    
    for (int i = 1; i<N+1; i++){
        pred[i] = i;
    }

    for (int i = 0; i<Q; i++){
        cin>>a>>b>>w;
        edges.push_back(make_pair(w, make_pair(a, b)));
        edges.push_back(make_pair(w, make_pair(b, a)));
    }
    cout<<endl;
    sort(edges.begin(), edges.end());

    min_cost = krushkal(edges, pred, N);
    cout<<endl;
    cout<<min_cost<<endl;
    /*
    for (int i = 0; i<Q; i++){
        cout<<edges[i].first<< " "<<edges[i].second.first<< " "<<edges[i].second.second<<endl;
    }
    */
    return 0;
}


int krushkal(vector <pair<int, pair<int, int> > >& edges, vector<int>& pred, int N){
    int min_cost = 0;
    int x, y, cost;
    for (int i = 0; i<edges.size(); i++){
        cost = edges[i].first;
        x = edges[i].second.first;
        y = edges[i].second.second;
        if(root(pred, x)!=root(pred, y)){
            min_cost+=cost;
            union1(pred, x, y);
        }        
    }
    return min_cost;
}


int root(vector<int>& pred, int a){
    while(pred[a]!=a){
        pred[a] = pred[pred[a]];
        a = pred[a];
    }
    return a;
}

void union1(vector<int>& pred, int x, int y){
    int p = root(pred, x);
    int q = root(pred, y);
    pred[p]  = pred[q];
}