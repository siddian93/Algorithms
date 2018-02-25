#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int lis(int ar[], int N){
    int m=0;
    vector<int> dp(N, 1);
    
    for (int i = 1; i< N; i++){
        for (int j = 0; j<i; j++){
            if (ar[i]>ar[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    for (int i = 0; i< N; i++){
        if (m<dp[i]){
            m = dp[i];
        }
    }
    return m;
}

int main(){
    int ar[] = {10, 22, 9, 33, 21, 50, 41, 60};
    cout<<lis(ar, sizeof(ar)/sizeof(*ar));
    return 0;
}