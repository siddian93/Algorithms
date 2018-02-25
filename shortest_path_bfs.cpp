#include<iostream>
#include<queue>
#include<vector>

//This Code is written to Find the Sortest Path in an undirected and No Weighted Edges
/*
Test Case is :
9 11
1 3
1 5
1 4
3 7
5 9
3 2
4 2
7 8
2 6
8 9
5 9

Enter 2 nodes for shortest Path :  4 8

o/p: 8 7 3 1 4 

*/

using namespace std;

void find_shortest_path(vector<vector<int> >& v ,int a, int b){
    int node, t;
    vector<bool> visted(v.size(), false);
    queue<int> q;
    vector<int> pred(v.size());
    pred[a] = 0;
    visted[a] = true;
    q.push(a);
    while(!q.empty()){
        node = q.front();
        q.pop();
        for (int i = 0; i < v[node].size(); i++){
            if (visted[v[node][i]]==false){
                q.push(v[node][i]);
                visted[v[node][i]] = true;
                pred[v[node][i]] = node;
            }
        }
    }
    for (int i = 0; i<pred.size(); i++){
        cout<<pred[i]<<" ";
    }
    cout<<endl;
    t = pred[b];
    cout<<b<<" ";
    while(t!=0){
        cout<<t<<" "; 
        t = pred[t];
    }
    cout<<endl;
}

int main(){
    int N, n_edg, a, b;
    cin>>N>>n_edg;
    vector< vector<int> > v(N+1);
    for (int i = 0; i<n_edg; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<"Enter 2 nodes for shortest Path : ";
    cin>>a>>b;
    find_shortest_path(v, a, b);
    return 0;
}