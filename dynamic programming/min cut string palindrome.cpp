#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
string s;


int dp1[1010][1010];
int rec1(int l, int r){
	if(l>=r){
		return 1;
	}
	if(dp1[l][r]!=-1){
		return dp1[l][r];
	}
	int ans = 0;
	if(s[l-1]==s[r-1]&&rec1(l+1, r+1)) ans = 1;
	return dp1[l][r] = ans;
}

int dp2[1010];
int rec2(int i){
	if(i==0){
		return -1;
	}
	if(dp2[i]!=-1){
		return dp2[i];
	}
	int ans = 1e9;
	for(int j = 0;j<i;j++){
		if(rec1(j+1, i)){
			ans = min(ans, rec2(j)+1);
		}
	}
	return dp2[i] = ans;
}


void solve(){
    cin>>n;
    cin>>s;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    cout<<rec2(n)<<'\n';
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
