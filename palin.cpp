#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void next_palin1(string &s, int N){
    if (N%2 !=0)
        s[N/2]+=1;
    else {
        s[N/2-1] +=1;
        s[N/2] +=1;
    }
}

bool all9s(string& s){
    for (int i = 0; i< s.length(); i++){
        if (s[i]!='9'){
            return false;
        }
    }
    return true;
}

void next_palin(string &s, int N){
    int mid  = N/2, i = 0;
    bool f = 0;
    if (N%2 != 0){
        
        while(!f && i<=mid){
            if (s[mid-i]<s[mid+i]){
                s[mid-i]+=1;
                s[mid+i] = s[mid-i];
                f = 1;
            }
            if (s[mid-i]>s[mid+i]){
                s[mid+i] = s[mid-i];
                f = 1;
            }
            if (s[mid-i]==s[mid+i]){
                i++;    
            }    
        }
        if (f){
            for (int j = 0; j< i; j++){
                s[s.length()-j-1]=s[j];
            }
        }
    }
    
    else {
        mid-=1;
        while(!f && i<=mid){
            if (s[mid-i] == s[mid+i+1]){
                i++;
            }
            if (s[mid-i]>s[mid+i+1]){
                //s[mid-i] = s[mid+1+i];
                s[mid+i+1] = s[mid-i];
                f = 1;
            }
            if (s[mid-i]<s[mid+i+1]){
                s[mid-i] += 1;
                s[mid+i+1] = s[mid-i];
                f = 1;
            }
            
        }
        if (f){
            for (int j = 0; j< mid-i; j++){
                s[s.length()-1-j]=s[j];     
            }
        }
    }
}

bool isPalin(string& s, int N){
    for (int i = 0; i<=N/2; i++){
        if (s[i]!=s[N-1-i]){
            return false;
            
        }
    }
    return true;
}

int main() {
    int N;
    cin>>N;
    while(N){
        string s;
        cin>>s;
        //cout<<s<<endl;
        if (!isPalin(s, s.length())){
            next_palin(s, s.length());
            cout<<s;
        }
        else {
            if (!all9s(s)){
                next_palin1(s, s.length());
                cout<<s;
            }
            else {
                cout<<'1';
                for (int i = 0; i<s.length()-1; i++){
                    cout<<'0';
                }
                cout<<'1';
            }
        }
        cout<<endl;
        
        N--;
    }
	
	return 0;
}
