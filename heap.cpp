#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v;
    for (int i = 0; i< 10; i++){
        v.push_back(i);
    }
    cout<<v.back()<< endl;
    v.pop_back();

    make_heap(v.begin(), v.end());
    cout<<v.front()<<endl;
    pop_heap(v.begin(), v.end());
    v.pop_back();
    cout<<v.front();
    return 0;
}
