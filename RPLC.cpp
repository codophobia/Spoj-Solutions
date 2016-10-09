#include <iostream>
#include <stdio.h>
#define INF 100000000000000009;
using namespace std;
long long int sum[1000008];
int main()
{
    long long int s,mini,n,tmp,t,i;
    cin >> t;

    for (s = 1; s <= t;s++){
        scanf("%lld", &n);
        mini = INF;
        sum[0] = 0;
        for (i = 1; i <= n; i++){
            cin >> tmp;
            sum[i] = sum[i-1]+tmp;
            if (sum[i] < mini){
                mini = sum[i];
            }
        }
        if (mini >= 0){
            printf("Scenario #%lld: ",s);
            printf("1\n");
        }
        else {
            printf("Scenario #%lld: ",s);
            printf("%lld\n", 1+(-mini));
        }
    }
    return 0;
}
