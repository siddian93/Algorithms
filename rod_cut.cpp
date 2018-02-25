#include<iostream>
#include<vector>

using namespace std;

long long int max_price(int val[], int n){
    vector<long long int> dp(n+1, 0);
    dp[1] = val[0];
    for (int i = 1; i <n+1; i++){
            
    }
    return dp[n];
}

int main(){
    int val[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<max_price(val, sizeof(val)/sizeof(val[0]))<<endl;
    return 0;
}