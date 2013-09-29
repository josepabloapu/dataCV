#include "../../src/mysqplot.hh"

using namespace std;

int main(){
	Mysqplot A ("table1");
	A.conn("test", "localhost", "root", "root");
	A.gaussian_distribution("datos");
	return 0;
}
