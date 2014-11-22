//rokas: if you change the code pls re-run TestCases_Rokas before comiting. Feel free to add your own test cases.
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std::rel_ops;
using namespace std;
//2.1 Divide and Conquer. . . (25 marks)
int gcd( int n, int m)
{
	for(int i=min(n,m);i>0;i--)
	{
		if(div(n, i).rem==0 && div(m, i).rem==0)
		{
			return i;
		}
	}
	return 1;
} //(1 mark) remove the semicolon (;) if you add code;
int lcm( int n, int m)
{
	for(int i=1;i<=min(n,m);i++)
	{
		for(int j=1;j<=max(n,m);j++)
		{
			if(max(n,m)*i==min(n,m)*j)
			{
				return max(n,m)*i;
			}
		}
	}
	return m*n;
} //(1 mark) only classes end with a semicolon (;).
class fraction {
	public:
		fraction() : numer(0), denomer(1) {} //(1 mark) 0/1
		fraction(int n) : numer(n), denomer(1){} //(1 mark) n/1
		fraction(int n, int m)
		{
			if(m!=0)
			{
					numer = n;
					denomer =m;
					simplify();
			}else
			{
				numer=0;
				denomer=0;
			}
		} //(2 marks) n/m SIMPLIFIED; 0/0 when m=0
		int numerator() const { return numer; }// (1 mark)
		int denominator() const { return denomer; }// (1 mark)
		// methods below - 2 marks each
		bool operator==(const fraction &o) const
		{
			return o.denominator() == denomer && o.numerator()==numer;
		}
		//(2 marks) use utility & rel_ops to
		bool operator<(const fraction &o) const
		{
			int lcmul = lcm(denominator(), o.denominator());
			return o.numerator()*(lcmul/o.denominator()) > numerator()*(lcmul/denominator());
		}
		//(2 marks) get the other operators
		fraction &operator+=(const fraction &o)//(2 marks)
		{
			int lcmul = lcm(denominator(), o.denominator());
			numer = o.numerator()*(lcmul/o.denominator()) + numerator()*(lcmul/denominator());
			denomer = lcmul;
			simplify();
			return *this;
		}
		fraction &operator-=(const fraction &o)//(2 marks)
		{
			int lcmul = lcm(denominator(), o.denominator());
			numer = numerator()*(lcmul/denominator()) - o.numerator()*(lcmul/o.denominator());
			denomer = lcmul;
			simplify();
			return *this;			
		}
		fraction &operator*=(const fraction &o)//(2 marks)
		{
			numer = numerator() * o.numerator();
			denomer = denominator() * o.denominator();
			simplify();
			return *this;
		}
		fraction &operator/=(const fraction &o)//(2 marks)
		{
			numer = numerator() * o.denominator();
			denomer = denominator() * o.numerator();
			simplify();
			return *this;
		}
	private:
		int numer, denomer;
		void simplify()
		{
			int gcdiv=gcd(numer ,denomer);
			numer = numer/gcdiv;
			denomer =denomer/gcdiv;
		}
	// ...
};
// you need the following for all operators - they’re too simple; see
// the first one. 1 mark for all 12 of them. (1 mark)
fraction operator+(fraction a, fraction b) {return a+=b;}
fraction operator+(int a, fraction b) 
{
	fraction af(a, 1);
	return af+=b;
}
fraction operator+(fraction a, int b)
{
	fraction bf(b, 1);
	return a+=bf;
}
//-
fraction operator-(fraction a, fraction b) {return a-=b;}
fraction operator-(int a, fraction b) 
{
	fraction af(a, 1);
	return af-=b;
}
fraction operator-(fraction a, int b)
{
	fraction bf(b, 1);
	return a-=bf;
}
//*
fraction operator*(fraction a, fraction b) {return a*=b;}
fraction operator*(int a, fraction b) 
{
	fraction af(a, 1);
	return af*=b;
}
fraction operator*(fraction a, int b)
{
	fraction bf(b, 1);
	return a*=bf;
}
// /
fraction operator/(fraction a, fraction b) {return a/=b;}
fraction operator/(int a, fraction b) 
{
	fraction af(a, 1);
	return af/=b;
}
fraction operator/(fraction a, int b)
{
	fraction bf(b, 1);
	return a/=bf;
}
// 2 marks each for the following two
ostream & operator<<( ostream &os, const fraction &f)
{
	os << f.numerator();
	if(f.denominator()!=1)
	{	
		os	<< '/' << f.denominator();
	}
	return os;
} //(2 marks) format: n/m
istream & operator>>( istream &os, fraction &f)
{
	int n, m;
	char fs;//forward slash
	if(!(os >> n >> fs >> m))
	{
		os.setstate(ios::badbit); 
	}else
	{
		if(fs=='/')	
		{
			f= fraction(n, m);
		}
	}
	return os;
}

double globalmean;
double variance_helper(double sum, double y)
{
	return sum+=pow((y-globalmean), 2);
}
//2.2 Sampling
class sample
{
	//Q-1. (1 mark ) How could you have forced programmers using your class to not initialise empty sampleobjects (i.e., without providing a vector to initialise them with)?
	//ANSWER: This could be done by not providing default constructor. When there's no default constructor and a programmer tries to initialise an empty object the code doesn't compile.

