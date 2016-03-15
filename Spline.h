#include <cstdlib>
#include <cmath>
#include <limits>

class cubic_spline
{
private:
	
	struct spline_tuple
	{
		double a, b, c, d, x;
	};

	spline_tuple *splines;
	std::size_t n; 

	void free_mem(); 

public:
	cubic_spline(); 
	~cubic_spline(); 

	
	void build_spline(const double *x, const double *y, std::size_t n);


	double f(double x) const;
};

cubic_spline::cubic_spline() : splines(NULL)
{

}

cubic_spline::~cubic_spline()
{
	free_mem();
}

void cubic_spline::build_spline(const double *x, const double *y, std::size_t n)
{
	free_mem();

	this->n = n;

	splines = new spline_tuple[n];
	for (std::size_t i = 0; i < n; ++i)
	{
		splines[i].x = x[i];
		splines[i].a = y[i];
	}
	splines[0].c = 0.;


	double *alpha = new double[n - 1];
	double *beta = new double[n - 1];
	double A, B, C, F, h_i, h_i1, z;
	alpha[0] = beta[0] = 0.;
	for (std::size_t i = 1; i < n - 1; ++i)
	{
		h_i = x[i] - x[i - 1], h_i1 = x[i + 1] - x[i];
		A = h_i;
		C = 2. * (h_i + h_i1);
		B = h_i1;
		F = 6. * ((y[i + 1] - y[i]) / h_i1 - (y[i] - y[i - 1]) / h_i);
		z = (A * alpha[i - 1] + C);
		alpha[i] = -B / z;
		beta[i] = (F - A * beta[i - 1]) / z;
	}

	splines[n - 1].c = (F - A * beta[n - 2]) / (C + A * alpha[n - 2]);

	for (std::size_t i = n - 2; i > 0; --i)
		splines[i].c = alpha[i] * splines[i + 1].c + beta[i];

	delete[] beta;
	delete[] alpha;

	for (std::size_t i = n - 1; i > 0; --i)
	{
		double h_i = x[i] - x[i - 1];
		splines[i].d = (splines[i].c - splines[i - 1].c) / h_i;
		splines[i].b = h_i * (2. * splines[i].c + splines[i - 1].c) / 6. + (y[i] - y[i - 1]) / h_i;
	}
}

double cubic_spline::f(double x) const
{
	if (!splines)
		return std::numeric_limits<double>::quiet_NaN(); 

	spline_tuple *s;
	if (x <= splines[0].x) 
		s = splines + 1;
	else if (x >= splines[n - 1].x) 
		s = splines + n - 1;
	else 
	{
		std::size_t i = 0, j = n - 1;
		while (i + 1 < j)
		{
			std::size_t k = i + (j - i) / 2;
			if (x <= splines[k].x)
				j = k;
			else
				i = k;
		}
		s = splines + j;
	}

	double dx = (x - s->x);
	return s->a + (s->b + (s->c / 2. + s->d * dx / 6.) * dx) * dx;
}

void cubic_spline::free_mem()
{
	delete[] splines;
	splines = NULL;
}