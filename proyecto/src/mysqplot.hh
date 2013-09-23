#ifndef __MYSQPLOT_HH_INCLUDED__   //   if dataCV.hh hasn't been included yet...
#define __MYSQPLOT_HH_INCLUDED__   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
#include <stdlib>
#include <mysql++.h>
#include "gnuplot_i.hpp"

class mysqplot{
protected:
  string database;
  string server;
  string username;
  string password;
public:
  mysqplot();
  ~mysqplot();
  bool conn(string, string, string, string);
  float media();
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