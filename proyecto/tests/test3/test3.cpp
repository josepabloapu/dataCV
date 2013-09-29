#include "../../src/mysqplot.hh"

using namespace std;

int main(){
	Mysqplot A ("table3");
	A.conn("data", "localhost", "root", "root");
	A.pdf("datos");
	A.cdf("datos");
	return 0;
}
