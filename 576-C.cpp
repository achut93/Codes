#include <bits/stdc++.h>

using namespace std;

vector <pair <int , int> > v[1000001];

int main() {
	int n;
	cin >> n;
	int x,y;
	for(int i = 0 ; i< n;i++) {
		scanf("%d %d",&x,&y);
		v[x/1000].push_back({y,i});
	}
	int j = 0;
	for(int i =0 ; i < 1000001 ; i++) {
		if(v[i].size() == 0)
			continue;
		sort(v[i].begin(),v[i].end());
		if(j == 0) {
			for(int k = 0 ;k <v[i].size();k++) {
				printf("%d ",v[i][k].second+1);
			}
		}
		else {
			for(int k = v[i].size()-1 ;k >= 0;k--) {
				printf("%d ",v[i][k].second+1);
			}
		}
		j = 1-j;
	}
	return 0;
}
