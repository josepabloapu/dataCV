#include "mysqplot.hh"
#include "gnuplot_i.hpp"

Mysqplot::Mysqplot(string name){
  table = name;
}
Mysqplot::~Mysqplot(){}

bool Mysqplot::conn(const char* database, const char* server, const char* username, const char* password){
	mysqlpp::Connection connect_object(true);
	connect_object.connect(database, server, username, password);
	mysqlpp::Query query_object = connect_object.query("SELECT * FROM " + table);
	mysqlpp::StoreQueryResult result_object = query_object.store();
	n_cols = result_object.num_fields();
	n_lines = result_object.num_rows();
	return true;
}

int Mysqplot::get_lines(){
	int n = this->n_lines;
	return n;
}

int Mysqplot::get_cols(){
	int n = this->n_cols;
	return n;
}

/*float Mysqplot::mean(int col){
  if (!col) cout<<"No collumn especified"<<endl;
}*/
