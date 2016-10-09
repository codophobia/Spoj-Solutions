#include <bits/stdc++.h>
using namespace std;
int l;
int k;
int dp[1000001][2];
int main()
{
    int n;
    int m;
    int i;
    int j;
    int a;
    int b;
    int c;
    dp[0][0] = 1;
    dp[0][1] = 0;

    cin>>k>>l>>m;
    for(i = 1; i <= 1000002; i++) {
            for(j = 0; j < 2; j++) {
                a = (i-1 >= 0)?dp[i-1][!j]:2;
                b = (i-k >= 0)?dp[i-k][!j]:2;
                c = (i-l >= 0)?dp[i-l][!j]:2;
                if(j == 0) {
                    if(a == 0 || b == 0 || c == 0) {
                        dp[i][j] = 0;
                    }
                    else {
                        dp[i][j] = 1;
                    }
                }
                if(j == 1) {
                    if(a == 1 || b == 1 || c == 1) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
    while(m--) {
        scanf("%d",&n);
        if(dp[n][0] == 0) {
            printf("A");
        }
        else {
            printf("B");
        }


    }

}
