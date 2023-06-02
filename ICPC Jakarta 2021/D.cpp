#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n,m,total=0,temp=0;
    cin>>n>>m;
    int freq[m][26]={};
    for(int i =0; i<n;i++){
        cin>>s;
        for(int j=0; j < m; j++){
            freq[j][s[j]-'a']++;
        }
    }
    for(int i =0; i<m;i++){
        for(int j =0; j <26;j++){
            temp=max(temp,freq[i][j]);
        }
        total+=n-temp;
        temp=0;
    }
    cout<<total;
}