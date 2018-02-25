#include <iostream>
using namespace std;

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

struct Node* create_node(int x){
     struct Node* new_node = new Node;
      new_node->val = x;
      new_node->left = NULL;
      new_node->right = NULL;
      return new_node;
 }

void insert_node(int val, string s, Node* root){
    if (root == NULL){
         root  = create_node(val);
    }
    Node* temp= root;
    Node* new_node = create_node(val);
    for (int i = 0; i< s.size()-1; i++){
        if (s[i] == 'L'){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if (s[s.size()-1] == 'L'){
        temp->left = new_node;
    }
    else {
        temp->right = new_node;
    }
}

void inorder(Node* node){
    if (node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->val<<'\t';
    inorder(node->right);
}

int max(int a, int b){
    return (a>b?a:b);
}

int find_diameter(Node* node, int *d){
    if (node==NULL)
        return 0;
    int lh=0, rh= 0, temp = 0;
    lh = find_diameter(node->left, d);
    rh = find_diameter(node->right, d);
    temp  = lh+rh+1;
    if (temp>*d){
        *d = temp;
    }
    return max(lh, rh)+1;
}

int main(){
    int T, X, n, d = 0;
    string s;
    cin>>T>>X;
    n = 2*(T-1);
    struct Node* root = create_node(X);
    //cout<<root->val<<endl;
    for (int i = 0; i<n; i++){
        cin>>s;
        cin>>X;
        insert_node(X, s, root);
    }
    //cout<<"Printing ...."<<endl;
    //inorder(root);
    find_diameter(root, &d);
    cout<<d;
    return 0;
}
