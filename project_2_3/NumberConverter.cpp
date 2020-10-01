#include <string>
#include <cmath>
#include "NumberConverter.h"

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char numberToHexChar(int input) {
  if(input < 10) {
    // it is a digit
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}

int binaryToDecmal(std::string binary) {
    int total = 0;
    for(int i = 0; i < binary.size(); i++) {
        if(binary.at(i) == '1') {
            total += std::pow(2, i);
        }
    }
    return total;
}

int hexToDecmal(std::string hex) {
    int total = 0;
    for(int i = 0; i < hex.size(); i++) {
        total += hexCharToNumber(hex.at(i));
    }
    return total;
}