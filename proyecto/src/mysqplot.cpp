#include "mysqplot.hh"

Mysqplot::Mysqplot(string database, string server, string username, string password){
  mysqlpp::Connection connect_object(true);
  connect_object.connect(database, server, username, password);
}
Mysqplot::~Mysqplot(){}

bool Mysqplot::get_table(string table){
  mysqlpp::Query query_object = connect_object.query("SELECT * FROM " + table);
  mysqlpp::StoreQueryResult result_object = query_object.store();
  n_cols = result_object.num_fields();
  n_lines = result_object.num_rows();
  return true;
}

int Mysqplot::get_cols(){
  int get_cols = n_cols;
  return get_cols;
}

int Mysqplot::get_lines(){
  int get_lines = n_lines;
  return get_lines;
}

float Mysqplot::mean(int col){
  if (!col) cout<<"No collumn especified"<<endl;
}
