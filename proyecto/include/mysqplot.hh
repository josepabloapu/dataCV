#ifndef __MYSQPLOT_HH_INCLUDED__   //   if dataCV.hh hasn't been included yet...
#define __MYSQPLOT_HH_INCLUDED__   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
#include <stdlib.h>  // no me acuerdo para que esta
#include <mysql++.h>
#include <algorithm>  // sort()
#include <sstream>
//#include <cstdlib>

using namespace std;

class Mysqplot{

private:

	string table;
	//string database;
	//string server;
	//string username;
	//string password;
	int n_lines;
	int n_cols;
	//vector<float>* ptdata;

public:

	Mysqplot(string);
	~Mysqplot();
  	///connects to mysql server
	bool conn(const char*,const char*,const char*,const char*); 
	///
	bool fill_vector(int,int, const char*, vector<double> &);
	///
	bool fill_vector(const char*, vector<double> &);
	///fills a vector of aleatory values from -delta to +delta, where delta is the int parameter
	bool fill_vector(const char*, vector<double> &, int);
	///obtain the number of lines(rows) of a determined table
	int get_lines();
	///obtain the number of fields(columns) of a determined table
	int get_cols();
  	/// obtain mean value of a field
	float mean(const char*);
	/// obtain variance value of a field
	float variance(const char*);
	/// obtain standar deviation value of a field
	float standard_deviation(const char*);
	///
	bool histogram();
	/// displays a gaussian distributions of a field
	bool gaussian_distribution(const char*);
	/// displays a jitterplot of a field
	bool jitterplot(const char*, int);
	/// displays a scatterplot of a fields, supposed to be x-y
	bool scatterplot(const char*, const char*);
	/// displays a kernel density estimates function of a fields
	bool kde(const char*,float=1.0);
	/// displays a kernel density estimates function of a fields
	bool pdf(const char*,bool=false);
	/// displays a cumulative distribution function of a fields
	bool cdf(const char*);
	///
	string gaussian_distribution_function(const char*);
};

#endif
