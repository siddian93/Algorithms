#include<iostream>

using namespace std;

class Dude{
    private:
        int a; 
        void print(int val);
    public:
        void get_val();
        void set_val();
};



void Dude::print(int val){
    cout<<val<<"IN PRIVATE"<< endl;
}

void Dude::get_val(){
    int p;
    cin>>p;
    a = p;
}

void Dude::set_val(){
    print(a);
}


int main(){
    Dude d;
    Dude* nd  = new Dude();
    d.get_val();
    d.set_val();
    nd->get_val();
    nd->set_val();
    delete(nd);
    return 0;
}