#include <vector>
#include <iostream>
#include "rand_int_in_n.cpp"
#include "knapsack.cpp"

int mcmc() {
  int n = 100;
  int k = 0;
  int best_value = 0;
  int weight_ = 50;//arbitrary
  std::vector<item> x;

  //randomize the weights and values
  for (int i = 0; i < n; i++ ) {
    item new_item;
    new_item.weight_ = rand_int_in_n(10);
    new_item.value_ = rand_int_in_n(10);
    //indicator remains zero initially
    x.push_back(new_item);
  }
  
  
  std::vector<item> best_x = x;
  //  best_value_ = value(best_x);
  std::vector<item> new_x = x;

  for (int i = 0; i < n; i++) {
    k = rand_int_in_n(n);
    new_x[k].indicator_ = !x[k].indicator_;
    //check new_x's weight condition
    if ( weight(new_x, weight_) ) {
      x = new_x;
    }
    if ( value(x) > value(best_x) ){//obv don't call the function, just store the value.
      best_x = x;
    }
  }
  int sum = 0;
  for (int i=0;i<n;i++) {
  
    if (best_x[i].indicator_) {
      //std::cout << "item #" << i << std::endl;
      //std::cout << "weight: " << best_x[i].weight_ << " ";
      //std::cout << "value: " << best_x[i].value_ << " ";
      //std::cout << std::endl;
      sum += 1;
    }
    
  }
  
  //std::cout << sum << " items in the locally optimized knapsack!" << std::endl;
  
  return sum;
}
