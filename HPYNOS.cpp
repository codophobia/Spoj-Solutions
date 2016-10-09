#include <bits/stdc++.h>
using namespace std;
int sum(long long int n)
{
    int sum;
    sum = 0;
    int r;

    while(n > 0) {
        r = n % 10;
        sum = sum + (r * r);
        n = n / 10;
    }

    return sum;
}
int main()
{
    long long int n;
    int count;
    map<int,int> s;
    int a;
    count = 1;
    int flag;
    flag = 0;

    scanf("%lld",&n);

    a = sum(n);
    s[a]++;
    while(1) {


        if(s[1] == 1) {
            flag = 1;
            break;
        }

        a = sum(a);
        s[a]++;
        count++;

        if(s[a] == 2) {
            break;
        }
    }

    if(flag == 1) {
        printf("%d\n",count);
    }
    else {
        printf("-1\n");
    }







}
