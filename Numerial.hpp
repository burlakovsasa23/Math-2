#pragma once
#include <vector>

#define ll long long

#pragma comment(linker, "/STACK:1000000000000")

using namespace std;
namespace math {
	int gcd(int a, int b) {
		if (a == b) {
			return a;
		}
		if (a * b == 0) {
			return a + b;
		}
		return gcd(a % b, b % a);
	}

	vector<int> gcdEX(int a, int b) {
		if (a == b) {
			return { a, 1, 0 };
		}
		if (a * b == 0) {
			return { a + b, 1, 1 };
		}
		auto ans = gcdEX(a % b, b % a);
		int a1 = ans[0], a2 = ans[1], a3 = ans[2];
		return { a1, a2 - b / a * a3, a3 - a / b * a2 };
	}

	bool is_prime(long long n) {
		for (long long i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

	vector<bool> all_primes(int END) {
		vector<bool> a(END, true);
		for (int i = 2; i * i <= END; i++) {
			if (a[i - 1] == false) {
				continue;
			}
			for (int j = 2 * i; j <= END; j += i) {
				a[j - 1] = false;
			}
			if (i % (int)1e3 == 0) {
				cout << i;
			}
		}
		return a;
	}

	vector<ll> all_divs(long long n) {
		vector<ll> ans = {};
		ll i = 0;
		for (i = 2; i * i < n; i++) {
			ans.push_back(i);
			ans.push_back(n / i);
		}
		if (i * i == n) {
			ans.push_back(i);
		}
		return ans;
	}

	ll sum_divs(long long n) {
		ll ans = 0;
		ll i = 0;
		for (i = 2; i * i < n; i++) {
			ans += (i);
			ans += (n / i);
		}
		if (i * i == n) {
			ans += (i);
		}
		return ans;
	}
}
