#include<iostream>

using namespace std;

long long int find_min(long long int a, long long int b, long long int c){
    long long m;
    m = (a<b)?a:b;
    m = (m<c)?m:c;
    return m;
}

long long int ugly(int n){
    long long int ar[n];
    int i_2=0, i_3=0, i_5=0;
    ar[0] = 1;
    for (int i = 1; i< n; i++){
        ar[i] = find_min(ar[i_2]*2, ar[i_3]*3, ar[i_5]*5);
        if (ar[i] == ar[i_2]*2)
            i_2+=1;
        if (ar[i] == ar[i_3]*3)
            i_3+=1;
        if (ar[i] == ar[i_5]*5)
            i_5+=1;    
    }
    for (int i = 0; i<n+1 ; i++){
        cout<<ar[i]<<" ";
    }
    return ar[n];
}

int main(){
    int n = 5;
    cout<<ugly(n)<<endl;
    return 0;
}