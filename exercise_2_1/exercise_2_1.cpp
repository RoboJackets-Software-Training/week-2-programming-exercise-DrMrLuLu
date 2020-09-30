#include <iostream>
#include <vector>
#include "convolution.h"


std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

void printVector(std::vector<double> vec) {
  for(int i = 1; i < vec.size(); i++) {
    std::cout << ", " << vec[i];
  }
  std::cout << "}" << std::endl;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);


  std::cout << "x: {" << x[0];
  printVector(x);

  std::cout << "w: {" << w[0];
  printVector(w);

  y = applyConvolution(x,w,pack_with_zeros);

  std::cout << "{" << y[0];
  printVector(y);

  return 0;
}