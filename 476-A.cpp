#include <bits/stdc++.h>

using namespace std;

int prime [1001];
vector<int> v;

void seive(int n) {
	prime[2] = 0;
	for(int i = 2 ; i*i <= n;i++) {
		for(int j = i*i ; j <= n ;j+=i) {
			prime[j] = 1;
		}
	}
}

int main() {

	int n;
	cin >> n;

	seive(n);

	for(int i = 2 ; i <= n;i++) {
		if(prime[i] == 0) {
			int q = i;
			while(q <= n) {
				v.push_back(q);
				q *= i;
			}
		}
	}

	cout << v.size() << endl;
	for(int i = 0 ; i < v.size() ; i++) {
		cout << v[i] << " ";
	}
}
