#include "../../src/mysqplot.hh"

using namespace std;

int main(){
	/*Mysqplot A ("table3");
	A.conn("data", "localhost", "root", "root");
	A.pdf("datos");
	A.cdf("datos");*/
	
	Mysqplot B ("scatter");
	B.conn("data", "localhost", "root", "root");
	B.scatterplot("x","y");
	return 0;
}
