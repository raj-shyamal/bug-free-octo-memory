#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9+7;
int H, W;
char a[1010][1010];

int dp[1000][1000];

int rec(int i, int j){
	
	if(i==H-1&&j==W-1){
		return 1;
	}
	if(i==H-1&&a[i][j+1]=='#'){
		return 0;
	}
	if(j==W-1&&a[i+1][j]=='#'){
		return 0;
	}
	if(i!=H-1 && j!=W-1){
		if(a[i+1][j]=='#'&&a[i][j+1]=='#'){
			return 0;
		}
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}


	if(i==H-1||j==W-1){
		if(i==H-1){
			dp[i][j] = rec(i, j+1);
		}
		if(j==W-1){
			dp[i][j] = rec(i+1, j);
		}
	}else{
		if(a[i+1][j]=='.'&&a[i][j+1]=='.'){
			dp[i][j] = (rec(i+1, j)+rec(i, j+1))%mod;
		}
		else if(a[i+1][j]=='.'){
			dp[i][j] = rec(i+1, j);
		}
		else if(a[i][j+1]=='.'){
			dp[i][j] = rec(i, j+1);
		}

	}
	return dp[i][j];

}



void solve(){
    cin>>H>>W;
    for(int i=0;i<H;i++){
    	for(int j = 0;j<W;j++){
    		cin>>a[i][j];
    	}
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, 0)<<'\n';

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
