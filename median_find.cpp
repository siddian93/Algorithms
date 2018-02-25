#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;



void testing(vector<int>& ar){
    if (ar.size() ==0)
        return;
    for (int i = 0; i< ar.size(); i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    vector<int> new_ar(ar.begin()+1, ar.end());
    testing(new_ar);
}

int main(){
    int size1 = rand()%10, size2 = rand()%10; 
    vector<int> ar1(size1, 1);
    vector<int> ar2(size2, 1);
    vector<int> res;
    for (int i = 0; i< size1; i++){
        ar1[i] = rand()%1000;
    }
    for (int i = 0; i< size2; i++){
        ar2[i] = rand()%1000;
    }
    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());
    
    res.insert(res.end(), ar1.begin(), ar1.end());
    res.insert(res.end(), ar2.begin(), ar2.end());
    sort(res.begin(), res.end());
    int med_res, med_comp;
    if (res.size()%2 == 0)
        med_res = (res[res.size()/2] + res[res.size()/2-1])/2;
    else 
        med_res = res[(res.size()-1)/2];
    // for (int i = 0; i< size1+size2; i++){
    //     cout<<res[i]<<" ";
    // }
    //cout<<endl;

    //med_comp = median_compute(ar1, ar2);
    testing(ar1);
    return 0;
}