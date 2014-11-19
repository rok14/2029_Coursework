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
	
	results.close();
  return 0;
}