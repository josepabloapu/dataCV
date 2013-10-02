#include "../../include/mysqplot.hh"

using namespace std;

int main(){
	/*Mysqplot A ("table3");
	A.conn("data", "localhost", "root", "root");
	A.pdf("datos");
	A.cdf("datos");*/
	
	/*Mysqplot B ("scatter");
	B.conn("data", "localhost", "root", "root");
	B.scatterplot("x","y");
	*/
	/*Mysqplot C ("gauss");
	C.conn("data", "localhost", "root", "root");
	//C.mean("datos");
	C.pdf("datos",false);
	C.gaussian_distribution("datos");
	C.pdf("datos",true);
	C.cdf("datos");*/
	
	Mysqplot D ("kde");
	D.conn("data","localhost","root","root");
	D.kde("datos");
	D.kde("datos",0.5);
	D.kde("datos",1.5);
	
	return 0;
}
