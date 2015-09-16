#include <bits/stdc++.h>

using namespace std;

priority_queue < pair <int,int> , vector < pair<int,int> > , greater < pair<int,int> > > pq;

vector <pair <int,int> > v[100001];

int visited[100001];

int cost [100001];

int main() {
	int t;
	cin >> t ;
	int x,y,c;
	while(t--) {
		memset(cost , 0 ,sizeof cost);
		memset(visited , 0 ,sizeof visited);
		pq = priority_queue < pair <int,int> , vector < pair<int,int> > , greater < pair<int,int> > >();
		
			int n,m,q;
			cin >> n >> m;
		for(int i = 0 ; i <= n ;i++) {
			v[i].clear();
		}
			for(int i = 0 ; i < m ;i++) {
				cin >> x >> y >> c;
				v[x].push_back({y,c});
				v[y].push_back({x,c});
			}
		for(int i = 0 ;i < v[1].size() ; i++) {
			pq.push({v[1][i].second , v[1][i].first});
		}
		visited[1] = 1;
		while(!pq.empty()) {
			pair<int,int> t = pq.top();
			pq.pop();
			if(visited[t.second]) continue;
			visited[t.second] = 1;
			cost[t.second] = t.first;
			for(int i = 0 ; i < v[t.second].size() ; i++) {
				pq.push({t.first+ v[t.second][i].second , v[t.second][i].first });
			}
		}
		cin >> q;
		while(q--) {
			cin >> x >> y;
			int ans = max(y - cost[x]*2,0);
			cout << ans << endl;
		}
	
	}
	return 0;
}