#include "../../include/mysqplot.hh"

using namespace std;

int main(){
	Mysqplot A ("jitter");
	A.conn("data", "test", "localhost", "root", "root");
	A.histogram("data", 3);
	return 0;
}
