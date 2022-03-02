#ifndef __METHODS_H_
#define __METHODS_H_

#include <cstring>
#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

//methods
  int addInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int addiInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int subInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int multInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int divInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int mfloInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int mfhiInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int sllInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int srlInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int lwInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg);

  int swInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg);

  int sltInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int beqInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> lab,
  int lineNum);

  int bneInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> lab,
  int lineNum);

  int jInstruction(string asmInstruction, unordered_map <string, int> op,
    unordered_map <string, int> lab, int lineNum);

  int jalInstruction(string asmInstruction, unordered_map <string, int> op,
    unordered_map <string, int> lab, int lineNum);

  int jrInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func);

  int jalrInstruction(string asmInstruction, unordered_map <string, int> op,
    unordered_map <string, int> reg,
    unordered_map <string, int> func, unordered_map <string, int> lab);

  int syscallInstruction(string asmInstruction, unordered_map <string, int> op,
    unordered_map <string, int> func);



#endif
