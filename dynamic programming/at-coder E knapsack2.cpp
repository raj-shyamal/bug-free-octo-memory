#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, W;
int w[101];
int v[101];
int dp[101][100000];

int rec(int i, int sumVal){
	if(sumVal<0){
		return INT_MAX;
	}
	if(sumVal==0){
		return 0;
	}

	if(i==n){
		return INT_MAX;
	}
	if(dp[i][sumVal]!=-1){
		return dp[i][sumVal];
	}
	int ans = min(rec(i+1, sumVal), rec(i+1, sumVal-v[i])+w[i]);
	return dp[i][sumVal] = ans;

}

void solve(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
    	cin>>w[i]>>v[i];
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i<=1e5;i++){
    	if(rec(0, i)<=W){
    		ans = i;
    	}
    }

    cout<<ans<<'\n';
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	//int _t;cin>>_t;while(_t--)
	solve();
}
