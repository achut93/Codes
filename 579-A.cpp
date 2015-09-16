#include <bits/stdc++.h>

using namespace std;

int a[] = {0,1,1,2,1,2,2,3,1,2};

int main() {
    int n;
    cin >> n;
    if(n < 10) {
        cout << a[n] << endl;
    }
    else {
        int ans = 0;
        while(n >= 10) {
            if(n%2 == 0) n /= 2;
            else {
                n--;
                ans += 1;
            }
        }
        if( n > 0 && n < 10) ans += a[n];
        cout << ans << endl;
    }
    return 0;
}