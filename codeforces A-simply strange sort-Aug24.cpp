#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[1010];

void f(int i){
	if(a[i]>a[i+1]){
		int temp = a[i+1];
		a[i+1] = a[i];
		a[i] = temp;
	}
}

bool arraySortedOrNot(){
    if (n == 0 || n == 1)
        return true;
 
    for (int i = 1; i < n; i++)
        if (a[i - 1+1] > a[i+1])
            return false;
 
	return true;
}

void solve(){
    
    cin>>n;
    
    for(int i=0;i<n;i++){
    	cin>>a[i+1];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
    	if(arraySortedOrNot()==1){
    		break;
    	}
    	else if(arraySortedOrNot()==0){
    		ans++;
    	}

    	if(i%2==1){
    		for(int j=1;j<n;j+=2){
    			f(j);
    		}
    	}
    	else if(i%2==0){
    		for(int j=2;j<n;j+=2){
    			f(j);
    		}
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