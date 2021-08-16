#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, p, k;
    cin>>n>>p>>k;
    int ans = 0;
    int q = p%k;
    q--;
    int s = (((n-1)/k)*k);
    s = n-1-s;
    if(q>s){
    	ans+=(s+1)*((n-1)/k+1)+(q-s)*((n-1)/k);
    }
    else{
    	ans+=((n-1)/k+1)*(q+1);
    }
    for(int i=q+1;i<=n-1;i+=k){
    	ans++;
    	if(i==p){
    		cout<<ans<<'\n';
    		break;
    	}
    }
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
