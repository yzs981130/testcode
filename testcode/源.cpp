#include <iostream>
using namespace std;
int main()
{
	//dp[i]为花费为i时最少花费钱数，c[i]为第i种钱的最大个数，ans[i][j]为价格为i时花了j种货币的值
	//init
	memset(dp, -1, sizeof(dp));
	memset(ans, 0, sizeof(num));
	dp[0] = 0;

	for (int i = 0; i < N; i++) 
		for (int j = v[i]; j <= V; j++) 
			if (dp[j - v[i]] != -1 && dp[j - v[i]] + 1 > dp[j]) 
			{
				dp[j] = dp[j - v[i]] + 1;
				for (int k = 0; k < N; k++) 
				{
					if (k == i) 
						ans[j][k] = ans[j - v[i]][k] + 1;
					else
						ans[j][k] = ans[j - v[i]][k];
				}
			}
	system("pause");
	return 0;
}