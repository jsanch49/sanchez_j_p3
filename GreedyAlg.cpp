#include "GreedyAlg.h"


bool fun(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  double ad = a.second/a.first;
  double bd = b.second/b.first;
  return ((ad - bd) > 0);
}

void GreedyAlg::computeKnapSack(int option) {
  std::chrono::time_point<std::chrono::system_clock> t0 = std::chrono::system_clock::now();
  this->maxProfit = 0;
  this->sortItems();
  int ret = -1;
  /*for (int i = 0; i < 5000; i++) {
    printf("******************\n");
  }*/
  //TODO uncomment as implemented
  if (option == 0) ret = this->GreedyAlg1();
  else if (option == 1) ret = this->GreedyAlg2();
  else if (option == 2) ret = this->BacktrackAlg();
  std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
  auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
  this->ms = time_span.count();
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
  os << this->numItems << " " << this->maxProfit << " " << this->ms << std::endl;
} 

int GreedyAlg::GreedyAlg1() {
  int sum = 0;
  int bag = 0;
  for (int i = 0; i < this->numItems; i++) {
    if (bag + this->items[i].first <= this->capacity) {
      bag += this->items[i].first;
      sum += this->items[i].second;
    }
  }
  return sum;
}

int GreedyAlg::GreedyAlg2() {
  int greedyalg1 = this->GreedyAlg1();
  int heaviestProfit = 0;
  for (int i = 0; i < this->numItems; i++) {
    if (this->items[i].second > heaviestProfit && this->items[i].first <= this->capacity) {
      heaviestProfit = this->items[i].second;
    }
  }  
  return (greedyalg1 > heaviestProfit)? greedyalg1 : heaviestProfit;
}

int GreedyAlg::bound(int profit, int w, int i) {
  if (w > this->capacity) {
    //std::cout << "SHOULD NEVER HAPPEN!!\n";
    return 0;
  }
  for (; i < this->numItems; i++) {
    if (this->capacity >= (w+items[i].first)) {
      w += items[i].first;
      profit += items[i].second;
    } else {
      break;
    }
  }
  //std::cout << "Profit: " << profit << " Capacity: " << this->capacity << " Weight: " << w << std::endl;
  if (i == this->numItems || this->capacity == w) return profit;
  
  //std::cout << "BOUND: " << profit+(left*this->items[i].second/this->items[i].first) << std::endl;
  return profit + ((this->capacity-w)*(this->items[i].second/this->items[i].first));
} 

int GreedyAlg::BacktrackAlg() {
  //std::cout << "N: " << this->numItems << " W: " << this->capacity << std::endl;
  this->BTHelper(0, 0, 0);
  return this->maxProfit;
}

void GreedyAlg::BTHelper(int i, int profit, int weight) {
  if (i > this->numItems || weight > this->capacity) return;
  if ((weight <= this->capacity) && (profit > this->maxProfit)) {
    this->maxProfit = profit;
  }
  int bd = this->bound(profit, weight, i);
  //std::cout << "BOUND: " << bd << " MAX_PROFIT: " << this->maxProfit << std::endl;
  //std::cout << "i: " << i << " Profit: " << profit << " weight: " << weight << std::endl;
  if ( (weight < this->capacity) && (bd > this->maxProfit) ) {
    this->BTHelper(i+1, profit + this->items[i].second, weight + this->items[i].first);
    this->BTHelper(i+1, profit, weight);
  }
}
