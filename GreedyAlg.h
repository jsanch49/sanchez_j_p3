#ifndef GREEDYALG_H_JSANCH
#define GREEDYALG_H_JSANCH

#include <iostream>
#include <utility>
#include <algorithm>
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>

//HLLE
class GreedyAlg {
  private:
    int numItems;
    int capacity;
    std::pair<int, int> * items; // <weight, profit>
    int maxProfit;
    double seconds;
    int GreedyAlg1();
    int GreedyAlg2();
    int BacktrackAlg();
    void sortItems();
  public:
    GreedyAlg(int _num, int _cap, std::pair<int, int> * _items) : numItems(_num), capacity(_cap), items(_items) {};
    void computeKnapSack(int option);
    void printOut(std::ostream &os);
};


#endif
