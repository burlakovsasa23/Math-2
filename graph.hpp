#pragma once
#include <vector>

#define vector std::vector

namespace math {
	struct Graph {
		vector<vector<int>> self;
		Graph() {}
		Graph(vector<vector<int>> v, char construct = 'N', bool ucn=true) {
			if (construct == 'N') {
				if (ucn) {
					for (auto& i : v) {
						for (auto& j : i) {
							j--;
						}
					}
				}
				self = v;
			}
			else {
				for (auto i : v) {
					self.push_back({});
					for (int j = 0; j < v.size(); j++) {
						self[self.size() - 1].push_back(j);
					}
				}
			}
		}
		Graph(vector<std::pair<int, int>>) {}
	};
}