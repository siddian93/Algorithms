#include<iostream>
#include<map>

using namespace std;

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
/*
void find_code(node* n){
    if (n->left==NULL && n->right==NULL){
        m1[code] = n->data;
        m2[n->data]  = code;
        
    }
    if (n->left!=NULL){
        code+='0';
        find_code(n->left);
        code.pop_back();
        if (n->right!=NULL){
            code+='1';
            find_code(n->right);
            code.pop_back();
        }
    }
}


void decode_huff(node * root,string s)
{
    find_code(root);
    //cout<<m2['A'];
    //cout<<s;
    string op="", ss="";
    for (int i = 0; i<s.size(); i++){
        ss = "";
        for (int j=1; j<s.size()-i;j++){
            ss+=s.substr(i, j);
            if (m1.find(ss)!=m1.end()){
                op+=m1[ss];
                break;
            }
        }
    }
    cout<<op<<endl;
}
*/
int main(){
    const char* s = "Dude";
    s  = "Yes";
    *(s+1) = 'D';
    //s2[0]  = 'P';
    cout<<s[1]<<endl;
    return 0;
}