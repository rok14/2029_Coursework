#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std::rel_ops;
using namespace std;



int gcd(int n,int m){
  if (m==0)

    {
      return abs(n);     
    }

  else gcd(m,n%m);

}

int lcm(int n, int m){
  return  abs(m * (n / gcd(n,m)));
}



int main(){
  cout <<  gcd(12,5) << endl;
  cout << lcm(12,5) << endl;
}
