#include<iostream>
#include<vector>

using namespace std;

long long int min_cost(int cost[][3],  int r, int c){
    vector<vector<long long int> > dp(r, vector<long long int>(r, 0));
    dp[0][0] = cost[0][0];
    for (int i = 1, j = 1; i< r, j<c; i++, j++){
        dp[i][0] = dp[i-1][0]+cost[i][0];
        dp[0][j] = dp[0][j-1]+cost[0][j]; 
    }

    for (int i = 1; i<r; i++){
        for (int j = 1; j<c; j++){
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + cost[i][j];
        }
    }
    /*
    for (int i= 0; i<r; i++){
        for (int j = 0; j<c; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[r-1][c-1];
}

int main(){
    int cost[3][3]= { {1, 2, 3},
                    {4, 8, 2},
                    {1, 5, 3} };
    cout<<min_cost(cost, sizeof(cost)/sizeof(*cost), sizeof(cost[0])/sizeof(cost[0][0]))<<endl;
    return 0;
}