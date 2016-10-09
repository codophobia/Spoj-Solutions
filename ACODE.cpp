#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a[50005];
    string s;
    long long int i;
    long long  int first;
    long long int second;
    long long int sum;

    while(1) {
        cin>>s;
        if(s[0]-'0' == 0) {
            break;
        }
        memset(a,0,sizeof(a));
        a[0] = 1;


        for(i = 1; i < s.size(); i++) {
            first = s[i]-'0';
            second = s[i-1]-'0';
            sum = (10 * second) + first;
           // cout<<first<<' '<<second<<' '<<sum<<endl;
            if(first > 0) {
                a[i] = a[i-1];
            }
            if(sum <= 26 && sum >= 10) {
                if(i - 2 < 0) {
                    a[i] = a[i] + 1;
                }
                else {
                    a[i] = a[i] + a[i-2];
                }
            }
        }

        cout<<a[s.size()-1]<<endl;
    }


}
