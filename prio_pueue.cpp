#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 0; i< 20; i++){
        if (i&1)
            pq.push(make_pair(i, i+10));
        else 
            pq.push(make_pair(i, i-10));
    }

    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}