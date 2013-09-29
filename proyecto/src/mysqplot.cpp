#include "mysqplot.hh"
#include "gnuplot_i.hpp"

mysqlpp::StoreQueryResult result_object;

void wait_for_key ()
{
    cout << endl << "Press ENTER to continue..." << endl;

    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    return;
}

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

bool Mysqplot::pdf(const char* str){
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	float ymax=0;
	float xmax=0;
	
	this->fill_vector(str,x);
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<x.size();++i){
		for(int j=0;j<v1.size();++j){
			if (x[i]==v1[j]){ 
				flag=1;
				v2[j]+=1;
			}					
		}
		if (flag==0){ 
			v1.push_back(x[i]);
			v2.push_back((double)1);
		}
		flag=0;
	}
	
	for(int i=0;i<v2.size();++i){
		v2[i]=v2[i]/x.size();
		if (v2[i]>ymax) ymax=v2[i];
	}
	
	for(int i=0;i<v1.size();++i){
		if (v1[i]>xmax) xmax=v1[i];
	}

	Gnuplot g1("PDF");
	g1.set_xrange(0,xmax).set_yrange(0,ymax);
	g1.set_style("impulses").plot_xy(v1,v2,str);
	wait_for_key();
	return true;
}
