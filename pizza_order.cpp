#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void swap( deque<vector<int> >& , int a, int b);
void sort_in_time(deque<vector<int> >&);
void min_heapify(deque< vector<int> >&, int);
void pop_first(deque< vector<int> >&);

int a = 5;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    a = ++a + 5;
    cout<<a;
    return 0;
}
    /*
    int N, c_in, c_ord, c_wait=0, avg_wait=0;
    int t_tot = 0, count = 0;
    deque< vector<int> > v;
    deque< vector<int> > dq;
    deque<vector<int> >::iterator it;
    vector<int> costumer, v_temp;
    
    cin>>N;
    for (int i = 0; i<N; i++){
        cin>>c_in>>c_ord;
        costumer.push_back(c_in); costumer.push_back(c_ord);
        v.push_back(costumer);
        costumer.resize(0);
    }

    sort_in_time(v);
    for (int i = 0; i<v.size(); i++){
        v[i][2]  = i;
    }
    int j = 0;
    for (int i = 0; i<N; i++){
        while(j<N && v[j][0]<=t_tot){
            dq.push_back(v[j]);
            j++;
        }
        min_heapify(dq, pow(2, floor(log2(dq.size()))));
        if (!dq.empty()){
            v_temp = dq.front();
            t_tot+=v_temp[1];
            avg_wait+=t_tot-v_temp[0];
            dq.pop_front();
        }
    
        for (int k  = 0; k<dq.size(); k++){
            for (int l = 0; l<3; l++){
                cout<<dq[k][l]<< "  ";
            }
            cout<<endl;
        }
    }
    cout<<avg_wait/N<<endl;
    return 0;
}


void pop_first(deque<vector<int> >& dq){
    dq.pop_front();
}

void swap(deque<vector<int> >& v , int a , int b){
    int p, q, r;
    p = v[a][0]; q = v[a][1]; r = v[a][2];
    v[a][0] = v[b][0]; v[a][1] = v[b][1]; v[a][2] = v[b][2];
    v[b][0] = p; v[b][1] = q; v[b][2] = r;
}


void sort_in_time(deque<vector<int> >& v){
    int len = v.size();
    for (int i = 0; i < len; i++){
        for (int j  = 0; j < len; j++){
            if (v[i][0]<=v[j][0]){
                swap(v, i, j);
            }
        }
    }
}

void min_heapify(deque<vector<int> >& v, int i){
    int left  = i*2+1;
    int right = i*2+2;
    int small = i;
    int arr_size = v.size();
    if (i<0){
        return;
    }
    if (left<arr_size && v[i][1]>v[left][1]){
        small = left;
        //cout<<small<<"LEFT"<<endl;
    }
    if (right<arr_size && v[small][1]>v[right][1]){
        small = right;
        //cout<<small<<"Right"<<endl;
    }
    if (small!=i){
        swap(v, i, small);
        //max_heapify(v, right);
        
    }
    min_heapify(v,i-1);
}
*/

