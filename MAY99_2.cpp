#include <bits/stdc++.h>
using namespace std;
long long int strnglen(long long int n)
{

    long long int c;
    long long int len;


    c = 0;

    len = 0;

    while(n > c) {
        c = c + pow(5,++len);

    }

    return len;



}
int main()
{
    long long int n;
    char a[10000];
    char b[] = {'m','a','n','k','u'};
    int t;
    long long int i;
    int j;
    long long len;
    vector<char> v;

    scanf("%d",&t);
    int k;


    while(t--) {
        scanf("%lld",&n);
        len = strnglen(n);
        //printf("%d\n",len);

        k = 1;


        for(i = 0; i < len; i++) {

            j = n % 5;

            if(j == 0) {
                j = 5;
            }
            //printf("%d %c\n",j,a[j-1]);


            v.push_back(b[j-1]);


            if(n % 5 == 0) {
                n = n/5 - 1;
            }
            else {
                n = n / 5;
            }
        }

        for(i = v.size()-1;i >= 0; i--) {
            cout<<v[i];
        }

        cout<<endl;
        v.clear();








    }

}
