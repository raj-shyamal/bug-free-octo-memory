#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
int h[100100];

int dp[100100];
bool done[100100];

int rec(int i){
    if(i<0){
        return 0;
    }
    if(i==0){
        return 0;
    }
    if(done[i]){
        return dp[i];
    }
    int ans = INT_MAX;
    for(int j = i-k; j<= i-1; j++){
        if(j>=0){
            int cost = rec(j)+abs(h[i] - h[j]);
            ans = min(ans, cost);
        }
    }
    done[i] = 1;
    return dp[i] = ans;

}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(done, 0, sizeof(done));
    cout<<rec(n-1)<<'\n';
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//int _t;cin>>_t;while(_t--)
	solve();
}
