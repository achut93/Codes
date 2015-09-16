#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a ,b;
	cin >> a >> b;
	if(b == 0 && a%2 == 0) {
		cout << setprecision(9) << 1 << endl;
	}
	else if (b %2 != 0) {
		double ans = 1000000001;
		if(b == a) {
			ans = min(ans ,(double) a);
		}
		if ( a > b && (a-b)%2 == 0) {
			ans = min (ans ,(double) b);
		}
		double t = ((a+b)*1.0)/2.0;
		while(t > b && t/2 > b) {
			t /= 2;
		}
		if(t < b) t = 1000000001;
		ans = min(ans , t);
		t = ((a-b)*1.0)/2.0;
		while(t > b && t/2 > b) {
			t /= 2;
		}
		if(t < b) t = 1000000001;
		ans = min(ans , t);
		if(ans == 1000000001)
			cout << -1 << endl;
		else
			cout <<setprecision(9) << ans << endl;
	}
	else {
		cout << setprecision(9) << -1 << endl;
	}
	return 0;
}