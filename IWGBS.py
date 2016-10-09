import sys
def f(prev,n):
	if(n == 1):
		dp[prev][n] = 1;
		return dp[prev][n]
	if(dp[prev][n] != -1):
		return dp[prev][n]
	if(prev == 1):
		dp[prev][n] = f(0,n-1) + f(1,n-1)
		return dp[prev][n]
	else:
		dp[prev][n] =  f(1,n-1)
		return dp[prev][n]

n = input()
n = int(n)
dp = [[-1 for x in range(n+1)]for x in range(10)]
sys.setrecursionlimit(100000)
ans = f(1,n) + f(0,n)
print ans