	public:
		sample(){}
		sample(vector<double> vec): measurement(vec){} 
		const vector<double> &get_data() const{ return measurement;} //Q-3
		void set_data(const vector<double> &v){ measurement = v;} //Q-4
		double minimum() const { return *min_element(begin(measurement), end(measurement));}
		double maximum() const { return *max_element(begin(measurement), end(measurement));}
		double range() const { return maximum()-minimum();}
		double midrange() const { return (maximum()+minimum())/2;}
		double mean() const { return std::accumulate(begin(measurement), end(measurement), 0.0)/measurement.size();}

		double variance() const { globalmean = mean(); return accumulate(begin(measurement), end(measurement), 0.0, variance_helper)/measurement.size();}
		double std_deviation() const { return sqrt(variance());}
		double median() const
		{
			vector<double> sorted_measurement = measurement;
			sort(sorted_measurement.begin(), sorted_measurement.end());
			int n = measurement.size();
			div_t divresult = div(n, 2);
			if(divresult.rem==1)
			{
				return sorted_measurement[n/2];
			}else
			{
				return (sorted_measurement[n/2-1] + sorted_measurement[n/2])/2.0;
			}
		}
		
			
		
	private:
		vector<double> measurement;

};
//Q-2. (1 mark ) Overload the << operator so that you can write a sample to an output stream.
//The output format should be:
//’<’ space int ’:’ space num1 space ... numN space ’>’,
//e.g., < 2: 10.3 35 >. Do NOT change the format.
template<class T> struct print_it : public unary_function<T, void>
{
	ostream &os;
	print_it(ostream& o) : os(o){}
	void operator()(T x){ os << x << " "; }
};
ostream & operator<<( ostream &os, const sample &s) 
{
	const vector<double> data = s.get_data();//
	os << "< " << data.size() << ": ";
	/* Q-14
		input:		<2: 1.7976931348623158e+308 1.7976931348623158e+308 >
		my output:  <2: 1.79769313486232e+308 1.79769313486232e+308 >
		
		Doubles in input string contain 17 precision digits each. In order to print them exactly as in input I would need to
		set my output stream precision to numeric_limits<double>::max_digits10 (17). I'm reluctant to do so since
		the minimum guaranteed number of digits for double is numeric_limits<double>::digits10 (15), which means that 
		digits 1-15 are ALWAYS valid while 16th and 17th digits MAY be junk. 
		This could cause 1.4 being printed as 1.3999999999999999 or 1.6 printed as 1.6000000000000001
	*/
	int default_precision = os.precision();
	os.precision(numeric_limits<double>::digits10);
	for_each(begin(data), end(data), print_it<double>(os));
	os.precision(default_precision);
	os << ">";
	return os;
}	

istream & operator>>( istream &is, sample &s)
{
	vector<double> data;
	int n;
	char less_than, more_than, colon;
	is >> less_than;
	if(less_than == '<'){
		is >> n;
		is >> colon;
		while(colon==' '){is >> colon;} //skip optional whitespace
		if(colon==':'){
			double d;
			for(int i=0; i< n; i++)
			{
				is >> d;
				data.push_back(d);
			}
			is >> more_than;
			while(more_than==' '){is >> more_than;} //skip optional whitespace
			if(more_than == '>')
			{
				s = sample(data);
				return is;
			}
		}
		
	}
	is.setstate(ios::badbit); 
	return is;
}

//Q-15 return type of samplet's member function but a generic type T, 
//so that for samplet<fraction> member functions could return objects of type fraction 
//or for samplet<int> member functions could return integers
template<class T> class samplet
{
	public:
		samplet(){}
		
		samplet(vector<T> vec): measurement(vec){} 
		const vector<T> &get_data() const{ return measurement;}
		void set_data(const vector<T> &v){ measurement = v;} 
		T minimum() const { return *min_element(begin(measurement), end(measurement));}
		T maximum() const { return *max_element(begin(measurement), end(measurement));}
		T range() const { return maximum()-minimum();}
		T midrange() const { return (maximum()+minimum())/2;}
		T mean() const { 
			T innit = 0; /*not sure what I'm doing here but it works*/ 
			return accumulate(begin(measurement), end(measurement), innit)/measurement.size();
		}
		T variance() const { 
			T innit = 0;
			for(typename vector<T>::const_iterator iter = begin(measurement); iter != end(measurement); iter++)
			{
				innit+=(*iter-mean())*(*iter-mean());
			}
			return innit/measurement.size();
		}
		
		T std_deviation() const { return sqrt(variance());}
		
		T median() const
		{
			vector<T> sorted_measurement = measurement;
			sort(sorted_measurement.begin(), sorted_measurement.end());
			int n = measurement.size();
			div_t divresult = div(n, 2);
			if(divresult.rem==1)
			{
				return sorted_measurement[n/2];
			}else
			{
				return (sorted_measurement[n/2-1] + sorted_measurement[n/2])/2.0;
			}
		}
		
			
		
	private:
		vector<T> measurement;
		
};

template<typename T>
ostream & operator<<( ostream &os, const samplet<T> &s) 
{
	const vector<T> data = s.get_data();//
	os << "< " << data.size() << ": ";
	for_each(begin(data), end(data), print_it<T>(os));
	os << ">";
	return os;
}	