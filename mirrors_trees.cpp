#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    string s = "Dud";
    map<string, char> m;
    m["Dude"]  = 'd';
    //cout<<m["Dude"]<<endl;
    s+='e';
    //cout<<s;
    cout<<s.substr(1, 2)<<endl;
    return 0;
}