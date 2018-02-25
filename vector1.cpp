#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//vector<int> change(vector<int>);

int main(){
    
    //cout<<v.size()<<" ";
    //v = v(20);
    //cout<<v.size()<<" ";
    //for (int i = 0; i< 10; i++){
    //    vector<int> v(i);
    //    vector<int>::iterator it = v.begin();
    //    cout<<&it<<" "<<v.size()<<endl;
    //}

    vector<vector<int> > v(6, vector<int>(9, 20));
    for (int i = 0; i< 6; i++){
        for (int j = 0; j< 9; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
    /*
    deque<int> d;
    for (int i = 1; i<5; i++){
        d.push_back(i);
    }
    for (int i = 0; i<d.size(); i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    d.push_front(10);
    //d.pop_back();
    //d.pop_back();
    d.pop_front();
    d.pop_front();
    for (int i = 0; i<d.size(); i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    return 0;
    */
}

/*
int main(){
    //cout<<"Dude";
    
    deque< vector<int> > dq;
    
    vector<int>  v;
    
    for (int i = 0; i<3; i++){
        v.push_back(i);
    }
    
    cout<<v.size();
    
    dq.push_back(v);
    
    v.resize(0);
    
    for (int i = 10; i<13; i++){
        v.push_back(i);
    }
    
    //cout<<"Dude";
    
    //v.clear();
    
    dq.push_back(v);
    
    while(!dq.empty()){
        v = dq.front();
        cout<<v[0];
        dq.pop_front();
    }

    vector<vector<int> >v(3);
    int a = 5;
    v[0].push_back(a);
    v[0].push_back(20);
    v[1].push_back(10);
    v[1].push_back(33);
    v[1].push_back(31);
    v[1].push_back(35);
    v[1].push_back(38);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    v[2].push_back(85);
    cout<<v.size() << " "<< v[0].size() << " " <<  v[1].size() << " " << v[2].size()<<endl;

    return 0;
    
}

vector<int> change(vector<int> v){
    vector<int>::iterator it;
    for (it = v.begin(); it<=v.begin()+2; it++){
        v.push_back(100);
    }
    return v;
}
*/