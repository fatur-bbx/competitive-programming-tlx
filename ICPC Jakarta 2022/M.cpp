#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const ll LINF = LLONG_MAX;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    string out = "";
    cin>>n>>m;
    ll a[n+5],b[n+5];
    ll pa[n+5], pb[n+5];
    pa[0] = pb[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pa[i]=pa[i-1]+a[i];
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        pb[i] = pb[i-1] + b[i];
        if(a[i] + b[i] < 0) ok = false;
    }
    if(pa[n]<0 || pb[n]<0) ok = false;
    for(int i = 0; i < m; i++){
        int l,r;
        cin>>l>>r;
        if(!ok){
            cout<<"flawed"<<endl;
            continue;
        }
        ll ans = LINF;
        if(l == r)ans=0;
        else if(l<r)ans=min(pa[r-1] - pa[l-1], pb[l-1] + pb[n] -pb[r-1]);
        else ans = min(pb[l-1] - pb[r-1], pa[r-1] + pa[n] - pa[l-1]);
        out+= to_string(ans)+"\n";
    }
    cout<<out<<endl;
    return 0;
}