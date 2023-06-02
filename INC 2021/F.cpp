#include "bits/stdc++.h"
using namespace std;

bool cek(string x){
    int idx=0;
    while(idx<=x.length()/2){
        if(x[idx] != x[x.length()-1-idx]){
            return false;
        }
        idx++;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    string tmp = s, tmp1, tmp2;
    string a,b;
    bool d =0;
    for(int i = 1; i < s.length(); i++){
        tmp = s;
        a = tmp.substr(0,i);
        b = tmp.erase(0,i);
        if(cek(a) && cek(b)){
            d=1;
            tmp1=a;
            tmp2=b;
        }
    }
    if(d){
        cout << tmp1 << " " << tmp2;
    }else{
        cout << "NO\n";
    }
}