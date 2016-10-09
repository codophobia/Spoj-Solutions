#include <bits/stdc++.h>
using namespace std;
long long int power(long long base,long long power)
{
        long long result=1;
        while (power>0)
        {
                if (power%2==1)
                        result = (result*base);
                base = (base*base);
                power/=2;
        }
        return result;
}
int main()
{
    int t;
    int n;
    char prev;
    char current;
    int count;
    long long int p;
    char s[35];
    map<char,int>::iterator it;
    int i;

    scanf("%d",&t);

    while(t--) {
        scanf("%s",s);
        map<char,int> m;
        p = 1;
        count = 0;
        prev = s[0];
        for(i = 1; i <= strlen(s);i++) {
            current = s[i];
            if(prev == current) {
                count++;
                //cout<<111<<endl;
            }
            else {
                p = p * power(2,count);
                count = 0;
                prev = s[i];
            }
        }

        printf("%lld\n",p);

    }
}
