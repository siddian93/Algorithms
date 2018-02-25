#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int lis(string& s1, string& s2){
    int l1 = s1.size(), l2 = s2.size();
    int dp[l1+1][l2+1];
    memset(dp, 0, sizeof(int)*(l1+1)*(l2+1));
    for (int i =1; i< l1+1; i++){
        for (int j = 1; j<l2+1; j++){
            if (s1[i-1]==s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    for (int i =0; i< l1+1; i++){
        for (int j = 0; j<l2+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[l1][l2];
}

int main(){
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout<<lis(s1, s2)<<endl;
    return 0;
}