#include <iostream>
#include <fstream>
#include <cstring>
#include "GreedyAlg.h"


int main(int argc, char ** argv) {
  if (argc != 4)
    return 1;
    
  std::string line;
  
  std::ofstream ofs;
  ofs.open(argv[2], std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  std::ifstream in_file;
  in_file.open(argv[1], std::ifstream::in);
  //bool init = true
  while (in_file.good()) {
    int n = 0;
    int C = 0;
    in_file >> n;
    in_file >> C;
    if (n == 0) break;
    auto items = static_cast<std::pair<int, int> *>(malloc(n*sizeof(std::pair<int, int>)));
    for (int i = 0; i < n; i++) {
      in_file >> items[i].first;
      in_file >> items[i].second;
    }

    GreedyAlg alg(n, C, items);
    alg.computeKnapSack(atoi(argv[3]));
    ofs.open(argv[2], std::ofstream::out | std::ofstream::app);
    alg.printOut(ofs);
    ofs.close();
    /*std::cout << "Items (Sorted)" << std::endl;
    for (int i = 0; i < n; i++) {
      std::cout << "\tfirst: " << items[i].first << std::endl;
      std::cout << "\tsecond: " << items[i].second << std::endl;
    }*/
    free(items);
  }
  in_file.close();
  return 0;
}
