#include "../../src/mysqplot.hh"

using namespace std;

int main(){
	
	Mysqplot A ("table1");
	
	// escriba aca los datos de su base de datos
	A.conn("data", "localhost", "root", "root"); 
	cout << "Las columnas son " << A.get_cols() << endl;
	cout << "Las filas son " << A.get_lines() << endl;
}
 
