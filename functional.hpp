#pragma once
#include <climits>
#include <iostream>
#include "constants.hpp"
namespace math {
	double abs(double n) {
		if (n > 0) {
			return n;
		}
		else {
			return -n;
		}
	}
	int pow(int a, int b) {
		if (b == 0) {
			return 1;
		}
		else {
			int ans = pow(a, b / 2);
			ans *= ans;
			if (b % 2) {
				ans *= a;
			}
			return ans;
		}
	}

	double pow(double a, int b) {
		if (b < 0) {
			return 1 / math::pow(a, -b);
		}
		if (b == 0) {
			return 1;
		}
		else {
			double ans = pow(a, b / 2);
			ans *= ans;
			if (b % 2) {
				ans *= a;
			}
			return ans;
		}
	}

	double root(double a, int b, int gates = 18) {
		double l = -pow(10.0, gates), r = pow(10.0, gates);
		if (b % 2 == 0) {
			l = 0;
		}
		for (int i = 0; i < 23 + gates / 3; i++) {
			double m = (l + r) / 2;
			if (math::pow(m, b) < a) {
				l = m;
			}
			else {
				r = m;
			}
		}
		return (r);
	}

	double pow(double a, double b) {
		if (b < 0) {
			return 1 / math::pow(a, -b);
		}
		double ans = 1;
		for (int i = 1; i < 10; i++) {
			ans *= math::pow(math::root(a, math::pow(10, i), 2), int(b * math::pow(10, i)) % 10);
			//std::cout << math::root(a, math::pow(10, i)) << int(b * math::pow(10, i));// << int(b * math::pow(10, i)) << " ";
		}
		ans *= math::pow(a, int(b));
		return ans;
	}

	double root(double a, double b) {
		return math::pow(a, 1 / b);
	}

	double sqrt(double a, int gates = 18) {
		return math::root(a, 2, gates);
	}

	double qbrt(double a, int gates = 18) {
		return math::root(a, 3, gates);
	}

	double log(double b, double a) {
		double l = -127, r = 127;
		for (int i = 0; i < 45; i++) {
			double m = (l + r) / 2;
			if (pow(b, m) < a) {
				l = m;
			}
			else {
				r = m;
			}
		}
		return r;
	}

	double log2(double n) {
		return log(2, n);
	}

	double log10(double n) {
		return log(10, n);
	}

	double ln(double n) {
		return log(math::e, n);
	}
}