#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int in[100];
#define max 100000008;
void sieve()
{
    long int i;
    long int n;
    int j;
    int s;

    memset(in,0,sizeof(in));
    in[0] = 1;
    in[1] = 1;

    for(i = 2; i <= 10; i++) {
        if(in[i] == 0) {
            for(j = i + i; j < 100; j = j+i) {
                in[j] = 1;
            }
        }
    }


    for(i = 0; i < 100000008; i++) {
        n = i;
        s = 0;


        while(n >  0) {
            s = s + (n % 10);
            n = n / 10;
        }

        if(in[s] == 0) {
            v.push_back(i);
        }


    }


    /*for(i = 0; i < 100; i++) {
        cout<<v[i]<<' ';
    }*/
}
int main()
{
    sieve();
    int t;
    int a;
    int b;
    vector<int>::iterator low,up;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&a,&b);
        low = lower_bound(v.begin(),v.end(),a);
        up = upper_bound(v.begin(),v.end(),b);

        printf("%d\n",(up-v.begin())-(low-v.begin()));

    }
    
    return 0;

}
