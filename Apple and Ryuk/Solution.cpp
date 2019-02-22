#include <bits/stdc++.h>

const double PI = 3.141592653589793238460;

using namespace std;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

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

int32_t main()
{
    int N;
    cin >> N;
    N++;

    assert(N >= 2 && N <=100001);

    string s;
    cin >> s;

    for(int i=0;i<N-1;i++)
        assert(s[i] == '1' || s[i] == '0');

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

    reverse(s.begin(),s.end());

    for(int i = 1; i < N; i++) 
    {
        if(s[i-1] == '1')
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

    vector<long long> ans;

    for (int i = 0; i < padded_size - 1; i++)
        ans.push_back((long long)(round(data3[i].real())));

    for(int i = padded_size - N; i < padded_size - 1; i++)
        cout << ans[i] << " ";
    cout << endl;
}