#include "../../src/mysqplot.hh"

using namespace std;

int main(){
	
	Mysqplot A ("table1");
	vector<double> x,y; 
	
	// escriba aca los datos de su base de datos
	A.conn("data", "localhost", "root", "root"); 
	cout << "Las columnas son " << A.get_cols() << endl;
	cout << "Las filas son " << A.get_lines() << endl;
	A.fill_vector(1,4,"datos",x);
	A.fill_vector("datos",y);
	for(int i=0;i<x.size();++i) cout<<x[i]<<endl;
	for(int i=0;i<y.size();++i) cout<<y[i]<<endl;
	cout<<"la media es: "<< A.mean("datos") <<endl;
}
 
