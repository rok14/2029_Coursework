#include <iostream>
#include "cwk.cc"
#include <fstream>
using namespace std;

//Test cases for the first part.
int main () {
	
	ofstream output;
	output.open ("TestOutput_rokas.txt");
	//test default constructor
	fraction d;
	output << d << '\n';
	//test 1 param constructor
	d = fraction(5);
	output << d << '\n';
	//test 2 param constructor
	d = fraction(5, 4);
	output << d << '\n';
	//test 2 param constructor and gcd
	d = fraction(6, 12);
	output << d << '\n';
	//test == operator
	d = fraction(6, 12);
	fraction a(3,6);
	bool ans = d==a ;
	output << ans << '\n';
	//test == operator
	d = fraction(6, 12);
	a = fraction(4,6);
	ans = d==a ;
	output << ans << '\n';
	//test lcm
	output << lcm(2, 5) << '\n';
	//test lcm
	output << lcm(4, 2) << '\n';
	//test lcm
	output << lcm(6, 4) << '\n'; 
	//test lcm
	output << lcm(1, 1) << '\n';
	//test lcm
	output << lcm(10, 15) << '\n';
	//test < operator
	d = fraction(6,13);
	a = fraction(4,6);
	ans = d<a ;
	output << ans << '\n';
	//test > operator
	d = fraction(6,13);
	a = fraction(4,6);
	ans = d>a ;
	output << ans << '\n';
	//test != operator
	ans = d!=a ;
	output << ans << '\n';
	//test >= operator
	ans = d>=a ;
	output << ans << '\n';
	//test += operator (should print 44/39)
	d+=a;
	output << d << '\n';
	//test += operator (should print 1/2 )
	fraction e(1,4);
	fraction b(1,4);
	e+=b;
	output << e << '\n';
	//test -= operator (should print 6/13)
	d-=a;
	output << d << '\n';
	//test *= operator
	d = fraction(2,4);
	a = fraction(2,4);
	d*=a;
	output << d << '\n';
	//test /= operator
	d/=a;
	output << d << '\n';
	//test  operator+(int a, fraction b)
	int i = 5;
	a = fraction(1, 2);
	fraction anz = i + a;
	output << anz << '\n'; //11/2
	//test  operator+(fraction a, int b)
	anz = a + i; 
	output << anz << '\n'; //11/2
	
	//test sample << operator
	vector<double> tv;
	tv.push_back(1);
	tv.push_back(1.2);
	tv.push_back(1.3);
	tv.push_back(1.4);
	tv.push_back(1.5);
	sample s(tv);
	output << s << '\n';
	tv.push_back(1.6);
	s.set_data(tv);
	output << s << '\n';
	output << s.minimum() << '\n';
	tv.push_back(0.6);
	s.set_data(tv);
	output << s.minimum() << '\n';
	output << s.maximum() << '\n';
	output << s.range() << '\n';
	output << s.midrange() << '\n';
	vector<double> tvv;
	tvv.push_back(1);
	tvv.push_back(2);
	tvv.push_back(3);
	sample ss(tvv);
	output << ss.mean() << '\n';
	output << ss.variance() << '\n';
	output << ss.median() << '\n';
	output << s.median() << '\n';
	tvv.push_back(4);
	sample sss(tvv);
	output << sss.median() << '\n';
	output << s << '\n';
	output << "<7:1            1.2 1.3 1.4 1.5 1.6 0.6>" << '\n';
	output << ss << '\n';
	output << sss << '\n';
	output << "<2: 1.7976931348623157e+308 1.7976931348623157e+308 >" << '\n';
	
	vector<fraction> fa;
	fa.push_back(fraction(1,2));
	fa.push_back(fraction(1,3));
	fa.push_back(fraction(1,4));
	samplet<fraction> fs(fa);
	output << fs << "\n";
	output << fs.minimum() << "\n";
	output << fs.maximum() << "\n";
	output << fs.range() << "\n";
	output << fs.midrange() << "\n";
	output << fs.mean() << "\n";
	output << fs.variance() << "\n";
	output << fs.median() << "\n";
	

	
	output.close();	
	//------------------------------------------------------------------------------------------------------------------
	//now read the results and validate them
	ifstream results("TestOutput_rokas.txt"); 
	string line; 
	
	//default constructor
	getline(results, line);
	if(line!="0")
	{
		cout << "FAIL: " << line << '\n';
	}
	// 1 param constructor 
	getline(results, line); 
	if(line!="5")
	{
		cout << "FAIL: " << line << '\n';
	}
	// 2 param constructor
	getline(results, line);
	if(line!="5/4")
	{
		cout << "FAIL: " << line << '\n';
	}
	//2 param constructor and gcd
	getline(results, line);
	if(line!="1/2")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator ==
	getline(results, line);
	if(line!="1")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator ==
	getline(results, line);
	if(line!="0")
	{
		cout << "FAIL: " << line << '\n';
	}
	//test lcm
	getline(results, line);
	if(line!="10")
	{
		cout << "FAIL: " << line << '\n';
	}
	//test   lcm
	getline(results, line);
	if(line!="4")
	{
		cout << "FAIL: " << line << '\n';
	}
	//test lcm
	getline(results, line);
	if(line!="12")
	{
		cout << "FAIL: " << line << '\n';
	}
	//test lcm
	getline(results, line);
	if(line!="1")
	{
		cout << "FAIL: " << line << '\n';
	}
	//test  lcm 
	getline(results, line);
	if(line!="30")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator <
	getline(results, line);
	if(line!="1")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator >
	getline(results, line);
	if(line!="0")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator !=
	getline(results, line);
	if(line!="1")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator >=
	getline(results, line);
	if(line!="0")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator +=
	getline(results, line);
	if(line!="44/39")
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator +=
	getline(results, line);
	if(line!="1/2") 
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator -=
	getline(results, line);
	if(line!="6/13") 
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator *=
	getline(results, line);
	if(line!="1/4") 
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator /=
	getline(results, line);
	if(line!="1/2") 
	{
		cout << "FAIL: " << line << '\n';     
	}
	//operator int+fraction
	getline(results, line);
	if(line!="11/2") 
	{
		cout << "FAIL: " << line << '\n';
	}
	//operator fraction+int
	getline(results, line);
	if(line!="11/2") 
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample << operator
	getline(results, line);
	if(line!="< 5: 1 1.2 1.3 1.4 1.5 >")  	 
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample set_data
	getline(results, line);
	if(line!="< 6: 1 1.2 1.3 1.4 1.5 1.6 >")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample minimum
	getline(results, line);
	if(line!="1")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample minimum
	getline(results, line);
	if(line!="0.6")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample max
	getline(results, line); 
	if(line!="1.6")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample range
	getline(results, line);
	if(line!="1")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample midrange
	getline(results, line);
	if(line!="1.1")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample mean
	getline(results, line);
	if(line!="2")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample variance
	getline(results, line);
	if(line!="0.666667")  	  
	{
		cout << "FAILz: " << line << '\n';
	}
	//test sample median
	getline(results, line);
	if(line!="2")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample median
	getline(results, line);
	if(line!="1.3")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	//test sample median
	getline(results, line);
	if(line!="2.5")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	sample s1;
	results >> s1;
	if(s1.get_data()!=s.get_data())  	  
	{
		cout << "FAIL: " << s1 << '\n';
		cout << "      " << s << '\n';
	}
	results >> s1;
	if(s1.get_data()!=s.get_data())  	  
	{
		cout << "FAIL: " << s1 << '\n';
		cout << "      " << s << '\n';
	}
	results >> s1;
	if(s1.get_data()!=ss.get_data())  	  
	{
		cout << "FAIL: " << s1 << '\n';
		cout << "      " << ss << '\n';
	}
	results >> s1;
	if(s1.get_data()!=sss.get_data())  	  
	{
		cout << "FAIL: " << s1 << '\n';
		cout << "      " << sss << '\n';
	}
	results >> s1;
	//test samplet << operator
	getline(results, line);
	getline(results, line);
	if(line!="< 3: 1/2 1/3 1/4 >")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	getline(results, line);
	if(line!="1/4")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	getline(results, line);
	if(line!="1/2")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	getline(results, line);
	if(line!="1/4")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	getline(results, line);
	if(line!="3/8")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	getline(results, line);
	if(line!="13/36")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	getline(results, line);
	if(line!="7/648")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
		getline(results, line);
	if(line!="1/3")  	  
	{
		cout << "FAIL: " << line << '\n';
	}
	results.close();
  return 0;
}