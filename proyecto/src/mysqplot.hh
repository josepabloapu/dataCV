#ifndef __MYSQPLOT_HH_INCLUDED__   //   if dataCV.hh hasn't been included yet...
#define __MYSQPLOT_HH_INCLUDED__   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
#include <stdlib>
#include <mysql++.h>
#include "gnuplot_i.hpp"

using namespace std;

class Mysqplot{

private:
  string table;
  string database;
  string server;
  string username;
  string password;
  int n_lines;
  int n_cols;
  
public:
  Mysqplot(string);
  ~Mysqplot();
  bool conn(string, string, string, string);
  bool fill(int=0,int=(n_lines-1));
  float mean(int);
  float standar_desviation();
  float variance();
  bool histogram();
  bool gaussian_distribution();
  bool jitterplot();
  bool kde();
  bool pdf();
  bool cdf();
};

#endif
