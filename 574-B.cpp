#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int cnt[4001];
vector <int> v[4001];

int vi[4001];

int dd(int idx , int depth ,int original) {
	if(depth == 3) {
		if(idx == original) {
			cout << "hello " << idx << endl;
			return 0;
		}
		else {
			return 1 << 30;
		}
	}
	if(vi[idx] == 1)
		return 1<<30;

	vi[idx] = 1;
	int ans = 1 << 30;
	for(int i = 0; i < v[idx].size() ;i++) {
			ans = min (ans , dd(v[idx][i],depth+1,original));
	}
	return ans+cnt[idx];
}
int dfs(int idx) {

	memset(vi,0,sizeof vi);
	return dd(idx,0,idx);
}

int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < m ;i++) {
		int a,b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		cnt[a]++;
		cnt[b]++;
	}

	int ans = 1 << 30;

	for(int i = 1 ; i<= n;i++) {
		int boo = dfs(i);
		//cout << boo << endl;
		ans = min(ans,boo);
	}
	if( ans < (1 << 30))
		cout << ans-6 << endl;
	else
		cout << -1 << endl;
	return 0;
}
