#include <iostream>
using namespace std;

int dp[101][101][102];
int special[101][101];

int main()
{
	int n, m , k;
	cin >> n >> m >> k;
	int x,y;
	for(int i = 0 ; i < k ; i++) {
		cin >> x >> y ;
		special[x][y] = 1;
	}
	dp[1][1][1+special[1][1]] = 1;
   // cout << 1+special[1][1] << endl;
   for(int l = 1 ; l <= k+1 ;l++)
    for(int i = 1 ; i <= n ;i++) 
    	for(int j = 1; j <= m ;j++)  {
    			if(special[i][j] == 1){
    				dp[i][j][l] += dp[i-1][j][l-1]+dp[i][j-1][l-1];
    			}
    			else {
    				dp[i][j][l] += dp[i-1][j][l]+dp[i][j-1][l];
    			}
    		}
    		
//    for(int i = 1 ; i <= n ;i++) 
// 	{
// 		for(int j = 1; j <= m ;j++) 
//    	{
//    		cout << dp[i][j][1] << " ";
//    	}
//    	cout << "" << endl;
//	}
    
    for(int i = 1; i <= k+1 ;i++) {
    	cout << dp[n][m][i] << " ";
    }
    
    return 0;
}
