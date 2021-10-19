#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[505];

int dp[505][505];

int rec(int l, int r){
	if(l==r){
		return 0;
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	int ans = 0;
	int tot = 0;
	int sum = 0;
	for(int mid = l;mid<=r;mid++){
		tot+=arr[mid];
	}

	for(int mid = l;mid<r;mid++){
		sum+=arr[mid];
		ans = max(ans, rec(l, mid)+rec(mid+1, r)+(sum%100)*((tot-sum)%100));
	}
	return dp[l][r]=ans;
}


void solve(){
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int _t;cin>>_t;while(_t--)
	solve();
}