#include<iostream>
#include<vector>

using namespace std;


long long int coin_ways(int c[], int s, int N){
    vector<vector<long long int> > way(s+1, vector<long long int>(N+1, 0));
    
    for (int i = 0; i< s+1; i++){
        way[i][0] = 1;
    }

    for (int i = 1; i< s+1; i++){
         for (int j = 1; j<N+1; j++){
            if (c[i-1]>j){
                way[i][j] = way[i-1][j];
            }
            else {
                //cout<<j<<" "<<c[i]  <<j-c[i]<<endl;
                way[i][j] = way[i-1][j] + way[i][j-c[i-1]];
            }
         }
    }
    /*
    for (int i = 0; i< s+1; i++){
        for (int j = 0; j<N+1; j++){
           cout<<way[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return way[s][N];
}

int main(){
    int c[]  = {1, 2, 3};
    int N = 5;
    cout<<coin_ways(c, sizeof(c)/sizeof(*c), N)<<endl;
    return 0;
}

/*
int get_max_ways(vector<int>& change, int tot){
    vector<long long int> ways(tot+1, 0);
    ways[0] = 1;
    for (int i = 0; i<change.size(); i++){
        for(int j = change[i]; j<tot+1; j++){
             ways[j] += ways[j-change[i]]; 
        }
    }
    return ways[tot];
}

int main(){
    int N, tot; 
    cin>>N>>tot;
    vector<int> change(N);
    for (int i = 0; i< N; i++){
        cin>>change[i];
    }
    cout<<get_max_ways(change, tot);
    return 0;
}
*/