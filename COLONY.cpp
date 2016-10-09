#include <bits/stdc++.h>
using namespace std;
long long int par;
char child(int n,long long int k)
{
    if(n == 0 && k == 0) {
        return 'R';
    }

    par = k / 2;

    char c = child(n-1,par);

    if(k % 2 == 0) {
        if(c == 'R') {
            c = 'B';
        }
        else {
            c = 'R';
        }
    }
    else {
        if(c == 'R') {
            c = 'R';
        }
        else {
            c = 'B';
        }
    }

    return c;
}
int main()
{
    int t;
    int n;
    char c;
    long long int k;




        scanf("%d%lld",&n,&k);
        c = child(n,k);
        if(c == 'B') {
            printf("blue\n");
        }
        else if(c == 'R') {
            printf("red\n");
        }

}
