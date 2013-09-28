#include "../../src/mysqplot.hh"
//#include "gnuplot_i.hpp"

int main(){
	
	Mysqplot A ("table1");
	A.conn("data", "localhost", "root", "root"); // ponga aca los datos de su base de datos
	std::cout << "Las columnas son " << A.n_cols << std::endl;
	std::cout << "Las filas son " << A.n_lines << std::endl;
}
 
