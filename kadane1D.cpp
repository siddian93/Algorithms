#include<iostream>

using namespace std;

long long int max_con_sum(int ar[], int N){
    int start = 0, end = 0, s = 0;
    long long int max_so_far = ar[0], max_at_i = 0;
    for (int i = 0; i<N; i++){
        max_at_i+=ar[i];
        if (max_at_i>max_so_far){
            max_so_far = max_at_i;
            end = i;
        }
        if (max_at_i<0){
            max_at_i = 0;
            start = i;
        }
    }
    
    /*
    for (int i = 0; i< N; i++){
        cout<<ar[i]<<" ";
    }
    */
    for (int i = start+1; i<end+1; i++){
        cout<<ar[i]<<" ";
    }
    return max_so_far;
}

int main(){
    int ar[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int N = sizeof(ar)/sizeof(ar[0]);
    cout<<max_con_sum(ar, N)<<endl;
    return 0;
}