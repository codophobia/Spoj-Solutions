#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a % b == 0) {
        return b;
    }
    else {
        return gcd(b,a%b);
    }
}


int main()
{
    int t;
    int a;
    int b;
    int i;
    int count;
    int k;

    scanf("%d",&t);

    while(t--) {

        scanf("%d%d",&a,&b);


        count = 0;
        if(a > b) {
            k = gcd(a,b);
        }
        else {
            k = gcd(b,a);
        }
        int mi = min(a,b);
        int mx = max(a,b);




        for(i = 1; i <= sqrt(k); i++) {

                if(mi % i == 0) {
                    if(mx % i == 0) {
                        count++;
                    }

                    if(mx % k/i == 0 && i * i != k) {
                        count++;
                    }
                }


        }

        printf("%d\n",count);
    }

    return 0;

}

