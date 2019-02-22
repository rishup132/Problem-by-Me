//-----Author: Saptarshi Dey 
//-----Handle: rishi_07

#include<bits/stdc++.h>
#define int long long
using namespace std;
 

int32_t main()
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
        //cout << tt << endl;

        while(tt--)
        {
            int n,x,y;
            cin >> n >> x >> y;

            string s;
            cin >> s;

            int c1,c2;
            c1 = c2 = 0;

            for(auto i:s)
                i == 'a' ? c1++ : c2++;

            if(c1*c2 != x+y)
                cout << "Impossible\n";
            else if(c1 == 0 || c2 == 0)
                cout << "Possible\n" << s << endl;
            else
            {
                cout << "Possible" << endl;
                int t1,t2;
                t1 = y/c2;
                t2 = y%c2;
                c2 -= t2;
                c1 -= t1;
                x = t2;

                //cout << t1 << " " << t2 << " " << x << " " << y << " " << c2 << endl;

                if(t2 != 0)
                    c1--;

                while(c1--)
                    cout << "a";
                
                while(t2--)
                    cout << "b";

                if(x != 0)
                    cout << "a";

                while(c2--)
                    cout << "b";

                while(t1--)
                    cout << "a";

                cout << endl;
            }
        }

    }
    return 0;
}