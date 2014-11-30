#include <iostream>
#include "cwk.cc"
#include <fstream>
#include <vector>

using namespace std;


//2.1
template<typename T>
string test_template(T a, T b){
	if(a == b){
		return "PASS";
	} else {
		return "FAIL";
	}
}

int main(){
			
	ofstream out;
	out.open ("TestOutput_Nick.txt");
	out << "Group coursework testing" << "\n";
	out << "2.1" <<"\n";
	out << "Line 1: gcd : " <<  test_template(gcd(10,20), 10) <<"\n";
	out << "Line 2: lcm : " <<  test_template(lcm(4,5), 20) <<"\n";
	out << "Line 5: fraction() : " <<  test_template(fraction(), fraction(0,1)) <<"\n";
	out << "Line 6: fraction(n) : " <<  test_template(fraction(5), fraction(5,1)) <<"\n";
	out << "Line 7: fraction(n,n) : " <<  test_template(fraction(5,6), fraction(10,12)) <<" Also Simplified\n";
	out << "Line 7: fraction(n,n) : " <<  test_template(fraction(5,0), fraction(10,0)) <<" m=0 Simplified\n";
	fraction temp1 = fraction(5,8);
	fraction temp2 = fraction(3, 7);
	out << "Line 8:  numerator(): " <<  test_template(temp1.numerator(), 5)  << "\n";
	out << "Line 9:  denominator(): " << test_template(temp1.denominator(), 8) << "\n";
	out << "Line 11: ==:  " << (fraction(5, 8) == temp1  ? "PASS" : "FAIL")  << "\n";
	out << "Line 12: <:  " << (temp1 < fraction(17,20)  ? "PASS" : "FAIL")  << "\n";
	out << "Line 13: +=:  " << test_template(temp1 += fraction(2,16) , fraction(6,8))  << "\n";
	out << "Line 14: -= : " << test_template(temp2 -= fraction(1,7) , fraction(2,7))  << "\n";	
	fraction temp3 = fraction(3,7);
	out << "Line 15: *=: " << test_template(temp3 *= fraction(2,3) , fraction(2,7))  << "\n";	
	out << "Line 16: /=: " << test_template(temp3 /= fraction(3,6) , fraction(4,7))  << "\n";	
	out << "Line 22: fraction  + fraction: " << test_template(fraction(1,8) + fraction(2,16) , fraction(1,4))  << "\n";
	out << "Line 23: int + fraction:  " << test_template(2 + fraction(2,16) , fraction(17,8))  << "\n";
	out << "Line 24: fraction + int:  " << test_template(( fraction(2,16)  + 2) , fraction(17,8))  << "\n";
	out << "Line 23: int - fraction: " << test_template(7 - fraction(3,5) , fraction(32,5))  << "\n";
	out << "Line 24: fraction - int: " << test_template(fraction(3,5) - 7 , fraction(-32,5))  << "\n";
	out << "Line 23: int * fraction: " << test_template(5 *  fraction(3,5) , fraction(3,1))  << "\n";
	out << "Line 24: fraction * int: " << test_template(fraction(3,5) * 5 , fraction(3,1))  << "\n";
	out << "Line 23: int / fraction: " << test_template(8 / fraction(2,3) , fraction(12,1))  << "\n";
	out << "Line 24: fraction / int: " << test_template(fraction(2,3) / 8 , fraction(1,12))  << "\n";
	out << "Line 26: <<:  " << fraction(940,81) << "\n";	

	out << "2.2\n";
	sample smp =  sample();
	vector<double> v ;
	v .push_back(93.5);
	v .push_back(123);
	v .push_back(0.03);
	v .push_back(44.23);
	v .push_back(2.23);

	sample smp1 =  sample();
	vector<double> b;
	b.push_back(1.7976931348623158e+308);
	b.push_back(1.7976931348623158e+308);
	smp1.set_data(b);

	out << "Q-2: " << smp << "\n";
	out << "Q-3: " << smp.get_data() << "\n";
	smp.set_data(v);
	out << "Q-4: " << smp << "\n";
	out << "Q-5: " << test_template(smp.minimum(), 0.03) << "\n";
	out << "Q-6: " << test_template(smp.maximum(), double(123)) << "\n";
	out << "Q-7: " << test_template(smp.range(), 122.97) << "\n";
	out << "Q-8: " << test_template(smp.midrange(), 61.515) << "\n";
	out << "Q-9: " << test_template(smp.mean(), 52.598) << "\n";
	out << "Q-10: " <<smp.variance() << "== 2399.95 ?" << "\n";
	out << "Q-11: " <<smp.std_deviation() << "== 48.9893 ?" << "\n";
	out << "Q-12: " << test_template(smp.median(), 44.23) << "\n";
	out << "Q-13: " << smp1 << "\n";	
	out << "2.3\n";
	out << "Testing is unecessary as it works with single type using typename <T> therefore it will work with other types\n";

	out.close();
	return 0;
}
 
