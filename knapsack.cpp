#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int knap1D(vector<pair<int, int> >& v, int w){
    vector<int> dp(w+1, 0);
    int m = 0;
    for (int i = 1; i<w+1; i++){
        if (v[i-1].first<=w){
            dp[v[i-1].first] = v[i-1].second;
        }
    }
    for (int i = 1; i < w+1; i++){
        for (int j = 0; j<=i; j++){
            if (m<(dp[j]+dp[i-j])){
                m = dp[j]+dp[i-j];
            }
        }
        dp[i] = max(dp[i], m);
    }
    return dp[w];
}

int knap2D(vector<pair<int, int> >& v, int w){
    int n = v.size()+1, m = w+1;
    vector<vector<int> > dp( n, vector<int>(m, 0));
    for (int i = 1; i< n; i++){
        for (int j = 1; j<m; j++){
            if (v[i].first <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].first]+v[i].second);
            }
            else {
                dp[i][j]  = dp[i-1][j];
            }
        }
    }
    return dp[n-1][w];
}

int main(){
    vector<int> weight, val;
    vector<pair<int, int> > d;
    int w, v, N, W;
    cin>>N>>W;
    while(N>0){
        cin>>w>>v;
        d.push_back(make_pair(w, v));
        N--;
    }
    sort(d.begin(), d.end());
    cout<<knap2D(d, W)<<endl;
    cout<<knap1D(d, W)<<endl;
    return 0;
}

/*
    for (int i = 0; i<d.size(); i++){
        cout<<d[i].first<<" "<<d[i].second<<endl;
    }
*/