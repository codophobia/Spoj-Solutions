#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;

    int flag;
    flag = 0;

    scanf("%lld",&n);

    while((n % 2 == 0) && n > 1) {
        n = n / 2;
        if(n == 1){
            flag = 1;
        }
    }


    if(flag == 1) {
        printf("TAK\n");
    }
    else {
        printf("NIE\n");
    }
    return 0;
}
