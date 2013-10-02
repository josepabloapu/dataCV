#include "../../include/mysqplot.hh"

using namespace std;

int main(){
	/*Mysqplot A ("table3");
	A.conn("test", "localhost", "root", "root");
	A.pdf("datos");
	A.cdf("datos");*/
	/*
	Mysqplot B ("scatter");
	B.conn("test", "localhost", "root", "root");
	B.scatterplot("x","y");
	
	Mysqplot C ("gauss");
	C.conn("test", "localhost", "root", "root");
	//C.mean("datos");
	C.pdf("datos",false);
	C.gaussian_distribution("datos");
	C.pdf("datos",true);
	C.cdf("datos");
	*/
	Mysqplot C ("jitter");
	C.conn("test", "localhost", "root", "root");
	C.jitterplot("data",1);

	return 0;
}
