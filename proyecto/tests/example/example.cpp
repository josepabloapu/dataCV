#include "../../include/mysqplot.hh"

using namespace std;

int main(){

	Mysqplot Gaussdis ("gaussdis");
	Gaussdis.conn("test", "localhost", "root", "root");
	Gaussdis.gaussian_distribution("data");
	
	Mysqplot Jittertest ("jitter");
	Jittertest.conn("test", "localhost", "root", "root");
	Jittertest.jitterplot("data", 3);
	
	Mysqplot KDEtest ("kdetest");
	KDEtest.conn("test","localhost","root","root");
	KDEtest.kde("datos");
	KDEtest.kde("datos",2);
	KDEtest.kde("datos",0.5);
	
	Mysqplot PDFtest2 ("gauss");
	PDFtest2.conn("test","localhost","root","root");
	PDFtest2.pdf("datos",true);
	
	Mysqplot PDFtest1 ("pdftest1");
	PDFtest1.conn("test","localhost","root","root");
	PDFtest1.pdf("datos",true);
		
	Mysqplot PDFtest3 ("pdftest3");
	PDFtest3.conn("test","localhost","root","root");
	PDFtest3.pdf("datos",true);
	
	Mysqplot CDFtest ("pdftest1");
	CDFtest.conn("test","localhost","root","root");
	CDFtest.cdf("datos");
	
	Mysqplot KStest ("kstest");
	KStest.conn("test","localhost","root","root");
	cout<<KStest.kolmogorov_test_uniform("datos",0,1)<<endl;
	cout<<KStest.kolmogorov_test_uniform("datos",0,4)<<endl;
	cout<<KStest.kolmogorov_test_uniform("datos",0,6)<<endl;
	KStest.cdf("datos");
	return 0;
}
