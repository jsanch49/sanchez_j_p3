#include "GreedyAlg.h"

//HLEE

bool fun(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  double ad = a.second/a.first;
  double bd = b.second/b.first;
  return ((ad - bd) > 0);
}

void GreedyAlg::computeKnapSack(int option) {
  std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
  this->sortItems();
  int ret = -1;
  //TODO uncomment as implemented
  //if (option == 0) ret = this->GreedyAlg1();
  //else if (option == 1) ret = this->GreedyAlg2();
  //else if (option == 2) ret = this->BacktrackAlg();
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t1-t0);
  this->seconds = time_span.count();
  this->maxProfit = ret; 
}

void GreedyAlg::sortItems() {
  if (!this->items) {
    std::cout << "SHOULD NEVER HAPPEN!\n";
    return;
  }
  std::sort(&this->items[0], &this->items[this->numItems], fun); 
}

void GreedyAlg::printOut(std::ostream &os) {
  os << this->numItems << " " << this->maxProfit << " " << this->seconds << std::endl;
} 

/*int GreedyAlg::GreedyAlg1() {
  

}*/

