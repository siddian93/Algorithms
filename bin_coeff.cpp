#include<iostream>
#include<vector>

#define mod 1000000007

using namespace std;

/*
Binomial Coefficient : C(n, k) = C(n-1, k-1) + C(n-1, k)
Its basically selecting k items from n items and the ways to doing it. 
*/

long long int bin_coef(int N, int k){
    vector<vector<long long int> > c(N+1, vector<long long int>(k+1, 0));
    for (int i = 0; i< N+1; i++){
        for (int j = 0; j <= min(i, k); j++){
            if (j == 1 && i!= 0){
                c[i][j] = i;
            }
            if (i == 0 || j == 0 || j == i){
                c[i][j] = 1;
            }
            else {
                c[i][j] = (c[i-1][j-1] + c[i-1][j])% mod;
            }
        }
    }
    
    return c[N][k];
}


int main(){
    int N = 10, k = 5;
    cout<<bin_coef(N, k)<<endl;
    return 0;
}