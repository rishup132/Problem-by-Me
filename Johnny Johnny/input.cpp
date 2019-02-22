//-----Author: Saptarshi Dey 
//-----Handle: rishi_07

#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define trace1(x) cerr<<#x<<": "<<x<<endl;
#define trace2(x,y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
using namespace std;


int32_t main()
{
	//seed
	srand(time(0));
	
	//number of testcases you want to generate (supports at max 20 files upto input19.txt)
	int testcases=14;

	char input[]="input00.txt";

	int bb[] = {10,25,50,100,500,1000,5000,10000,200000,200000,200000,200000,200000};

	for(int t=0;t<testcases;t++)
	{
		freopen(input,"w",stdout);

		if(input[6]<'9')
		{
			input[6]++;
		}
		else 
		{
			input[5]++;
			input[6]='0';
		}

		if(t == 0)
		{
			cout << 2 << endl;
			cout << 1 << " " << 0 << " " << 0 << endl;
			cout << "a" << endl;
			cout << 5 << " " << 3 << " " << 3 << endl;
			cout << "baaab" << endl;
		}
		else
		{
			int tt = 30;
			cout << tt << endl;

			while(tt--)
			{
				int n,x,y;
				n = rand()%bb[t-1] + 1;
				//cout << bb[t-1] << endl;
				cout << n << " ";
				
				string s = "";

				for(int i=0;i<n;i++)
				{
					char z = rand()%2 + 97;
					s.push_back(z);
				}

				if(tt%5 == 0)
				{
					cout << 0 << " " << 0 << endl;
				}
				else
				{
					int a,b;
					a = b = 0;

					for(int i=0;i<n;i++)
					{
						if(s[i] == 'a')
							a++;
						else
							b++;
					}

					a *= b;

					if(a == 0)
						cout << a << " " << b << endl;
					else
					{
						b = rand()%a;
						a -= b;

						if(tt%4 == 0)
							cout << a+1 << " " << b << endl;
						else
							cout << a << " " << b << endl;
					}
				}

				cout << s << endl;
			}
		}
	}
	return 0;
}