#include <bits/stdc++.h>

using namespace std;

int a[3][3];
int b[8];

bool solve1()
{
    int c[8];

    c[0] = a[0][0]+a[0][1]+a[0][2];
    c[1] = a[1][0]+a[1][1]+a[1][2];
    c[2] = a[2][0]+a[2][1]+a[2][2];
    c[3] = a[0][0]+a[1][0]+a[2][0];
    c[4] = a[0][1]+a[1][1]+a[2][1];
    c[5] = a[0][2]+a[1][2]+a[2][2];
    c[6] = a[0][0]+a[1][1]+a[2][2];
    c[7] = a[0][2]+a[1][1]+a[2][0];

    for(int i=0;i<8;i++)
    {
        if(b[i] != c[i])
            return false;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j] <= 0 || a[i][j] > 1000)
                return false;
        }
    }

    return true;
}

bool solve2()
{
    set <int> s;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            s.insert(a[i][j]);
    }

    return s.size() == 9;
}

int main()
{
    int testcases=14;
    char input[]="input00.txt";
    char output[]="output00.txt";

    for(int t=0;t<testcases;t++)
    {
        freopen(input,"r",stdin);
        freopen(output,"w",stdout);

        if(input[6]<'9')
        {
            input[6]++;
            output[7]++;
        }
        else 
        {
            input[5]++;
            input[6]='0';
            output[6]++;
            output[7]='0';
        }

        int tt;
        cin >> tt;

        while(tt--)
        {
            for(int i=0;i<8;i++)
                cin >> b[i];

            a[1][1] = (b[4]+b[6]+b[7]-b[2]-b[0]);

            if(a[1][1]%3 != 0 || a[1][1] < 3 || a[1][1] > 3000)
            {
                cout << "Impossible" << endl;
                continue;
            }

            a[1][1] /= 3;

            int count = 0;

            for(int i=1;i<=1000;i++)
            {
                for(int j=1;j<=1000;j++)
                {
                    a[0][0] = i;
                    a[0][1] = j;
                    a[0][2] = b[0]-i-j;
                    a[2][0] = b[7]-a[0][2]-a[1][1];
                    a[2][1] = b[4]-a[0][1]-a[1][1];
                    a[2][2] = b[6]-a[0][0]-a[1][1];
                    a[1][0] = b[3]-a[0][0]-a[2][0];
                    a[1][2] = b[5]-a[0][2]-a[2][2];

                    if(solve1() && solve2())
                        count++;
                }
            }

            if(count == 0)
                cout << "Impossible\n";
            else
                cout << "Possible\n" << count << endl;
        }
    }
    return 0;
}