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
	srand(time(0));

	int testcases=14;

	char input[]="input00.txt";

	int a[3][3];
	int c[10];
	int b[] = {10,25,50,100,200,300,400,500,600,700,800,900,1000};

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
			cout << "abs" << endl;
		}
		else
		{
			int tt = 20;
			cout << tt << endl;

			while(tt--)
			{
				if(tt%4 != 0)
				{
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
							a[i][j] = rand()%b[t-1]+1;
					}

					c[0] = a[0][0]+a[0][1]+a[0][2];
					c[1] = a[1][0]+a[1][1]+a[1][2];
					c[2] = a[2][0]+a[2][1]+a[2][2];
					c[3] = a[0][0]+a[1][0]+a[2][0];
					c[4] = a[0][1]+a[1][1]+a[2][1];
					c[5] = a[0][2]+a[1][2]+a[2][2];
					c[6] = a[0][0]+a[1][1]+a[2][2];
					c[7] = a[0][2]+a[1][1]+a[2][0];
					
					for(int i=0;i<8;i++)
						cout << c[i] << " ";
					cout << endl;
				}
				else
				{
					for(int i=0;i<8;i++)
						cout << rand()%(3*b[t-1])+1 << " ";
					cout << endl;
				}
			}
		}
	}
	return 0;
}