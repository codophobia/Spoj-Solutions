#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string s;
    string sub;
    int i;
    int j;
    int k;
    int flag;

    scanf("%d",&t);

    while(t--) {
        cin>>s;
        sub = s;
        reverse(s.begin(),s.end());

        if(sub == s) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }


    }
}
