#include<bits/stdc++.h>

#define mod1 1000000007

using namespace std;

int segment[400010];
int ans[200010];

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	
	return a.first > b.first;
}

int query1(int node, int l, int r, int start, int end)
{
	if(start > r || end < l)
		return 0;

	else if (start <= l && r <= end)
		return segment[node];

	int mid=l+(r-l)/2;

	int p1 = query1(2*node,l,mid,start,end);
	int p2 = query1(2*node+1,mid+1,r,start,end);

	return (p1%mod1 + p2%mod1)%mod1;
}

void update(int node,int l,int r,int index,int val)
{
	if(l==r)
		segment[node] = val+1;
	else
	{
		int mid=l+(r-l)/2;

		if(index <= mid)
			update(2*node,l,mid,index,val);
		else
			update(2*node+1,mid+1,r,index,val);

		segment[node] = (segment[2*node]%mod1 + segment[2*node+1]%mod1)%mod1;
	}
}

int main() 
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
    cin >> t;
	assert(t >= 1 && t <= 20);

	while(t--)
	{
		int n,q;
		cin >> n >> q;
		assert(n >= 1 && n <= 100000);
		assert(q >= 1 && q <= 200000);

		for(int i=0;i<400010;i++)
			segment[i] = 0;

		for(int i=0;i<200010;i++)
			ans[i] = 0;

		int x;
		vector <pair<int,int> > query,v;

		for(int i=1;i<=n;i++)
		{
			cin >> x;
			assert(x >= 1 && x <= 1e9);
			v.push_back({x,i});
		}

		for(int i=0;i<q;i++)
		{
			cin >> x;
			assert(x >= 1 && x <= 1e9);
			query.push_back({x,i});
		}

		sort(v.begin(),v.end(),cmp);
		sort(query.begin(),query.end());

		for(auto i:query)
		{
			while(!v.empty() && v.back().first <= i.first)
			{
				int temp = query1(1,1,n,1,v.back().second);
				update(1,1,n,v.back().second,temp);

				v.pop_back();
			}

			ans[i.second] = segment[1];
		}

		for(int i=0;i<q;i++)
			cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}
