#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<pair<long long,long long>> pq;
    int n; cin>>n;
    while(n--){
        long long x;cin>>x;
        pq.push({-(x & -x), x});
    }

    while((int) pq.size() > 1){
        long long a = pq.top().second;pq.pop();
        long long b = pq.top().second;pq.pop();
        long long x = __gcd(a,b) * 2;
        pq.push({-(x & -x), x});
    }
    cout<<pq.top().second<<endl;
}