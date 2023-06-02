#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int pow(int a, int b){
    if(b==0){
        return 1;
    }
    int res = ((pow(a,b/2)%mod)*(pow(a,b/2)%mod));
    if(b&1) res = ((res%mod)*(a%mod))%mod;
    return res%mod;
}

void solve(){
    int N, X, Y;cin>>N>>X>>Y;
    cout << pow(X+Y, N)%mod << endl;
}

signed main()
{
    int T; cin >> T;
    while(T--) solve();
}