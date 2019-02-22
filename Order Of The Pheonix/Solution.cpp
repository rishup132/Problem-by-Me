#include <bits/stdc++.h>
 
//#define int long long
#define mod 10007
 
using namespace std;
 
vector <vector<int> > ans;
vector <int> a(4e5,0);
 
void output1()
{
	int n = 1;
	int cnt = 1;
	a[0] = 1;
 
	while(true)
	{
		vector <int> tt;
 
		for(int i=0;i<cnt;i++)
			tt.push_back(a[i]);
 
		ans.push_back(tt);
 
		if(n == 500)
			break;
 
		n++;
		vector <int> b(n*(n-1)/2+2,0);
 
		for(int i=0;i<cnt;i++)
		{
			b[i] += a[i];
			b[i+n] -= a[i];
		}
 
		for(int i=1;i<b.size();i++)
			b[i] = b[i] + b[i-1];
 
		b.pop_back();
		cnt = b.size();
 
		for(int i=0;i<cnt;i++)
			a[i] = b[i]%mod;
	}
}
 
int32_t main()
{
	int t;
	scanf("%d",&t);
	assert(1 <= t && t <= 100);
 
	output1();
 
	for(int i=0;i<t;i++)
	{
		int x;
		scanf("%d",&x);
 
		assert(1 <= x && x <= 500);
 
		x--;
 
		for(int i:ans[x])
			printf("%d ",i);
		printf("\n");
	}
} 