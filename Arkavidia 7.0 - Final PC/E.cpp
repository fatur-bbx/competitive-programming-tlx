#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define udd unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ipii pair<ll, pii>
#define fi first
#define se second
#define psi pair<string , ll>
#define pci pair<char, ll>
#define pic pair<ll, char>
ll a[509], lis[509][509], b[509][509], n;
void bfs(ll idx){
    a[idx] = 0;
    queue<ll> q;
    q.push(idx);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(i == cur) continue;
            if(lis[cur][i] != -1){
                ll nxtVal = (a[cur]^lis[cur][i]);
                if(a[i] != -1 && a[i] != nxtVal){
                    cout << "NO" << endl;
                    exit(0);
                }
                if(a[i] == -1){
                    a[i] = nxtVal;
                    q.push(i);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == -1){
            bfs(i);
            return;
        }
    }
}

void PreCompute(){
    for(int i = 1; i <= n; i++){
        if(b[i][i] != -1 && b[i][i] != 0){
            cout<<"NO"<<endl;
            exit(0);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ll st = b[i][j], dw = b[j][i];
            if(st == -1 && dw == -1) lis[i][j] = -1;
            else if(st==-1 && dw != -1) lis[i][j] = dw;
            else if(st!=-1 && dw == -1) lis[i][j] = st;
            else {
                if(st != dw){
                    cout<<"NO"<<endl;
                    exit(0);
                }else{
                    lis[i][j] =st;
                }
            }
        }
    }
}

void input(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j = 1; j <= n; j++) cin>>b[i][j];
}

void solve(){
    PreCompute();
    memset(a, -1, sizeof(a));
    bfs(1);
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    ll tc = 1;

    while(tc--){
        input();
        solve();
    }
}