#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
double p[3000];
double dp[3000][3000];
bool done[3000][3000];

double rec(int i, int nheads){
	if(i==n){
		if(nheads>n-nheads){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(done[i][nheads]){
		return dp[i][nheads];
	}

	dp[i][nheads] = (1.0 - p[i])*rec(i+1, nheads)+p[i]*rec(i+1, nheads+1);
	done[i][nheads] = 1;

	return dp[i][nheads];
}

void solve(){
    cin>>n;
    for(int i = 0;i<n;i++){
    	cin>>p[i];
    }
    memset(done, 0, sizeof(done));
    cout<<fixed<<setprecision(15)<<rec(0, 0)<<'\n';

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
