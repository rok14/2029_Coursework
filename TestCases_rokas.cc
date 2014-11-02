#include <iostream>
#include "cwk.cc"
#include <fstream>
using namespace std;

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
		
	output.close();	
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
	results.close();
  return 0;
}