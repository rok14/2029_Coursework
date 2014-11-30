#include <iostream>
#include "cwk.cc"
#include <fstream>
using namespace std;

void test_output (ifstream &results , vector<string> &tests) 
{
	string line;

	for (unsigned int i=0;i<tests.size();i++){
		
		getline(results,line);
		if(line!=tests[i])
		{
			int test = i +1;
		cout << "TEST "<< test <<" FAIL: " << line << '\n';
		}		

	}
	
}

//Test cases for the first part.
int main () {
	
	ofstream output;
	output.open ("TestOutput_jijo.txt");
	
	//1-lcm(n,m)
		output << lcm(12,8) << '\n';

	//2-gcd(n,m)
		output << gcd(12,8) << '\n';

	//3-fraction()
		fraction f;
		output << f << '\n';
	
	//4-fraction(int n)
		f=fraction(2);
		output << f << '\n';

	//5-fraction(int n, int m);
		//needs simplification
			f=fraction(12,8);
			output << f << '\n';
		//already simplified
			f=fraction(6,4);
			output << f << '\n';
		//m =0
			f=fraction(12,0);
			output << f << '\n';
	// 6- int numerator()
		output << f.numerator() << '\n';	
		f=fraction(1,2);
		output << f.numerator() << '\n';
	// 7- int denominator()
		output << f.denominator() << '\n';	
		f=fraction(12,0);
		output << f.denominator() << '\n';
	// 8 - bool operator ==
		f=fraction(6,12);
		fraction g=fraction(1,2);
		bool b=f==g;
		output << b << '\n';
		g=fraction(2,3);
		b=f==g;
		output << b << '\n';
	// 9 - bool operator < 
		f=fraction(6,12);
		g=fraction(2,3);
		b=f<g;
		output << b << '\n';
		b=g<f;
		output << b << '\n';
	// 10 - fraction &operator +=
		f+=g;
		output << f << '\n';
		//whole number 
			g=fraction(2);
			f+=g;
			output << f << '\n';
		//zero
			g=fraction();
			f+=g;
			output << f << '\n';
	// 11 - fraction &operator -=
		g=fraction(2,3);
		f-=g;
		output << f << '\n';
		//whole number 
			g=fraction(2);
			f-=g;
			output << f << '\n';
		//zero
			g=fraction();
			f-=g;
			output << f << '\n';
	// 12 - fraction &operator *=
		g=fraction(2,3);
		f*=g;
		output << f << '\n';
		//whole number 
			g=fraction(2);
			f*=g;
			output << f << '\n';
		//zero
			g=fraction();
			f*=g;
			output << f << '\n';	
	// 13 fraction &operator /=
		g=fraction(2,3);
		f=fraction(1,3);
		f/=g;
		output << f << '\n';
		//whole number 
			g=fraction(2);
			f/=g;
			output << f << '\n';
		//zero
			g=fraction();
			f/=g;
			output << f << '\n';	
	//14 fraction operator+ 
			int a =1;
			f = fraction(1,2);
			g = a + f;
			output << g << '\n';	
			g = f + a;
			output << g << '\n';	

	// 15 fraction operator-
			a =1;
			f = fraction(1,2);
			g = a - f;
			output << g << '\n';	
			g = f - a;
			output << g << '\n';				
	// 16 fraction operator*
			a =1;
			f = fraction(1,2);
			g = a * f;
			output << g << '\n';	
			g = f * a;
			output << g << '\n';

	// 17 fraction operator /
			a =1;
			f = fraction(1,2);
			g = a / f;
			output << g << '\n';	
			g = f / a;
			output << g << '\n';

	

	//sampling 
	
	//18 << operator
		vector<double> v;
		v.push_back(1.1);
		v.push_back(2.4);
		v.push_back(4.2);
		v.push_back(5.1);
		v.push_back(3.2);
		sample s = sample(v);
		output << s << '\n';

	// 19 minimum of the numbers 
		double min = s.minimum();
		output << min << '\n';

	//20 max 
		double max = s.maximum();
		output << max << '\n';

	//21 range 
		double range = s.range();
		output << range << '\n';

	// 22 midrange 
		double midrange = s.midrange();
		output << midrange << '\n';

	//23 mean 
		double mean =s.mean();
		output << mean << '\n';

	//24 variance 
		double variance = s.variance();
		output << variance << '\n';


	//25 std_dev
		double std_dev = s.std_deviation();
		output << std_dev << '\n';


	//26 double median
		double median = s.median();
		output << median << '\n';		

	//27 >> operator
		sample s2;
		cout << "enter the sample input to test" << '\n';
		cin >> s2;
		output << s2 << '\n';





	output.close();	
	//------------------------------------------------------------------------------------------------------------------
	//now read the results and validate them
		ifstream results("TestOutput_jijo.txt"); 

	//vector of strings containing the expected results for each test 
		vector<string> tests;

	//add each of the expected results in order
		tests.push_back("24"); //test - 1
		tests.push_back("4"); //test - 2
		tests.push_back("0");	//test - 3
		tests.push_back("2");	//test - 4
		tests.push_back("3/2");	//test - 5
		tests.push_back("3/2");	//test - 5
		tests.push_back("0/0");	//test - 5
		tests.push_back("0");	//test - 6
		tests.push_back("1");	//test - 6
		tests.push_back("2");	//test - 7
		tests.push_back("0");	//test - 7
		tests.push_back("1");	//test - 8
		tests.push_back("0");	//test - 8
		tests.push_back("1");	//test - 9
		tests.push_back("0");	//test - 9
		tests.push_back("7/6");	//test - 10
		tests.push_back("19/6");//test - 10
		tests.push_back("19/6");//test - 10
		tests.push_back("5/2");//test - 11
		tests.push_back("1/2");//test - 11
		tests.push_back("1/2");//test - 11
		tests.push_back("1/3");//test - 12
		tests.push_back("2/3");//test - 12
		tests.push_back("0/3");//test - 12
		tests.push_back("1/2");//test - 13
		tests.push_back("1/4");//test - 13
		tests.push_back("1/0");//test - 13
		tests.push_back("3/2");//test - 14
		tests.push_back("3/2");//test - 14
		tests.push_back("1/2");//test - 15
		tests.push_back("-1/2");//test - 15
		tests.push_back("1/2");//test - 16
		tests.push_back("1/2");//test - 16
		tests.push_back("2");//test - 17
		tests.push_back("1/2");//test - 17
		tests.push_back("< 5: 1.1 2.4 4.2 5.1 3.2 >");//test 18
		tests.push_back("1.1");//test - 19
		tests.push_back("5.1");//test - 20
		tests.push_back("4");//test - 21
		tests.push_back("3.1");//test - 22
		tests.push_back("3.2");//test - 23
		tests.push_back("1.932");//test - 24	
		tests.push_back("1.38996");//test - 25
		tests.push_back("3.2");//test - 26
		tests.push_back("< 5: 0.5 3.4 2.1 7.1 10.2 >");//test - 27

	test_output(results,tests);


	results.close();

	return 0;

}
