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
    //seed
    srand(time(0));
    
    //number of testcases you want to generate (supports at max 20 files upto input19.txt)
    int testcases=10;
    char input[]="input00.txt";

    int b[] = {10,50,100,500,5000,200000,200000,200000,200000};
    int arr[200010];

    for(int t=0;t<testcases;t++)
    {
        freopen(input,"w",stdout);

        if(input[6]<'9')
            input[6]++;
        else 
        {
            input[5]++;
            input[6]='0';
        }

        if(t == 0)
        {
            cout << 2 << endl;
            cout << 3 << endl;
            cout << 101 << endl;
            cout << 5 << endl;
            cout << 11010 << endl;
        }
        else
        {
            int T = 50;
            cout << T << endl;

            while(T--) 
            {
                int n = rand()%b[t-1] + 1;
                cout << n << endl;

                for(int i = 0; i < n ; i++) 
                {
                    int bit = rand()%2;
                    arr[i] = bit;
                }

                for(int i = 0 ; i< n ; i++) 
                    cout << arr[i];
                cout<<"\n";   
            } 
        }
    }
    return 0;
}