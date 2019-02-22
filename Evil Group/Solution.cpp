#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int a[100010];
int tree[400010];
int answers[100010];
int cnt1[100010];
int cnt2[100010];
int BLOCK_SIZE;
pair< pair<int, int>, int> queries[100500];
int ans;

void build(int node, int start, int end)
{
    if(start == end)
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;

        build(2*node, start, mid);
        build(2*node+1, mid+1, end);

        tree[node] = __gcd(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
        return 0;

    if(l <= start and end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return __gcd(p1,p2);
}

inline bool mo_cmp(const pair< pair<int, int>, int> &x, const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

int32_t main() {
    int n;
    cin >> n;

    assert(n >= 1 && n <= 100000);

    BLOCK_SIZE = static_cast<int>(sqrt(n));

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        assert(a[i] >= 1 && a[i] <= 1e6);
    }

    build(1,0,n-1);

    for(int i=0;i<n;i++)
    {
        int l = i;
        int h = n-1;
        int ans = n;

        while(l <= h)
        {
            int mid = (l+h)/2;

            if(query(1,0,n-1,i,mid) == 1)
            {
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }

        cnt1[i] = ans;
    }

    for(int i=n-1;i>=0;i--)
    {
        int l = 0;
        int h = i;
        int ans = -1;

        while(l <= h)
        {
            int mid = (l+h)/2;

            if(query(1,0,n-1,mid,i) == 1)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }

        cnt2[i] = ans;
    }

    int q;
    cin >> q;

    assert(q >= 1 && q <= 50000);

    for(int i=0;i<q;i++) 
    {
        cin >> queries[i].first.first >> queries[i].first.second;
        assert(queries[i].first.first >= 1 && queries[i].first.first <= n);
        assert(queries[i].first.second >= 1 && queries[i].first.second <= n);
        queries[i].second = i;
    }

    sort(queries, queries + q, mo_cmp);

    int mo_left = 0, mo_right = -1;
    ans =  0;

    for(int i=0;i<q;i++)
    {
        int left = queries[i].first.first-1;
        int right = queries[i].first.second-1;

        while(mo_right < right) 
        {
            mo_right++;
            
            if(cnt2[mo_right] >= mo_left)
                ans += (cnt2[mo_right]-mo_left+1);
        }

        while(mo_right > right) 
        {
            if(cnt2[mo_right] >= mo_left)
                ans -= (cnt2[mo_right]-mo_left+1);

            mo_right--;
        }

        while(mo_left < left) 
        {
            if(cnt1[mo_left] <= mo_right)
                ans -= (mo_right-cnt1[mo_left]+1);

            mo_left++;
        }

        while(mo_left > left) 
        {
            mo_left--;

            if(cnt1[mo_left] <= mo_right)
                ans += (mo_right-cnt1[mo_left]+1);
        }

        answers[queries[i].second] = ans;
    }

    for(int i=0;i<q;i++)
        cout << answers[i] << "\n";

    return 0;
}