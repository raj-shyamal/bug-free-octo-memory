#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int dp[10010][4];
int rec(int index, int match){
	if(index==n){
		return 1;
	}
	if(dp[index][match]!=-1){
		return dp[index][match];
	}

	if(match==0){
		return dp[index][match] = rec(index+1, 1)+rec(index+1, 0);
	}
	else if(match==1){
		return dp[index][match] = rec(index+1, 1)+rec(index+1, 2);
	}
	else if(match==2){
		return dp[index][match] = rec(index+1, 3)+rec(index+1, 0);
	}
	else{
		return dp[index][match] = rec(index+1, 2);
	}
}

void solve(){
	cin>>n;
	cout<<rec(0, 0)<<endl;
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