#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

int  main(){
    pair< int, pair<int, int> > p, q;
    vector<pair <int, pair<int, int> > > v;
    //q = make_pair(5,2);
    p  = make_pair(10, make_pair(5, 2));
    v.push_back(p);
    p  = make_pair(1, make_pair(15, 52));
    v.push_back(p);
    p  = make_pair(12, make_pair(50, 21));
    v.push_back(p);
    p  = make_pair(9, make_pair(2, 0));
    v.push_back(p);
    p  = make_pair(15, make_pair(11, 88));
    v.push_back(p);
    sort(v.begin(), v.end());
    for (int i = 0; i< v.size(); i++){
        cout<<v[i].first<< " -> ("<<v[i].second.first<<" -> "<<v[i].second.second<<")"<<endl;
    }
    //cout<<v.size();
    //cout<<endl<<v[0].first<<endl;
    return 0;
}