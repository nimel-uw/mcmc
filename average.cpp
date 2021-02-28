#include <iostream>
#include "mcmc.cpp"

int main() {
  double sum = 0;
  for(int i = 0; i< 1000; i++) {
    sum += mcmc();
  }
  double avg = sum/1000;
  std::cout << "average # of items in knapsack: " << avg << std::endl;
}
