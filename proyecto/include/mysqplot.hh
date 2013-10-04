#ifndef __MYSQPLOT_HH_INCLUDED__   //   if dataCV.hh hasn't been included yet...
#define __MYSQPLOT_HH_INCLUDED__   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <algorithm>  		// for sort()
#include <sstream> 		// for ostringstream
#include <cmath> 		// for abs(float) and pow()

using namespace std;

class Mysqplot{

private:

	// member data
	///\brief name of mysql table in which the data is
	string table;
	///\brief number of lines in the mysql table
	int n_lines;
	///\brief number of columms in the mysql table
	int n_cols;

public:
	
	// Constructor & Destructor
	///\brief set the mysql table name during construction
	///\param name it's the name of the table to connect in the mysql database
	Mysqplot(string);
	///\brief mysql table destructor
	~Mysqplot();
  	
  	// Member functions
  	///\brief connects to mysql server
	///\param database name of the database 
	///\param host name of the host usually named localhost
	///\param username
	///\param password
	bool conn(const char*,const char*,const char*,const char*); 

	//creo q esto es un problema 
	//pero a como lo estoy haciendo hay q crear una conexion diferente 
	//para el histograma
	bool conn(const char*,const char*,const char*,const char*,const char*);
	
	///\brief fills a vector with a determined set of rows of a determined field
	///\param inicio start position
	///\param fin end position
	///\param col_name the name of the field
	///\param &m vector that is going to be filled
	bool fill_vector(int,int, const char*, vector<double> &);
	
	///\brief fills a vector with all the data in a determined field
	///\param col_name the name of the field
	///\param &m vector that is going to be filled
	bool fill_vector(const char*, vector<double> &);
	
	///\brief fills a vector with aleatory values
	///\param col_name the name of the field
	///\param &m vector that is going to be filled
	///\param delta set the range of the posible aleatory values
	bool fill_vector(const char*, vector<double> &, int);
	
	///\brief obtain the number of lines(rows) of a determined table
	/// \return number of rows of the table that the object connected	
	int get_lines();
	
	///\brief obtain the number of fields(columns) of a determined table
	///\return number of fields of the table that the object connected
	int get_cols();
  	
  	///\brief obtain mean value of a field.
	///\param str a constant pointer to a character, the name of the field
	///\return the mean of the selected field
	float mean(const char*);
	
	///\brief obtain variance value of a field
	///\return the variance value of data taken from the selected field
	///\param str a constant pointer to a character, the name of the field 
	float variance(const char*);
	
	///\brief obtain standar deviation value of a field
	///\return the standar deviation value of data taken from the selected field
	///\param str a constant pointer to a character, the name of the field
	float standard_deviation(const char*);
	
	///\brief perform a kolgomorov-smirnov test on a set of data for a uniform distribution hypothesis.
	///\param str the name of the field desired
	///\param a the "a" parameter of the uniform distribution
	///\param b the "b" parameter of the uniform distribution
	///\return the kolmogorov test result
	double kolmogorov_test_uniform(const char*,float,float);

	bool histogram(const char*,int);
	
	///\brief displays the best-fit gaussian distributions of a set of data
	///\param str the name of the desired field 
	///\return the gaussian distribution plot
	bool gaussian_distribution(const char*);
	
	/// displays a jitterplot of a field
	///\param str the name of the desired field
	///\param delta set the range of the posible separation of equal values
	///\return the jitter plot
	bool jitterplot(const char*, int);
	
	/// displays a scatterplot of a fields, supposed to be x-y
	///\param str1	the field of the x-axis
	///\param str2  the field of the y-axis
	///\return the scatter plot	
	bool scatterplot(const char*, const char*);
	
	///\brief displays the kernel density estimation of a set of data
	///\param str the name of the field desired
	///\param bandwidth set the bandwidth of the kernel
	///\return the KDE plot
	bool kde(const char*,float=1.0);
	
	///\brief displays the Probability Density Function of a set of data
	///\param str the name of the field desired
	///\param gauss set the display of the best-fit gaussian density function (by default false==no)
	///\return the PDF plot 
	bool pdf(const char*,bool=false);
	
	///\brief displays the Cummulative Distribution Function of a set of data
	///\param str the name of the field desired
	///\return the CDF plot 
	bool cdf(const char*);
	
	///\brief obtains the best-fit gaussian density function for a discrete set of data
	///\param str  the name of the field desired
	///\return a string with the normal density function
	string gaussian_distribution_function(const char*);
};

#endif
