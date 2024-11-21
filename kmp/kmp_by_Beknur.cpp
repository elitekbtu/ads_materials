#include <bits/stdc++.h> 
using namespace std; 
 
 
vector<int>computefunction(string &pattern){ 
    int m=pattern.size(); 
    vector<int>pi(m,0); 
    int k=0; 
    for(int i=1;i<m;i++){ 
        while(k>0&&pattern[i]!=pattern[k]){ 
            k=pi[k-1]; 
        } 
        if(pattern[i]==pattern[k]){ 
            k++; 
        } 
        pi[i]=k; 
    } 
    return pi; 
} 
void kmp(string& text,string& pattern){ 
    int n=text.size(); 
    int m=pattern.size(); 
    vector<int>pi=computefunction(pattern); 
    int j=0; 
    for(int i=0;i<n;i++){ 
        while(j>0&&text[i]!=pattern[j]){ 
            j=pi[j-1]; 
        } 
        if(text[i]==pattern[j]){ 
            j++; 
        } 
        if(j==m){ 
            cout<<i-m+1<<"\n"; 
            j=pi[j-1]; 
 
        } 
    } 
} 
int main(){ 
 
string a,b; 
cin>>a>>b; 
kmp(a,b); 
 
}