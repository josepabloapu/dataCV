#ifndef __MYSQPLOT_HH_INCLUDED__   //   if dataCV.hh hasn't been included yet...
#define __MYSQPLOT_HH_INCLUDED__   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
#include <stdlib.h>
#include <mysql++.h>

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
  
	bool conn(const char*,const char*,const char*,const char*);
	bool fill_vector(int,int, const char*, vector<double> &);
	bool fill_vector(const char*, vector<double> &);
	int get_lines();
	int get_cols();
  
	//float mean(string);
	float standar_desviation();
	float variance();
  
	bool histogram();
	bool gaussian_distribution();
	bool jitterplot();
	bool scatterplot();
	bool kde();
	bool pdf();
	bool cdf();
};

#endif
