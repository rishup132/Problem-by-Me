#include<bits/stdc++.h>
 
const double PI = 3.141592653589793238460;
 
using namespace std;
 
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
bool a[200010],b[200010];
long long cnt1[200010],cnt2[200010];
 
void fft(CArray& x)
{
    const size_t N = x.size();
 
    if (N <= 1) 
        return;
 
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];
 
    fft(even);
    fft(odd);
 
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
 
void ifft(CArray& x)
{
    x = x.apply(std::conj);
    fft( x );
    x = x.apply(std::conj);
    x /= x.size();
}
 
long long solve(string s, string s1)
{
    int N = s.size() + 1;
    int padded_size = 2 * (1 << int(ceil(log2(N))));
    vector<Complex> num1_vec(padded_size - N, 0.0), num2_vec(padded_size - N, 0.0);
 
    num1_vec.push_back(0.0);
    num2_vec.push_back(0.0);
 
    for(int i = 1; i < N; i++) 
    {
        if(s[i-1] == '1')
            num1_vec.push_back(1.0);
        else
            num1_vec.push_back(0.0);
    }
 
    //reverse(s.begin(),s.end());
 
    for(int i = 1; i < N; i++) 
    {
        if(s1[i-1] == '1')
            num2_vec.push_back(1.0);
        else
            num2_vec.push_back(0.0);
    }
 
    CArray data1(padded_size);
    for(int i = 0; i < padded_size; i++) data1[i] = num1_vec[i];
    CArray data2(padded_size);
    for(int i = 0; i < padded_size; i++) data2[i] = num2_vec[i];
 
    fft(data1);
    fft(data2);
 
    CArray data3(padded_size);
    data3 = data1 * data2;
 
    ifft(data3);
 
    long long ans = 0;
 
    for (int i = 0; i < padded_size - 1; i++)
    {
        long long temp = (long long)(round(data3[i].real()));
        ans += temp*(temp-1)/2;
    }
 
    return ans;
}
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
    int t;
    cin >> t;
    assert(t >= 1 && t <= 5);
 
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        assert(n >= 1 && n <= 1e5);
        assert(m >= 1 && m <= 1e5);
 
        for(int i=0;i<200010;i++)
            a[i] = b[i] = false, cnt1[i] = cnt2[i] = 0;
 
        string s,s1;
        int cnt = 0;
 
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            assert(cnt < x);
            assert(x <= 2e5);
 
            a[x--] = true;
            
            while(s.size() < x)
                s += "0";
 
            s += "1";
        }
 
        cnt = 0;
        
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            assert(cnt < x);
            assert(x <= 2e5);
 
            b[x--] = true;
            
            while(s1.size() < x)
                s1 += "0";
 
            s1 += "1";
        }
 
        while(s.size() != s1.size())
        {
            if(s.size() < s1.size())
                s += "0";
            else
                s1 += "0";
        }
 
        reverse(s1.begin(),s1.end());
 
        long long ans = solve(s,s1);
 
        for(int i=1;i<=200000;i++)
        {
            if(a[i])
            {
                for(int j=2*i;j<=200000;j+=i)
                {
                    if(b[j])
                        cnt1[j-i]++;
                }
            }
 
            if(b[i])
            {
                for(int j=2*i;j<=200000;j+=i)
                {
                    if(a[j])
                        cnt2[j-i]++;
                }
 
                if(a[i] == b[i])
                    cnt1[0]++;
            }
        }
 
        for(int i=0;i<=200000;i++)
            ans -= (cnt1[i]*(cnt1[i]-1))/2, ans -= (cnt2[i]*(cnt2[i]-1))/2;
 
        cout << ans << endl;
    }
}  