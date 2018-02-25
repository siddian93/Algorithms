#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;


//68:F7:28:0F:D7:63

void print_graph( vector< vector<int> >& v){
    for (int i = 0; i<v.size(); i++){
        for (int j = 0; j<v[i].size(); j++){
            cout<<v[i][j]<< " ";
        }
        cout<<endl;
    }
}

//For BFS QUEUE is used

void bfs(vector< vector<int> >& v){
    int node;
    vector<bool> visted(v.size(), false);
    queue<int> q;
    q.push(v[1][0]);
    visted[v[1][0]] = true;
    cout<<endl;
    while(!q.empty()){
        node = q.front();
        cout<<node<<" ";
        q.pop();
        for (int i = 0; i<v[node].size(); i++){
            if (visted[v[node][i]]==false){
                q.push(v[node][i]);
                visted[v[node][i]] = true;
            }
        }
    }
}

//For DFS USE STACK
void dfs(vector< vector<int> >&v){
    int node;
    vector<bool> visted(v.size(), false);
    stack<int> s;
    s.push(v[1][0]);
    visted[v[1][0]]  = true;
    cout<<endl;
    while(!s.empty()){
        node = s.top();
        cout<<node<<" ";
        s.pop();
        for (int i = 0; i<v[node].size(); i++){
            if (visted[v[node][i]] == false){
                s.push(v[node][i]);
                visted[v[node][i]] = true;
            }
        }

    }
}


int main(){
    int N, a, b, n_edg;
    cin>>N>>n_edg;
    vector<vector<int> > v(N+1);
    //Create Graph
    for (int i = 0; i<=N; i++){
        v[i].push_back(i);
    }
    for (int i = 0; i<n_edg; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //Graph Created
    print_graph(v);

    bfs(v);

    dfs(v);

    return 0;
}