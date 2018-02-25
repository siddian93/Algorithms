#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

int main(){
    int N, a, b;
    cin>>N;
    vector< vector<int> > v(N+1);
    vector<bool> visted(N+1, false);
    for (int i = 0; i<=N; i++){
        v[i].push_back(i);
    }
    for (int i=1; i<N; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i<=N; i++){
        for (int j = 0; j<v[i].size(); j++){
            cout<<v[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}