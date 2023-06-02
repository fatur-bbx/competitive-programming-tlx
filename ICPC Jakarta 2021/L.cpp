#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
const int maxN=1e5+5;
const pair<ll,int> cv={-1e18,-1e9};
struct SegmentTree{
    priority_queue<pair<ll,int>> st[4*maxN];
    bool exist[maxN];
    void reset(){
        fill(exist,exist+maxN,true);
    }
    void add(int v, int curL, int curR, int l, int r, pair<ll, int> val){
        if(curL>curR||l>r)return;
        if(curL==l&&curR==r){
            st[v].push(val);
            return;
        }
        int curM=(curL+curR)>>1;
        add(2*v+1,curL,curM,l,min(curM,r),val);
        add(2*v+2,curM+1,curR,max(l,curM+1),r,val);
    }
    void remove(int v, int curL, int curR, int l, int r, pair<ll, int> val){
        if(curL>curR||l>r)return;
        if(curL==l&&curR==r){
            return;
        }
        int curM=(curL+curR)>>1;
        remove(2*v+1,curL,curM,l,min(curM,r),val);
        remove(2*v+2,curM+1,curR,max(l,curM+1),r,val);
    }
    pair<ll,int>query(int v,int curL, int curR, int l, int r){
        if(curL>curR||l>r)return cv;
        if(curL==l&&r==curR){
            while(!st[v].empty()&&!exist[st[v].top().second]){
                st[v].pop();
            }
            return (!st[v].empty() ? (st[v].top()):cv);
        }
        int curM=(curL+curR)>>1;
        while(!st[v].empty()&&!exist[st[v].top().second]){
            st[v].pop();
        }
        pair<ll, int> ans = (!st[v].empty()?(st[v].top()):cv);
        ans=max(ans,query(2*v+1,curL,curM,l, min(curM,r)));
        ans=max(ans,query(2*v+2,curM+1,curR,max(l,curM+1),r));
        return ans;
    }
}segtree;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    segtree.reset();
    int n,k,d;
    cin>>n>>k>>d;
    int h[n];
    for(int x=0;x<n;x++){
        cin>>h[x];
    }
    int t[n];
    for(int x=0;x<n-1;x++){
        cin>>t[x];
    }
    vector<pair<ll,int>>v[n+1];
    segtree.add(0,0,k-1,0,k-1,{h[0],0});
    v[t[0]+1].push_back({h[0],0});
    ll ans = -1e18;
    for(int x=1;x<n;x++){
        for(auto p:v[x]){
            segtree.exist[p.second]=false;
        }
        ll val = segtree.query(0,0,k-1,x%k,x%k).first;
        val=max(val,segtree.query(0,0,k-1,x%k,x%k).first);
        val-=(x/k)*d;
        val+=h[x];
        if(x==n-1){
            cout<<val<<"\n";
            break;
        }
        segtree.add(0,0,k-1,x%k,k-1,{val+(x/k)*d,x});
        segtree.add(0,0,k-1,0,(x%k)-1,{val+(x/k)*d+d,x});
        v[x+t[x]+1].push_back({val,x});
    }
    return 0;
}