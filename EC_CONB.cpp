#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a;
    int r;
    int i;
    int sum;
    int j;
    stack<int> s;

    scanf("%d",&n);

    for(i = 0; i < n ;i++) {
        scanf("%d",&a);
        sum = 0;
        j = 0;
        if(a % 2 == 1) {
            printf("%d\n",a);
            continue;
        }

        else  {
            while(a != 0) {
                r = a % 2;
                s.push(r);
                a = a / 2;
            }


            while(!s.empty()) {
                a = s.top();

                sum = sum + (a * pow(2,j));
                s.pop();
                j++;

            }



            printf("%d\n",sum);
        }


    }
}
