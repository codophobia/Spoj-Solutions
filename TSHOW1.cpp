#include <bits/stdc++.h>
using namespace std;
long long int strnglen(long long int n)
{

    long long int c;
    long long int len;


    c = 0;

    len = 0;

    while(n > c) {
        c = c + pow(2,++len);

    }

    return len;



}
int main()
{
    long long int n;
    char a[10000];
    int b[] = {5,6};
    int t;
    long long int i;
    int j;
    long long len;
    vector<int> v;

    scanf("%d",&t);
    int k;


    while(t--) {
        scanf("%lld",&n);
        len = strnglen(n);
        //printf("%d\n",len);

        k = 1;


        for(i = 0; i < len; i++) {

            j = n % 2;

            if(j == 0) {
                j = 2;
            }
            //printf("%d %c\n",j,a[j-1]);


            v.push_back(b[j-1]);


            if(n % 2 == 0) {
                n = n/2 - 1;
            }
            else {
                n = n / 2;
            }
        }

        for(i = v.size()-1;i >= 0; i--) {
            cout<<v[i];
        }

        cout<<endl;
        v.clear();








    }

}
