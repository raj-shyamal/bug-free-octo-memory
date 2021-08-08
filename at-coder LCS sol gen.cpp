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
        if(rec(i+1, j+1)+1>rec(i+1, j) && rec(i+1, j+1)+1>rec(i, j+1)){
            back[i][j] = 3;
        }
        else if(rec(i+1, j)>rec(i, j+1)){
            back[i][j] = 1;
        }
        else{
            back[i][j] = 2;
        }
    }
    else{
        ans = max(rec(i+1, j), rec(i, j+1));
        if(rec(i+1, j)>rec(i, j+1)){
            back[i][j] = 1;
        }
        else{
            back[i][j] = 2;
        }
    }

    return dp[i][j] = ans;
}

void generate(int i, int j){
    if(i==s.length()||j==t.length()){
        return;
    }

    if(back[i][j]==1){
        generate(i+1, j);
    }
    else if(back[i][j]==2){
        generate(i, j+1);
    }
    else if(back[i][j]==3){
        str += s[i];
        generate(i+1, j+1);
    }
}


void solve(){
	cin>>s>>t;
    memset(dp, -1, sizeof(dp));
    memset(back, -1, sizeof(back));
    str = "";
    int ans = rec(0, 0);
    generate(0, 0);
    cout<<str<<'\n';
    
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
