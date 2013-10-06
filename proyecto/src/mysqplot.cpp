#include "../include/mysqplot.hh"
#include "../include/gnuplot_i.hpp"

////////////////////////////////////////////////////////////////
// Auxiliary functions

///\brief holds the figure displayer until you press a key
void wait_for_key ()
{
    cout << endl << "Press ENTER to continue..." << endl;

    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    return;
}

///\brief transforme an integer to string
///\param Number  
///\return string
std::string NumberToString (int Number)
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

///\brief transforme float to string
///\param Number  
///\return string
std::string NumberToString (float Number)
{
    stringstream ss (stringstream::in | stringstream::out);
    ss << Number;
    return ss.str();
}

std::string step (float a){
	return "x>"+NumberToString(a)+" ? 1 : 0";
}

///\brief set the scale to be used on the plot
///\param &v1 the vector
///\param minimun min value of the vector
///\param maximun max value of the vector
void minMax(vector<double> &v1,float &min,float &max){
	for(int i=0;i<(int)v1.size();++i){
		if (v1[i]>max) max=v1[i];
		if (v1[i]<min) min=v1[i];
	}
	return;
}

string normal_standard_density(float shift,float scale){
	string sh = NumberToString (shift);
	string sc = NumberToString (scale);
	
	string function = "(1/("+sc+"*(2*pi)**(0.5)))*exp(-((((x-"+sh+")/"+sc+")**2)/2))";
	return function;
}

///////////////////////////////////////////////////////////////////

mysqlpp::StoreQueryResult result_object;

Mysqplot::Mysqplot(string name){
  table = name;
}

Mysqplot::~Mysqplot(){}

bool Mysqplot::conn(const char* database, const char* server, const char* username, const char* password){
	mysqlpp::Connection connect_object(true);
	connect_object.connect(database, server, username, password);
	mysqlpp::Query query_object = connect_object.query("SELECT * FROM " + table);
	result_object = query_object.store();
	n_cols = result_object.num_fields();
	n_lines = result_object.num_rows();
	return true;
}

