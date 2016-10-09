#include <bits/stdc++.h>
using namespace std;
long long int par;
char child(int n,long long int k)
{
    if(n == 1 && k == 1) {
        return 'm';
    }

    if(k % 2 == 0) {
         par = k / 2;
    }
    else {
        par = (k/2)+1;
    }

    char c = child(n-1,par);

    if(k % 2 == 0) {
        if(c == 'm') {
            c = 'f';
        }
        else {
            c = 'm';
        }
    }
    else {
        if(c == 'm') {
            c = 'm';
        }
        else {
            c = 'f';
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

    scanf("%d",&t);

    while(t--) {
        scanf("%d%lld",&n,&k);
        c = child(n,k);
        if(c == 'm') {
            printf("Male\n");
        }
        else if(c == 'f') {
            printf("Female\n");
        }
    }
}
