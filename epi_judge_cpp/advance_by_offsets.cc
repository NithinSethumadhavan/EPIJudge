#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;
bool CanReachEnd(const vector<int>& max_advance_steps) {
  const vector<int> a = max_advance_steps;
  int length = a.size();
  int cmax = 0;
  for(int i = 0; i <= cmax && cmax < length; ++i){
    cmax = std::max(cmax,a[i]+i);
  }
  return cmax >= length-1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
