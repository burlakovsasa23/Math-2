#define img *complex(0, 1)

namespace math {
	struct complex {
		double real = 0, imag = 0;

		complex(double r, double i) {
			real = r;
			imag = i;
		}

		complex operator+(complex oth) {
			return complex(real + oth.real, imag + oth.imag);
		}

		void operator+=(complex oth) {
			complex self(real, imag);
			self = self + oth;
			real = self.real;
			imag = self.imag;
		}

		complex operator* (complex oth) {
			return complex(real * oth.real - imag * oth.imag, imag * oth.real + real * oth.imag);
		}

		void operator*=(complex oth) {
			complex self(real, imag);
			self = self * oth;
			real = self.real;
			imag = self.imag;
		}
	};
}