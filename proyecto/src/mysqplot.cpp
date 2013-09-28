#include "mysqplot.hh"
#include "gnuplot_i.hpp"

mysqlpp::StoreQueryResult result_object;

Mysqplot::Mysqplot(string name){
  table = name;
}

Mysqplot::~Mysqplot(){}

bool Mysqplot::conn(const char* database, const char* server, const char* username, const char* password){
	mysqlpp::Connection connect_object(true);
	connect_object.connect(database, server, username, password);
	mysqlpp::Query query_object = connect_object.query("SELECT * FROM " + table);
	//mysqlpp::StoreQueryResult result_object = query_object.store();
	result_object = query_object.store();
	n_cols = result_object.num_fields();
	n_lines = result_object.num_rows();
	return true;
}

bool Mysqplot::fill_vector(int inicio, int fin, const char* col_name, vector<double> &m){
	for(int i=inicio; i<=fin; ++i) {
		// en este caso "col_name" es el nombre de la columna
        m.push_back((double)result_object[i][col_name]);
    }
	return true;
}

bool Mysqplot::fill_vector(const char* col_name, vector<double> &m){
	for(int i=0; i<(this->get_lines()); ++i) {
        m.push_back((double)result_object[i][col_name]);
    }    
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

float Mysqplot::mean(const char* str){
	float mean = 0;
	for(int i=0;i<(this->get_lines());++i) mean+=(float)result_object[i][str];
	mean = mean/this->get_lines();
	return mean;
}

//float mean(vector<double> &m){
	
