#include <bits/stdc++.h>
using namespace std;
const int maksimalBanyak=1000005;
bool ketemuKau[maksimalBanyak];
int main(){
    int N,M,A;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>A;
        ketemuKau[A]=1;
    }
    long long ans = 0;
    for(int i = 1; i <= N; i++){
        if(ketemuKau[i]!=1){
            ans+=2*(i- pow(2,floor(log2(i))));
        }
    }
    cout<<ans<<"\n";
    cin.get();
}