#ifndef __MYSQPLOT_HH_INCLUDED__   //   if dataCV.hh hasn't been included yet...
#define __MYSQPLOT_HH_INCLUDED__   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
//#include <stdlib>
#include <mysql++.h>
//#include "gnuplot_i.hpp"

using namespace std;

class Mysqplot{

private:
  string table;
  string database;
  string server;
  string username;
  string password;
  vector<float>* ptdata;

public:

  int n_lines;
  int n_cols;

  Mysqplot(string);
  ~Mysqplot();
  bool conn(const char*,const char*,const char*,const char*);
  bool fill(int,int);
  float mean(int);
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
