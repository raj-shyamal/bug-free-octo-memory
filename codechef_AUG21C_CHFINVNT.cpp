#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, p, k;
    cin>>n>>p>>k;
    int ans;
    if((n-1)%k!=0)
    	ans = (p%k)*((n+k-1)/k) + ((p/k)+1);
    else{
    	if(p%k==0){
    		ans = p/k +1;
    	}
    	else{
    		ans = ((n-1)/k +1)+(p%k-1)*((n+k-1)/k) + ((p/k)+1);
    	}
    }
    cout<<ans<<'\n';
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
