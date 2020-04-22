using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))

const int N = 3e5 + 100; // careful
const int MOD = 1e9 + 7;
const int BASE = 31;

int add (int a, int b){
    return (a += b) >= MOD ? a - MOD : a;
}

int sub (int a, int b){
    return (a -= b) < 0 ? a + MOD : a;
}

int mul (int a, int b){
    return (long long) a * b % MOD;
}

int power(int a, long long n){
    int res = 1;
    while(n){
        if (n & 1LL) res = mul(res, a);
        a = mul(a, a);
        n >>= 1LL;
    }
    return res;
}
int inv(int a){
    return power(a, MOD - 2);
}

long long hastable[N], pw[N];
unordered_map <long long, bool> f;
unordered_map <long long, string> enf;

long long get(int i, int j) {
	return hastable[j] - hastable[i - 1] * pw[j - i + 1];
}

std::vector<std::string> antivirus(std::string header, std::vector<std::string> keywords, std::string code)
{
    int lencode = code.size();
    code = " " + code;
    vector <int> len;
    for (int i = 0; i < keywords.size(); i++)
        len.push_back(keywords[i].size());
    sort(len.begin(), len.end());
    len.resize(distance(len.begin(), unique(len.begin(), len.end())));

    for (int i = pw[0] = 1; i <= lencode; i++)
        pw[i] = pw[i - 1] * BASE;
    for (int i = 1; i <= lencode; i++)
        hastable[i] = hastable[i - 1] * BASE + code[i] - 'a' + 1;

	vector <string> ans;

	for (int i = 0; i < keywords.size(); i++) {
		string tmp = keywords[i];
		long long elencode = 0;
		for (int j = 0; j < tmp.size(); j++) elencode = elencode * BASE + tmp[j] - 'a' + 1;
		enf[elencode] = keywords[i];
	}

	for (int i = 0; i < header.size(); i++) {
		for (char c = 'a'; c <= 'z'; c++) {

			string pattern = header; pattern[i] = c;
			long long elencode = 0;
			for (int j = 0; j < pattern.size(); j++) elencode = elencode * BASE + pattern[j] - 'a' + 1;
			f[elencode] = true;

		}
		string pattern = header;
		pattern.erase(i, 1);
		long long elencode = 0;
		for (int j = 0; j < pattern.size(); j++) elencode = elencode * BASE + pattern[j] - 'a' + 1;
		f[elencode] = true;
	}

	for (int i = 0; i < header.size(); i++)
		for (int j = i + 1; j < header.size(); j++) {

			char ch1 = header[i], ch2 = header[j];
			if (abs(ch1 - ch2) == 1) {
				string pattern = header;
				char tmp;
				tmp = pattern[i]; pattern[i] = pattern[j]; pattern[j] = tmp;
				long long elencode = 0;
				for (int j = 0; j < pattern.size(); j++) elencode = elencode * BASE + pattern[j] - 'a' + 1;
				f[elencode] = true;
			}
		}


	for (int i = 1; i <= lencode; i++) {
		for (int j = 0; j < len.size(); j++) {

			int mid = i - len[j] + 1;
			int x = (mid - 1) - (header.size()) + 1;
			int y = (mid - 1) - (header.size() - 1) + 1;

			if (enf[get(mid, i)] != "") {
				if (x >= 1 && f[get(x, mid - 1)] == true) {
					ans.push_back(enf[get(mid, i)]);
					break;
				}
				if (y >= 1 && f[get(y, mid - 1)] == true) {
					ans.push_back(enf[get(mid, i)]);
					break;
				}
			}
		}
	}

	sort(ans.begin(), ans.end());
	ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));


	return ans;
}