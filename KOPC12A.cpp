#include <bits/stdc++.h>

using namespace std;

long long int h[10005];
long long int c[10005];

long long int f_cost (long long int h[], long long int c[], long long int ht, long long int n)
{
    long long int i, j, cost;

    cost = 0;
    for (j = 0; j < n; j++) {
        cost = cost + abs(ht - h[j]) * c[j];
    }

    return cost;
}
int main()
{
    long long int t, n, i, j, low, mid, high, cost, ans, maxh, a, b, cc, f1, c_a, c_b;

    //cin >> t;
    scanf("%lld", &t);

    while (t--) {
        //cin >> n;
        scanf("%lld", &n);

        maxh = 0;
        for (i = 0; i < n; i++) {
            //cin >> h[i];
            scanf("%lld", &h[i]);
            if (h[i] > maxh)
                maxh = h[i];
        }

        for (i = 0; i < n; i++) {
            //cin >> c[i];
            scanf("%lld", &c[i]);
        }

        if(n <= 1) {
            cout<<0<<endl;
            continue;
        }


        low = 0;
        high = maxh;
        c_a = 0;
        //cout << f1 << " FF " << mid << endl;

        while (low < high) {
            mid = (low + high + 1) / 2;

            //cout << c_a << " !! " << mid << endl;

            if (mid - 1 >= 0) {

            a = f_cost(h, c, mid - 1, n);
            b = f_cost(h, c, mid, n);
            cc = f_cost(h, c, mid + 1, n);

            if (b < a && b < cc) {
                c_a = b;
                break;
            }
            else if(a < b && a < cc) { /// b < a & b < c
                high = mid - 1;
                c_a = a;
            }
            else { /// b < a & b >c
                low = mid + 1;
                c_a = cc;
            }

            }
            else {

            b = f_cost(h, c, mid, n);
            cc = f_cost(h, c, mid + 1, n);

            if (b < cc) {
                c_a = b;
                break;
            }
            else { /// b < a & b >c
                low = mid + 1;
                c_a = cc;
            }

            }
        }

        //printf("%lld\n", ans);
        //cout << endl

        printf("%lld\n", c_a);
    }

    return 0;
}
