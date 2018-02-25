#include<iostream>
#include<cstring>
#include<vector>


using namespace std;

int main(){
    //int ar[10]={};
    vector<string> v;
    v.push_back("Dude");
    v.push_back("Sir");
    cout<<v[0];
    string a = "Siri";
    for (int i = 0; i< 2; i++){
        if (v[i]== a){
            cout<<"Yes"<<endl;
        }
    }
    /*
    int ap[5][5];
    memset(ap, 0, sizeof(ap[0][0])*5*5);
    for (int i = 0; i<5; i++){
        for (int j = 0; j < 5; j++){
            cout<<ap[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    /*
    string s2;
    int a, b;
    char s1[10] = "Dude Sidd";
    cout<<s1<<endl;
    //cin>>s1;
    //cout<<s1<<endl;
    //cout<<s1[6]<<endl;
    //cin.ignore();
    //cin.getline(s1, 10);
    cin.get(s1, 20);
    cout<<s1<<endl;
    cin.ignore();
    cin.get(s1, 20);
    cout<<s1<<endl;
    cin>>s2;
    cout<<s2<<endl;
    */ 
    return 0;
}