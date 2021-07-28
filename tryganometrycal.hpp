#pragma once

#include "functional.hpp"
#include "constants.hpp"
 
namespace math {
	double sin(double ug) {
		ug *= 2;
		double l, r;
		double lx, ly, rx, ry;
		while (ug >= math::pi) {
			ug -= math::pi;
		}

		if (ug < math::pi / 4) {
			r = math::pi / 4;
			l = 0;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = 1;
		}

		else if (ug < math::pi / 2) {
			r = math::pi / 2;
			l = math::pi / 4;
			lx = 0;
			ly = 1;
			rx = -1;
			ry = 0;
		}

		else if (ug < math::pi * 3 / 4) {
			r = math::pi * 3 / 4;
			l = math::pi / 2;
			lx = -1;
			ly = 0;
			rx = 0;
			ry = -1;
		}

		else {
			r = math::pi;
			l = math::pi * 3 / 4;
			lx = 0;
			ly = -1;
			rx = 1;
			ry = 0;
		}
		double f;
		for (int i = 0; i < 25; i++) {
			double m = (l + r) / 2;
			double X = (lx + rx) / 2, Y = (ly + ry) / 2;
			double LN = 1 / sqrt(X * X + Y * Y, 1);
			//std::cout << m << " " << X << " " << Y << " " << LN << " " << l << " " << r << " " << lx << ly << endl;
			//std::cout << m << " " << X << " " << Y << " " << LN << " " << l << " " << r << " " << lx << ly << endl;

			if (m < ug) {
				l = m;
				lx = X * LN;
				ly = Y * LN;
			}
			else {
				r = m;
				rx = X * LN;
				ry = Y * LN;
			}
		}
		return ly;
	}

	double cos(double ug) {
		ug *= 2;
		double l, r;
		double lx, ly, rx, ry;
		while (ug >= math::pi) {
			ug -= math::pi;
		}

		if (ug < math::pi / 4) {
			r = math::pi / 4;
			l = 0;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = 1;
		}

		else if (ug < math::pi / 2) {
			r = math::pi / 2;
			l = math::pi / 4;
			lx = 0;
			ly = 1;
			rx = -1;
			ry = 0;
		}

		else if (ug < math::pi * 3 / 4) {
			r = math::pi * 3 / 4;
			l = math::pi / 2;
			lx = -1;
			ly = 0;
			rx = 0;
			ry = -1;
		}

		else {
			r = math::pi;
			l = math::pi * 3 / 4;
			lx = 0;
			ly = -1;
			rx = 1;
			ry = 0;
		}

		for (int i = 0; i < 25; i++) {
			double m = (l + r) / 2;
			double X = (lx + rx) / 2, Y = (ly + ry) / 2;
			double LN = 1 / sqrt(X * X + Y * Y, 1);
			if (m > ug) {
				l = m;
				lx = X * LN;
				ly = Y * LN;
			}
			else {
				r = m;
				rx = X * LN;
				ry = Y * LN;
			}
		}
		return lx;
	}

	double arcsin(double st) {
		double l, r;
		double lx, ly, rx, ry;

		if (st > 0) {
			r = math::pi / 4;
			l = 0;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = 1;
		}

		else {
			r = math::pi / 2;
			l = math::pi / 4;
			lx = 0;
			ly = 1;
			rx = -1;
			ry = 0;
		}

		for (int i = 0; i < 25; i++) {
			double m = (l + r) / 2;
			double X = (lx + rx) / 2, Y = (ly + ry) / 2;
			double LN = 1 / sqrt(X * X + Y * Y, 1);
			if (Y > st) {
				l = m;
				lx = X * LN;
				ly = Y * LN;
			}
			else {
				r = m;
				rx = X * LN;
				ry = Y * LN;
			}
		}
		return l * 2;
	}

	double arccos(double st) {
		double l, r;
		double lx, ly, rx, ry;

		if (st > 0) {
			r = math::pi / 4;
			l = 0;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = 1;
		}

		else {
			r = math::pi;
			l = math::pi * 3 / 4;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = -1;
		}

		for (int i = 0; i < 25; i++) {
			double m = (l + r) / 2;
			double X = (lx + rx) / 2, Y = (ly + ry) / 2;
			double LN = 1 / sqrt(X * X + Y * Y, 1);
			if (X > st) {
				l = m;
				lx = X * LN;
				ly = Y * LN;
			}
			else {
				r = m;
				rx = X * LN;
				ry = Y * LN;
			}
		}
		return 2 * l;
	}

	double tg(double ug) {
		return sin(ug) / cos(ug);
	}

	double ctg(double ug) {
		return cos(ug) / sin(ug);
	}

	double arctg(double st) {
		double l, r;
		double lx, ly, rx, ry;

		if (st > 0) {
			r = math::pi / 4;
			l = 0;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = 1;
		}

		else {
			r = math::pi / 2;
			l = math::pi / 4;
			lx = 0;
			ly = 1;
			rx = -1;
			ry = 0;
		}

		for (int i = 0; i < 25; i++) {
			double m = (l + r) / 2;
			double X = (lx + rx) / 2, Y = (ly + ry) / 2;
			double LN = 1 / sqrt(X * X + Y * Y, 1);
			if (Y / X > st) {
				l = m;
				lx = X * LN;
				ly = Y * LN;
			}
			else {
				r = m;
				rx = X * LN;
				ry = Y * LN;
			}
		}
		return l * 2;
	}

	double arcctg(double st) {
		double l, r;
		double lx, ly, rx, ry;

		if (st > 0) {
			r = math::pi / 4;
			l = 0;
			lx = 1;
			ly = 0;
			rx = 0;
			ry = 1;
		}

		else {
			r = math::pi / 2;
			l = math::pi / 4;
			lx = 0;
			ly = 1;
			rx = -1;
			ry = 0;
		}

		for (int i = 0; i < 25; i++) {
			double m = (l + r) / 2;
			double X = (lx + rx) / 2, Y = (ly + ry) / 2;
			double LN = 1 / sqrt(X * X + Y * Y, 1);
			if (X / Y > st) {
				l = m;
				lx = X * LN;
				ly = Y * LN;
			}
			else {
				r = m;
				rx = X * LN;
				ry = Y * LN;
			}
		}
		return 2 * l;
	}
}