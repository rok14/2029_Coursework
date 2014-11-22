#include <iostream>
#include "cwk.cc"

using namespace std;

int main(void) {
sample s;

while (cin >> s)
 cout << s << endl
 << s.minimum() << endl << s.maximum() << endl
 << s.range() << endl << s.midrange() << endl
 << s.median() << endl << s.mean() << endl
 << s.variance() << endl << s.std_deviation() << endl;

 if (cin.bad()) cerr << "\nBad input\n\n";
 return(0);
 }
