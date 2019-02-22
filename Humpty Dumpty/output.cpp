//-----Author: Saptarshi Dey 
//-----Handle: rishi_07

#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define trace1(x) cerr<<#x<<": "<<x<<endl;
#define trace2(x,y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
using namespace std;
 

int main()
{
    int testcases=10;
    char input[]="input00.txt";
    char output[]="output00.txt";
    int arr[200010];

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
            int n;
            cin >> n;

            string s;
            cin >> s;

            int c1,c2;
            c1 = c2 = 0;

            for(auto i:s)
                i == '1' ? c1++ : c2++;

            if(min(c1,c2)%2)
                cout << "Humpty Dumpty\n";
            else
                cout << "King\n";
        }
    }
    return 0;
}
