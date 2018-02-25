#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

bool check_same(map<int, int>m){
    map<int, int>::iterator it, it2;
    //it2=m.begin
    for (it = m.begin(); it!=m.end(); it++){
        if (it->second!=(it++)->second)
            return false;
    }
    return true;
}

int find_max(map<int, int>m){
    map<int, int>::iterator it=m.begin();
    int max=it->second;
    for (it=m.begin();it!=m.end();it++){
        if (it->second>max)
            max = it->second;
    }
    return max;
}

int max_weight(map<int, int>m){
    map<int, int>::iterator it;
    int w = m.begin()->first;
    int max = 0;
    for(it = m.begin(); it!=m.end(); it++){
        if (it->second>max)
            w = it->first;
    }
    return w;
}

int main()
{
    int N, ns, w;
    vector<int> vA, vR;
    map<int, int> m1, m2;
    map<int, int>::reverse_iterator itR, itA;
    itR = m1.rbegin();
    itA = m2.rbegin();
    cin>>N;
    cin >> ns;
    for (int i = 0; i< ns; i++){
        cin>>w;
        vR.push_back(w);
        m1[w]+=1;
    }
    for (int i = 0; i< ns; i++){
        cin>>w;
        vA.push_back(w);
        m2[w]+=1;
    }
    
    //int maxR = find_max(m1);
    //int maxA = find_max(m2);
    //int maxWR  = max_weight(m1);
    //int maxWA  = max_weight(m2);
    bool check1 = check_same(m1);
    bool check2 = check_same(m2);
    if (check1 == true && check2==true){
        if (itR->first > itA->first){
            cout<<"Rustom"<<endl;
        }
        else if (itR->first < itA->first) 
            cout<<"Anup"<<endl;
        else
            cout<<"Tie"<<endl;
    }
    else if (check1==true && check2 == false){
        int maxWA  = max_weight(m2);
        if (m2[maxWA]>m1[maxWA]){
            cout<<"Anup"<<endl;
        }
        else if (m2[maxWA]<m1[maxWA]){
            cout<<"Rustom"<<endl;
        }
        else 
            cout<<"Tie"<<endl;
        
    }
    else if (check1==false && check2 == true){
        int maxWR  = max_weight(m1);
        if (m2[maxWR]>m1[maxWR])
            cout<<"Anup"<<endl;
        else if (m2[maxWR]<m1[maxWR])
            cout<<"Rustom"<<endl;
        else 
            cout<<"Tie"<<endl;
    }
    else {
        int maxWR  = max_weight(m1);
        int maxWA  = max_weight(m2);
        if (maxWR>maxWA)
            cout<<"Rustom"<<endl;
        else if (maxWR<maxWA)
            cout<<"Anup"<<endl;
        else 
            cout<<"Tie"<<endl;
    }
    
    return 0;
}
