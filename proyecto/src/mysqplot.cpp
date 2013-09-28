#include "mysqplot.hh"

Mysqplot::Mysqplot(string name){
  table = name;
}
Mysqplot::~Mysqplot(){}

bool Mysqplot::conn(char database, char server, char username, char password){
  mysqlpp::Connection connect_object(true);
  connect_object.connect(&database, &server, &username, &password);
  mysqlpp::Query query_object = connect_object.query("SELECT * FROM " + table);
  mysqlpp::StoreQueryResult result_object = query_object.store();
  n_cols = result_object.num_fields();
  n_lines = result_object.num_rows();
  return true;
}

/*float Mysqplot::mean(int col){
  if (!col) cout<<"No collumn especified"<<endl;
}*/
