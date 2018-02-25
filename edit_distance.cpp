#include<iostream>
#include<vector>

using namespace std;

int edit_dist(string s1, string s2){
    vector<vector<int> > dp(s1.length()+1, vector<int>(s2.length()+1, 0));
    for (int i = 0; i<s1.length()+1; i++){
        dp[i][0] = i;
    }
    for (int i = 0; i<s2.length()+1; i++){
        dp[0][i] = i;
    }

    for (int i = 1; i<s1.length()+1; i++){
        for (int j = 1; j<s2.length()+1; j++){
            if (s1[i-1] == s2[j-1]){
                //cout<<s1[i-1]<<" "<<s2[j-1]<<endl;
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
        }    
    }

    /*
    for (int i= 0 ; i< s1.length()+1; i++){
        for (int j= 0; j< s2.length()+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[s1.length()][s2.length()];
    //return 1;
}

int main(){
    string s1 = "sunday", s2 = "saturday";
    cout<<edit_dist(s1, s2)<<endl;
    return 0;
}