#include <bits/stdc++.h>
#define intmax INT_MAX
#define lli LONG_LONG_MAX
#define mod 1000000007
#define MAXN 200005
#define ll long long
#define deb(x) cerr<<"[ "<<#x<<" = "<<x<<" ]"
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
using namespace std;
ll n,k,m,p,q,ans,l,r,x,y,z;
bool vis[MAXN];
long double dist[MAXN];
vector<vector<ll>> adj[MAXN];
ll a[MAXN];
ll val[4*MAXN];
ll cur = 0;
ll foo = 0;
string s;
void dfs(ll xx){
    foo += adj[xx].size();
    vis[xx]=1;
    cur++;
    for(auto a : adj[xx]){
        if(!vis[l]){
            dfs(l);
        }
    }
}
ll f(ll x){
    ll res=1;
    while(res-1<=x)res*=2;
    return res-1;
}
void solve(){
    cin>>n>>k;
    ll a[k];
    ll ans = -intmax;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin>>a[j];
        }
        ans = max(ans,*min_element(a,a+k));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    for(int i = 0; i < T; i++){
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}