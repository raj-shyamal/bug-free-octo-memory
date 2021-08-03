#include<bits/stdc++.h>
using namespace std;

string s, t;
int dp[3030][3030];
int back[3030][3030];
string str;

int rec(int i, int j){
    if(i==s.length()||j==t.length()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;
    if(s[i]==t[j]){
        ans = max(rec(i+1, j+1)+1, max(rec(i+1, j), rec(i, j+1)));
    }
    else{
        ans = max(rec(i+1, j), rec(i, j+1));
    }

    return dp[i][j] = ans;
}


void solve(){
	cin>>s>>t;
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
