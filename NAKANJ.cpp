#include <bits/stdc++.h>
#define initial 1;
#define waiting 2;
#define visited 3;

using namespace std;

int b_f_s(string a, string b)
{
    //string state[100005];

    //map <string, int> state;
    int state[10][10];
    //pair <string, int> state [100005];

    int xx[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    int yy[] = {-1, 1, 1, -1, -2, 2, 2, -2};

    int px, py, ph, i, j;
    char cx, cy;

    queue < pair <string, int> > q;
    pair <string, int> p;
    pair <string, int> top;

    string x;

    x = a;

     for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            state[i][j] = 1;
        }
    }

    ph = 0;
    p = make_pair(a, 0);
    q.push(p);
    px = p.first[0] - 97;
    py = p.first[1] - 48;

    state[px][py] = 2;

    while(!q.empty()) {
        top = q.front();
        q.pop();
        px = top.first[0] - 97;
        py = top.first[1] - 48;
        state[px][py] = 3;

        if (top.first == b) {
            return top.second;
        }

        ph = top.second;

        for (i = 0; i <= 7; i++) {
            cx = top.first[0];
            cy = top.first[1];

            px = cx;
            py = cy - '0';

           // cout << cx << " OkkkkO " << cy << endl;

            px = px + xx[i];
            py = py + yy[i];

            cx = px;
            cy = py + '0';

            //px = px;
            //py = py - 48;

            x[0] = cx;
            x[1] = cy;

            //cout << x[0] << " char " << x[1] << endl;
            //cout << px << " int " << py << endl;

            if (px >= 97 && px <= 104 && py >= 1 && py <= 8) {
                //cout << x[0] << " KK " << x[1] << endl;
                if (state[px - 97][py] == 1) {
                    //cout << px - 97 << " PP " << py << endl;
                    p = make_pair(x, ph + 1);
                    q.push(p);
                    state[px - 97][py] = 2;
                }
            }
        }
    }
}

int main()
{
    int i, j, t, x;

    string a, b;

    cin >> t;

    while (t--) {
        cin >> a;
        cin >> b;

        x = b_f_s(a, b);

        cout << x << endl;
    }

    return 0;
}
