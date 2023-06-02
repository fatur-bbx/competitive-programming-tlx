#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(x) begin(x), end(x)
#define SIZE(x) int((x).size())

struct BIT {
    const int n;
    vector<int> bit;

    BIT(int n_) : n(n_), bit(n, -1){}

    void update(int i, int v){
        for(; i <= n; i |= i+1){
            bit[i] = max(bit[i], v);
        }
    }

    int query(int i){
        int res = -1;
        for(; i >= 0; i = (i & (i+1)) - 1){
            res = max(res, bit[i]);
        }
        return res;
    }
};

struct Compress{
    bool finalized;
    vector<int> v;

    Compress() : finalized(false){}

    void insert(int x){
        assert(!finalized);
        v.emplace_back(x);
    }

    void finalize(){
        finalized = true;
        sort(ALL(v));
        v.erase(unique(ALL(v)), end(v));
    }

    int query(int x){
        assert(finalized);
        auto it = lower_bound(ALL(v), x);
        if(it == end(v) || *it != x) return -1;
        return int(it - begin(v));
    }

    int size(){
        assert(finalized);
        return SIZE(v);
    }
};

void solve(){
    Compress cy;
    int n, q;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto& [x, y] : a){
        cin >> x >> y;
        cy.insert(y);
    }

    cin >> q;
    vector<pair<int, int>> b(q);
    for(auto& [x, y] : b){
        cin >> x >> y;
        cy.insert(y);
    }

    cy.finalize();
    sort(ALL(a));
    vector<int> idx(q);
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](int x, int y){
        return b[x] < b[y];
    });
    BIT bit(cy.size());
    vector<int> ans(q, -1);
    int j = 0;
    for(int i : idx){
        auto [x, y] = b[i];
        while(j < n && a[j].first <= x){
            bit.update(cy.query(a[j].second), a[j].first + a[j].second);
            ++j;
        }

        int res = bit.query(cy.query(y));
        if(~res) ans[i] = x+y-res;
    }
    for(int i : ans) cout << i << "\n";
    cout << flush;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t = 1;
    while(t--) solve();
    return 0;
}