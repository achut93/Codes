#include <bits/stdc++.h>
using namespace std;

vector < pair <pair<int ,int> , int> > v;

int a[1000];

bool comp (pair <pair<int ,int> , int> l , pair <pair<int ,int> , int> r ) {

	return l.second > r.second;
	
}
int main() {
	int n;
	int x;
	cin >> n;
	for(int i = 2 ; i <= 2*n ;i++) {
		for(int j = 1; j < i ;j++) {
			cin >> x;
			v.push_back( { {i,j} ,x });
		}
	}
	sort(v.begin(), v.end() , comp);
	for(int i = 0 ; i < v.size(); i++) {
		if(a[v[i].first.first] == 0  && a[v[i].first.second] == 0 ) {
			a[v[i].first.first] = v[i].first.second;
			a[v[i].first.second] = v[i].first.first;
		}
	}
	for(int i = 1 ; i <= 2*n ;i++) {
		cout << a[i] << " ";
	}
	return 0;
}