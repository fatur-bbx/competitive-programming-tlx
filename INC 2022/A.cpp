#include <bits/stdc++.h>
using namespace std;
const int max_n=200;
int n,m;
int a[max_n+1];
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0;
    int max_team_rating=0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                int team_rating = a[i]+a[j]+a[k];
                int rating_difference = max(a[i],max(a[j],a[k])) - min(a[i],min(a[j],a[k]));
                if(rating_difference<=m){
                    cnt++;
                    max_team_rating = max(max_team_rating, team_rating);
                }
            }
        }
    }

    if(cnt==0){
        cout<<-1<<endl;
    }else{
        cout<<cnt<<" "<<max_team_rating<<endl;
    }
}