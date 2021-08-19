#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, W;
int w[101], v[101];

int dp[101][100100];

int rec(int i, int left){
    if(i==n){
        if(left<0){
            return INT_MIN;
        }
        else
            return 0;
    }
    if(dp[i][left]!=-1){
        return dp[i][left];
    }
    int ans;
    if(left-w[i]>=0){
        ans = max(rec(i+1, left), rec(i+1, left-w[i])+v[i]);
    }
    else {
        ans = rec(i+1, left);
    }
    return dp[i][left] = ans;
}

void solve(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, W)<<'\n';
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//int _t;cin>>_t;while(_t--)
	solve();
}
