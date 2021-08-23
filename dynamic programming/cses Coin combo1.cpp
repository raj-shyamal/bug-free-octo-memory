#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, x;
int c[100];
int const mod = 1e9+7;

int dp[1000000];
bool done[1000000];

int rec(int left){
	if(left==0){
		return 1;
	}
	if(left<0){
		return 0;
	}
	if(done[left]){
		return dp[left];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans=(ans+rec(left-c[i]))%mod;
	}
	done[left] = 1;
	return dp[left] = ans;

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//int _t;cin>>_t;while(_t--)
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	memset(done, 0, sizeof(done));
	cout<<rec(x)<<'\n';
}
