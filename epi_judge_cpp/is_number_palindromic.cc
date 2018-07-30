#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
  int ms = floor(log10(x)); 
  if( x < 0 ) return false;
  if ( x < 10) return true;
  int mask = (int) pow(10,ms);
  while(x){
      if((x / mask) != x % 10) return false;
  x %= mask;
  x/= 10;
  mask /= 100;
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
