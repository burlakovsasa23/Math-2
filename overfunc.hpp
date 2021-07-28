namespace math {
	long double derivative(double func(double), double x, double cor=1000) {
		return (func(x + 1 / cor) - func(x)) * cor;
	}
	long double integral(double func(double), double x, double cor = 1000) {
		return (func(x + 1 / cor) - func(x)) * cor;
	}
}