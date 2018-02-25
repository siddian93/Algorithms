#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void max_heapify(vector<int>&, int);
void insert(vector<int>&, int);
void extract(vector<int>&);


int main(){
    vector<int> v;
    for (int i =2; i< 3; i++){
        v.push_back(i);
    }
    max_heapify(v, pow(2, floor(log2(v.size())))-1);
    //extract(v);
    //insert(v, 100);
    cout<<"Max heap is : "<<v[0]<<endl;
    return 0;
}

void swap(vector<int>& v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void max_heapify(vector<int>& v, int i){
    int left  = i*2+1;
    int right = i*2+2;
    int large = i;
    int arr_size = v.size();
    if (i<0){
        return;
    }
    if (left<arr_size && v[i]<v[left]){
        large = left;
        //cout<<large<<"LEFT"<<endl;
    }
    if (right<arr_size && v[large]<v[right]){
        large = right;
        //cout<<large<<"Right"<<endl;
    }
    if (large!=i){
        swap(v, i, large);
        //max_heapify(v, right);
        
    }
    max_heapify(v,i-1);
    
}

void extract(vector<int>& v){
    int val = v.back();
    v.pop_back();
    v[0] = val;
    max_heapify(v, pow(2, floor(log2(v.size())))-1);
}

void insert(vector<int>& v, int val){
    v.push_back(val);
    max_heapify(v, pow(2, floor(log2(v.size())))-1);
}