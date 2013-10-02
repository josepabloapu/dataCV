#include "../../include/mysqplot.hh"

using namespace std;

int main(){
	Mysqplot D ("ks");
	D.conn("data","localhost","root","root");
	cout<<D.kolmogorov_test_uniform("datos",0,1)<<endl;
	D.cdf("datos");
	Mysqplot A ("ks2");
	A.conn("data","localhost","root","root");
	cout<<A.kolmogorov_test_uniform("datos",0,2)<<endl;
	A.cdf("datos");
	Mysqplot B ("ks3");
	B.conn("data","localhost","root","root");
	cout<<B.kolmogorov_test_uniform("datos",0,0.2)<<endl;
	B.cdf("datos");
	return 0;
}
