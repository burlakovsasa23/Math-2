#pragma once
#include "functional.hpp"
#include <vector>


namespace math {
	double arythmetic(std::vector<double> args) {
		double sum = 0;
		for (auto i : args) {
			sum += i;
		}
		return sum / args.size();
	}
	
	double geometric(std::vector<double> args) {
		double sum = 1;
		for (auto i : args) {
			sum *= i;
		}
		return math::root(sum, (int)args.size());
	}

	double garmonic(std::vector<double> args) {
		double sum = 0;
		for (auto i : args) {
			sum += 1 / i;
		}
		return args.size() / sum;
	}
	double qudratic(std::vector<double> args) {
		double sum = 0;
		for (auto i : args) {
			sum += i * i;
		}
		return math::sqrt(sum / args.size());
	}
}