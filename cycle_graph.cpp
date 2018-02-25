#include<bits/stdc++.h>

#define loop(i, start, end) for(i = start; i<end; i++)

using namespace std;

void print_root(vector<int> roots){
    int i, j;
    loop(i, 0, roots.size()){
        cout<<roots[i]<<" ";
    }
}

int dfs(vector<vector<int> >& graph, int v, int parent, vector<bool>& visted, vector<int>& roots){
    int i;
    static int count;
    visted[v] = 1;
    roots[v] = parent;
    cout<<v<<" ";
    loop(i, 0, graph[v].size()){
        if (visted[graph[v][i]] && graph[v][i]!= parent){
            count+=1;
        }
        if (!visted[graph[v][i]]){
            dfs(graph, graph[v][i], v, visted, roots);
        }    
    }
    return count/2;
}


int main(){
    int i1, i2;
    int a, b;
    int n , e;
    cin>>n>>e;
    vector<vector<int> > graph(n+1);
    vector<pair<int, int> > edges;
    loop(i1, 0, e){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }
    vector<bool> visted(n+1);
    vector<int> roots(n+1);
    int cc = dfs(graph, 1, 0, visted, roots);
    cout<<endl;
    cout<<"Number of Cycles in this graph is : "<<cc<<endl;
    cout<<endl;
    //print_root(roots);
    //cout<<endl;
    //print_graph(graph);
    return 0;
}