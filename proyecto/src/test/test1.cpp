#include <string>
#include <iostream>
//#include <stdlib>
#include <mysql++.h>
//#include "gnuplot_i.hpp"

int main(){

  std::string table = "table1";  
  mysqlpp::Connection connect_object(true);
  connect_object.connect("test", "localhost", "root", "root");
  mysqlpp::Query query_object = connect_object.query("SELECT * FROM " + table);
  mysqlpp::StoreQueryResult result_object = query_object.store();
  int num_fields = result_object.num_fields();
  int num_rows = result_object.num_rows();
  std::cout << "Las columnas son " << num_fields << std::endl;
  std::cout << "Las filas son " << num_rows << std::endl;
}
