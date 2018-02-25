#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

int main(){
    map<int, int> m;
    map<int, int>::iterator it;
    map<int, int>::reverse_iterator rit;
    m[1] = 5;
    m[2]  = 6;
    m[3]  = 12;
    m[4] = 2;
    m[4] = 5;
    m[5]  = 45;
    for (rit = m.rbegin(); rit!=m.rend(); ++rit){
        cout<<rit->first<<'\t'<<rit->second<<endl;
    }
    return 0;
}