#include "../mysqplot.hh"
//#include "gnuplot_i.hpp"

int main(){
  Mysqplot A ("test", "localhost", "root", "root");
  A.get_table("table1");
  cols = A.get_cols;
  lines = A.get_lines;
  std::cout << "Las columnas son " << cols << std::endl;
  std::cout << "Las filas son " << lines << std::endl;
}
 