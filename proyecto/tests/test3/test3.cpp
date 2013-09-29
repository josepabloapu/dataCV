#include "../../src/mysqplot.hh"
//#include "../../src/gnuplot_i.hpp"
//#include <conio.h>

using namespace std;

int main(){
	Mysqplot A ("table3");
	A.conn("data", "localhost", "root", "root");
	A.pdf("datos");
	return 0;
}
