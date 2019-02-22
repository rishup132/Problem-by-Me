#include<bits/stdc++.h>

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

int main() {

	srand(time(0));

	int T = 40;
	char input[] = "input/input00.txt";
	char output[] = "output/output00.txt";

	bool flag = true;
	for(int t = 0; t < T; ++t) {
		flag = true;
		if(t == 10) {
			output[13] = input[11] = '1';
			output[14] = input[12] = '0';
			flag = false;
		}
		if(t == 20) {
			output[13] = input[11] = '2';
			output[14] = input[12] = '0';
			flag = false;
		}
		if(t == 30) {
			output[13] = input[11] = '3';
			output[14] = input[12] = '0';
			flag = false;
		}
		if(t > 0 && flag) {
			input[12]++;
			output[14]++;
		}

		freopen(input, "w", stdout);

		int n = rand() % 100000 + 1;

		string s = "";
	
		if(t <= 17) 
		{
			cout << n << endl;
			for (int i = 0; i < n; ++i) 
			{
				int x = rand() % 2;
				s += x == 0 ? "0" : "1";
			}
		}
		else if(t <= 34)
		{
			cout << 100000 << endl;
			for (int i = 0; i < 100000; ++i) 
			{
				int x = rand() % 2;
				s += x == 0 ? "0" : "1";
			}
		}
		if (t == 35) {
			cout << 1 << endl;
			s = "0";
		}
		if (t == 36) {
			cout << 1 << endl;
			s = "1";
		}
		if(t == 37) {
			cout << 100000 << endl;
			for (int i = 1; i <= 100000; ++i) {
				s += "0";
			}
		}
		if (t == 38) {
			cout << 100000 << endl;
			for (int i = 1; i <= 100000; ++i) {
				s += "1";
			}
		}
		if (t == 39) {
			cout << 100000 << endl;
			for (int i = 1; i <= 100000; i++) {
				if(i%2)
					cout << 1;
				else
					cout << 0;
			}
		}

		cout << s << endl;

		freopen(input, "r", stdin);

		int N;
		cin >> N;
		N++;

		assert(N >= 2 && N <=100001);

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

		for(auto i:num1_vec)
			cout << i << " ";
		cout << endl;

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

		freopen(output, "w", stdout);

		for(int i = padded_size - N; i < padded_size - 1; i++)
        	cout << ans[i] << " ";
    	cout << endl;
	}
	return 0;
}