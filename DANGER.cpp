#include <bits/stdc++.h>
using namespace std;
int order(int n,int k)
{
    if(n == 1) {
        return 1;
    }

    if(n % 2 == 0) {
        if(k == 1) {
            return (2 * order(n/2,1));
        }
        else {
            return(2*order(n/2,2)-1);
        }
    }
    else {
        if(k == 1) {
            return (2 * order(n/2,2));
        }
        else {
            return (2 * order(n/2+1,1)-1);
        }
    }
}
int main()
{
    char s[5];
    int n;
    int x;
    int y;
    int z;
    int i;
    int j;

    while(1) {
        scanf("%s",s);
        x = s[0]-'0';
        y = s[1]-'0';
        z = s[3]-'0';
        if(x == 0 && y == 0 & z == 0) {
            break;
        }
        n = 10 * x + y;
        for(i = 0; i < z; i++) {
            n = n * 10;
        }

        printf("%d\n",order(n,2));
    }
}
