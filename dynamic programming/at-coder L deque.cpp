#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[3000];

int dp[3000][3000];
bool done[3000][3000];

int rec(int l, int r){
	if(l>r){
		return 0;
	}
	if(done[l][r]){
		return dp[l][r];
	}

	dp[l][r] = max(a[l] - rec(l+1, r), a[r] - rec(l, r-1));
	done[l][r] = 1;

	return dp[l][r];
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(done, 0, sizeof(done));
	cout<<rec(0, n-1)<<'\n';

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
