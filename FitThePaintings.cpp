#include <iostream>
using namespace std;

int main()
{
    int n,m,a,b,c,d;
    cin >> n >> m>> a >> b >> c >> d;
    if((n-a >= c && m >= d && m >= b) || (m-b >= d && n >= c && n >= a) || (n-a >= d && m >= c && m >= a) || (m-b >= c && n >= d && n >= b) ||
    	(n-b >= c && m >= d && m >= a) || (m-a >= d && n >= c && n >= b) || (n-b >= d && m >= c && m >= a) || (m-a >= c && n >= d && n >= b)
    ) {
    	cout << "Yes" << endl;
    }
    else
    cout << "No" << endl;
    
    return 0;
}
