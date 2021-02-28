#include <vector>
#include <iostream>

//create a struct called "item" that holds
//the weight, value, and boolean variable. There will
//be a hundred (n) of these.
struct item {
  int weight_ = 0;
  int value_ = 0;
  bool indicator_ = 0;
};

bool weight(std::vector<item> x, int weight_) {
  int sum = 0;
  for (int i=0;i<x.size();i++){
    if (x[i].indicator_) {
      sum += x[i].weight_;
    }
  }
  return (sum <= weight_);
}
//obviously refactor
int value(std::vector<item> x) {
  int sum = 0;
  for (int i=0;i<x.size();i++){
    if (x[i].indicator_) {
      sum += x[i].value_;
    }
  }
  return sum;
}


