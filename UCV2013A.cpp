#include <bits/stdc++.h>
using namespace std;
long long int power(long long base,long long power,long long M)
{
        long long result=1;
        while (power>0)
        {
                if (power%2==1)
                        result = (result*base)%M;
                base = (base*base)%M;
                power/=2;
        }
        return result;
}

int main()
{
    int t;
    int l;
    int i;
    int n;
    long long int m;
    long long int s;
    m = 1000000007;

    while(1) {
        scanf("%d%d",&n,&l);
        if(n == 0 && l == 0) {
            break;
        }
        s = 0;
        for(i = 1; i <= l; i++) {
           s = (s + power(n,i,m)) % m;
        }
        cout<<s<<endl;
    }

}
