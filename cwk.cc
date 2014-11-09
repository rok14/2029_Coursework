//rokas: if you change the code pls re-run TestCases_Rokas before comiting. Feel free to add your own test cases.
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>

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
//2.2 Sampling
class sample
{
	//Q-1. (1 mark ) How could you have forced programmers using your class to not initialise empty sampleobjects (i.e., without providing a vector to initialise them with)?
	//ANSWER: This could be done by not providing default constructor. When there's no default constructor and a programmer tries to initialise an empty object the code doesn't compile.

	public:
		sample(){}
		sample(vector<double> vec): measurement(vec){}
		const vector<double> &get_data(){ return measurement;}
		void set_data(const vector<double> &v){ measurement = v;}
	private:
		vector<double> measurement;
};

ostream & operator<<( ostream &os, sample &s)
{
	const vector<double> data = s.get_data();//
	os << "< " << data.size() << ": ";
	for(vector<double>::const_iterator it= data.begin(); it!= data.end(); it++)
	{
		os << *it << " ";
	}
	os << ">";
	return os;
}	