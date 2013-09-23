#include "mysqplot.hh"

Mysqplot::mysqplot(){}
Mysqplot::~mysqplot(){}

bool Mysqplot::conn(string database, string server, string username, string password){
  mysqlpp::Connection connect_object(false);
  connect_object.connect(database, server, username, password);
  mysqlpp::Query query = connect_object.query();
  n_lines = ;
  return true;
  
float Mysqplot::mean(int col){
  if (!col) cout<<"No collumn especified"<<endl;
}
