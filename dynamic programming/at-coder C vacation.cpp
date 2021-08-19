#include<bits/stdc++.h>
using namespace std;

int n;
int a[100100], b[100100], c[100100];

int dp[100100][3];

int rec(int i, int j){
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 0;
    if(j==1){
        ans = max(rec(i+1, 2)+a[i], rec(i+1, 3)+a[i]);
    }
    else if(j==2){
        ans = max(rec(i+1, 1)+b[i], rec(i+1, 3)+b[i]);
    }
    else if(j==3){
        ans = max(rec(i+1, 2)+c[i], rec(i+1, 1)+c[i]);
    }
    return dp[i][j] = ans;

}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<max(max(rec(0, 1), rec(0, 2)), rec(0, 3))<<'\n';
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//int _t;cin>>_t;while(_t--)
	solve();
}
