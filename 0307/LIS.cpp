//============================================================================
// Name        : LCS.cpp
// Author      : Chunyang Guo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int LIS(int *list, int n);
int max(int a, int b);

int main()
{

	int a[100] =
	{ 0, 300, 207, 155, 300, 299, 170, 158, 65 };
	std::cout << LIS(a, 8) << std::endl;

	return 0;
}

int LIS(int *list, int n)
{
	int dp[100];
	for (int i = 1; i <= n; ++i)
	{
		int tmax = 1;
		for (int j = 1; j < i; j++)
		{
			if (list[j] >= list[i])
			{
				tmax = max(tmax, dp[j] + 1);
			}
		}
		dp[i] = tmax;

	}

	int ans = 1;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, dp[i]);
	}
	return ans;

}

int max(int a, int b)
{
	return a > b ? a : b;
}