bool Mysqplot::conn(const char* field, const char* database, const char* server, const char* username, const char* password){
	string query = "";
	query = "SELECT *";
	query = query + ", COUNT(*) AS repetitions FROM ";
	query = query + table;
	query = query + " GROUP BY " + field + " ORDER BY " + field;

	mysqlpp::Connection connect_object(true);
	connect_object.connect(database, server, username, password);
	mysqlpp::Query query_object = connect_object.query(query);
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

bool Mysqplot::fill_vector(const char* col_name, vector<double> &m, int delta){
	float LO = 5-delta;
	float HI = 5+delta;
	for(int i=0; i<(this->get_lines()); ++i) {
        m.push_back(LO + (float)rand()/((float)RAND_MAX/(HI-LO)));
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
	float mean = 0.0;
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	
	this->fill_vector(str,x);
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<(int)x.size();++i){
		for(int j=0;j<(int)v1.size();++j){
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
	
	for(int i=0;i<(int)v2.size();++i){
		v2[i]=v2[i]/x.size();
	}
	
	for(int i=0;i<(int)v1.size();++i) mean+=v2[i]*v1[i]; 
	return mean;
}

float Mysqplot::variance(const char* str){
	float variance = 0.0;
	float mean = this->mean(str);
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	
	this->fill_vector(str,x);
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<(int)x.size();++i){
		for(int j=0;j<(int)v1.size();++j){
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
	
	for(int i=0;i<(int)v2.size();++i){
		v2[i]=v2[i]/x.size();
	}
		
	for(int i=0;i<(int)v2.size();++i)
		variance+=v2[i]*pow((v1[i]-mean), 2);
	
	return variance;
}

float Mysqplot::standard_deviation(const char* str){
	float standard_deviation = 0;
	standard_deviation = pow((float)this->variance(str), 0.5);
	return standard_deviation;
}

bool Mysqplot::histogram(const char* str1, int cols){
	vector<double> x, y;
	const char* str2 = "repetitions";
	float xmax=0;
	float ymax =0;
	float ymin=0;
	float xmin=0;

	this->fill_vector(str1, x);
	this->fill_vector(str2, y);

	minMax(x,xmin,xmax);
	minMax(y,ymin,ymax);

	Gnuplot g1("Histogram");
	g1.set_legend("outside right top");
	g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(ymin-(0.5*ymin),ymax+(0.5*ymax));
	g1.set_style("steps").plot_xy(x,y,(string)str2+" vs. "+(string)str1);
	
	wait_for_key();
	return true;

}

bool Mysqplot::gaussian_distribution(const char* str){
	
	string function = this->gaussian_distribution_function(str);
	
	Gnuplot g1("Gaussian Distribution");
	g1.set_style("lines");
	g1.plot_equation(function,"Gaussian Distribution");
	wait_for_key();
	return true;
}

bool Mysqplot::scatterplot(const char* str1, const char* str2){
	vector<double> x, y;
	float xmax=0;
	float ymax =0;
	float ymin=0;
	float xmin=0;
	float Sx=0,Sy=0,Sxx=0,Sxy=0;
	
	this->fill_vector(str1, x);
	this->fill_vector(str2, y);
	
	minMax(x,xmin,xmax);
	minMax(y,ymin,ymax);
	
	for(int i=0;i<(int)x.size();++i){
	Sx+=x[i];
	Sy+=y[i];
	Sxx+=x[i]*x[i];
	Sxy+=x[i]*y[i];
	}

	float m=((x.size())*Sxy-Sx*Sy)/((x.size())*Sxx-Sx*Sx);
	float b=(Sxx*Sy-Sx*Sxy)/((x.size())*Sxx-Sx*Sx);
	
	cout << "y = " << m << "x + " << b << endl;
	
	Gnuplot g1("Scatterplot");
	g1.set_legend("outside right top");
	g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(ymin-(0.5*ymin),ymax+(0.5*ymax));
	g1.set_style("points").plot_xy(x,y,(string)str2+" vs. "+(string)str1);
	g1.set_style("lines").plot_slope(m,b,"y="+NumberToString(m)+"x+"+NumberToString(b));
	wait_for_key();
	return true;
}

bool Mysqplot::jitterplot(const char* str, int delta){
	vector<double> x;
	vector<double> y;
	float xmax=0;
	float xmin=0;
	float ymax=20;
	float ymin=0;
	
	this->fill_vector(str,x);
	this->fill_vector(str,y,delta);
	minMax(x,xmin,xmax);

	Gnuplot g1("Jitterplot");
	g1.cmd("unset ytics");
	g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(ymin-(0.5*ymin),ymax+(0.5*ymax));
	g1.set_style("points").plot_xy(x,y,str);
	
	wait_for_key();
	return true;
}
	

bool Mysqplot::pdf(const char* str,bool gauss){
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	float ymax=0;
	float xmax=0;
	float ymin=0;
	float xmin=0;
	
	this->fill_vector(str,x);
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<(int)x.size();++i){
		for(int j=0;j<(int)v1.size();++j){
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
	
	for(int i=0;i<(int)v2.size();++i){
		v2[i]=v2[i]/x.size();
	}
	
	minMax(v1,xmin,xmax);
	minMax(v2,ymin,ymax);

	if(gauss==false){
		Gnuplot g1("PDF");
		g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(ymin-(0.25*ymin),ymax+(0.25*ymax));
		g1.set_style("impulses").plot_xy(v1,v2,str);
		wait_for_key();
	}
	else{		
		string gauss=this->gaussian_distribution_function(str);
		
		Gnuplot g1("PDF");
		g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(ymin-(0.25*ymin),ymax+(0.25*ymax));
		g1.set_style("impulses").plot_xy(v1,v2,str);
		g1.set_style("lines").plot_equation(gauss,"Gaussian Distribution");
		wait_for_key();
	}
	return true;
}

bool Mysqplot::cdf(const char* str){	
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	float xmax=0;
	float xmin=0;
	string function="";
	
	this->fill_vector(str,x);
	
	sort(x.begin(), x.end());
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<(int)x.size();++i){
		for(int j=0;j<(int)v1.size();++j){
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
	
	for(int i=0;i<(int)v2.size();++i){
		v2[i]=v2[i]/x.size();
	}
	
	minMax(v1,xmin,xmax);
	
	for(int i=0;i<(int)v2.size();++i)
		function+="+"+NumberToString((float)v2[i])+"*("+step(v1[i])+")";
		
	Gnuplot g1("CDF");
	g1.set_legend("outside right top");
	g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(-0.2,1.2);
	g1.set_style("steps").plot_equation(function,str);
	wait_for_key();
	return true;
}

bool Mysqplot::kde(const char* str, float bandwidth){
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	float ymax=0;
	float xmax=0;
	float ymin=0;
	float xmin=0;
	vector<string> kernels;
	string result="";
	
	this->fill_vector(str,x);
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<(int)x.size();++i){
		for(int j=0;j<(int)v1.size();++j){
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
	
	for(int i=0;i<(int)v1.size();i++){
		kernels.push_back(NumberToString((float)v2[i])+"*"+
					normal_standard_density((float)v1[i],bandwidth));
	}
		
	minMax(v1,xmin,xmax);
	minMax(v2,ymin,ymax);
	
	for(int i=0;i<(int)kernels.size();i++) result+="+"+kernels[i];
	
	Gnuplot g1("KDE");
	g1.set_legend("outside right top");
	g1.set_xrange(xmin-(0.5*xmin),xmax+(0.5*xmax)).set_yrange(0,ymax);
	g1.set_style("lines").plot_equation(result,str);
	
	wait_for_key();
	return true;
}

string Mysqplot::gaussian_distribution_function(const char* str){
	float variance_num = this->variance(str);
	float mean_num = this->mean(str);

	std::string variance = NumberToString (variance_num);
	std::string mean = NumberToString (mean_num);
	
	string function = "(1/((2*pi*"+variance+")**(0.5)))*exp(-((x-"+mean+")**2)/(2*"+variance+"))";
	return function;
}

double Mysqplot::kolmogorov_test_uniform(const char* str,float a,float b){
	vector<double> x;
	vector<double> v1,v2;
	int flag=0;
	double** hy_pt;
	double Dn=0;
	
	this->fill_vector(str,x);
	
	sort(x.begin(), x.end());
	
	v1.push_back(x[0]);
	v2.push_back((double)1);	
	for(int i=1;i<(int)x.size();++i){
		for(int j=0;j<(int)v1.size();++j){
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
	
	for(int i=0;i<(int)v2.size();++i){
		v2[i]=v2[i]/x.size();
	}
	
	for(int i=1;i<(int)v2.size();++i){
		v2[i]=v2[i]+v2[i-1];
	}

	hy_pt = new double* [v1.size()];
	
	for(int i=0;i<(int)v1.size();++i){
		hy_pt[i]=new double[2];
	}
	
	for(int i=0;i<(int)v1.size();++i){
		hy_pt[i][0]=v1[i];
		if(v1[i]<a)
			hy_pt[i][1]=0;
		if((v1[i]>=a) && (v1[i]<b))
			hy_pt[i][1]=(v1[i]-a)/(b-a);
		if(v1[i]>=b)
			hy_pt[i][1]=1;
	}
	
	for(int i=0;i<(int)v1.size();++i){
		double temp;
		temp = abs(v2[i]-hy_pt[i][1]);
		if (temp>Dn) Dn=temp;
	}
	
	for(int i=0;i<(int)v1.size();++i)
		delete [] hy_pt[i];
	delete [] hy_pt;
	
	return Dn; 
	
}
