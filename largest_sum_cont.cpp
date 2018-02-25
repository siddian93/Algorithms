#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

int largest_sum_cont(int* ar, int N){
    int max_so_far = ar[0], max_here = ar[0];
    for (int i = 1 ; i< N; i++){
        max_here = max(ar[i], max_here+ar[i]);
        max_so_far = max(max_here, max_so_far);
    }
    int sum_here = ar[0];
    int max_sum = ar[0];
    int s_i=0, e_i=0;
    for (int i = 1; i< N; i++){
        sum_here += ar[i];
        if (sum_here>max_sum){
            max_sum = sum_here;
            e_i = i;
        }
        if (sum_here<0){
            sum_here = 0;
            s_i = i+1;
        } 
    }
    cout<<s_i<<" "<<e_i<<" The Sum here "<<endl;
    if (s_i>e_i){
        cout<<ar[e_i];
    }
    else {
        for (int i = s_i; i<=e_i; i++ ){
            cout<<ar[i]<<" ";
        }
    }
    
    cout<<endl;
    return max_so_far;
}

int main(){
    int ar[10];
    for (int i = 0; i< 10; i++){
        int sign = rand()%2;
        if (sign == 1)
            ar[i] = -(rand()%10+1);
        else 
            ar[i] = -rand()%10+1;
    }
    ar[0] =1;
    for (int i = 0; i< 10; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    cout<<largest_sum_cont(ar, 10)<<endl;
    cout<<endl;
    return 0;
}