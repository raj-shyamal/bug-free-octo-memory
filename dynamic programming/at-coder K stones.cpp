#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, k;
int a[100];
int dp[100100];

int rec(int x){
	if(dp[x]!=-1){
		return dp[x];
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(x>=a[i]&&rec(x-a[i])==0){
			ans = 1;
			break;
		}
	}
	return dp[x] = ans;
}

void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}    
	memset(dp, -1, sizeof(dp));
	int value = rec(k);
	if(value)
		cout<<"First\n";
	else
		cout<<"Second\n";

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
