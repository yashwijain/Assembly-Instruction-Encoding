#ifndef __PROJECT1_H_
#define __PROJECT1_H_

#include <cstring>
#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include "methods.h"
using namespace std;

class project1{

private:
  //Hashmap for labels to line numbers
  unordered_map <string, int> labels;

  //Hashmap for function name to opcodes numbers
  unordered_map <string, int> opCodes;

  //Hashmap for function name to function code
  unordered_map <string, int> functionCodes;

  //Hashmap for register name to numbers !!! NOTE: registers can be $t0 or $8
  unordered_map <string, int> registerCodes;

public:
  project1(){

    opCodes["add"] = 0;
    opCodes["addi"] = 8;
    opCodes["sub"] = 0;
    opCodes["mult"] = 0;
    opCodes["div"] = 0;
    opCodes["mflo"] = 0;
    opCodes["mfhi"] = 0;
    opCodes["sll"] = 0;
    opCodes["srl"] = 0;
    opCodes["lw"] = 35;
    opCodes["sw"] = 43;
    opCodes["slt"] = 0;
    opCodes["beq"] = 4;
    opCodes["bne"] = 5;
    opCodes["j"] = 2;
    opCodes["jal"] = 3;
    opCodes["jr"] = 0;
    opCodes["jalr"] = 0;
    opCodes["syscall"] = 0;

    functionCodes["add"]= 32; //100000
    functionCodes["sub"]= 34; //100010
    functionCodes["mult"]= 24; //011000
    functionCodes["div"]= 26; //011010
    functionCodes["mflo"]= 18; //010010
    functionCodes["mfhi"]= 16; //010000
    functionCodes["srl"]= 2; //000010
    functionCodes["slt"]= 42; //101010
    functionCodes["jr"]= 8; //001000
    functionCodes["jalr"]= 9; //001001
    functionCodes["syscall"]= 12; //001100

    registerCodes["zero"] = 0;
    registerCodes["at"] = 1;
    registerCodes["v0"] = 2;
    registerCodes["v1"] = 3;
    registerCodes["a0"] = 4;
    registerCodes["a1"] = 5;
    registerCodes["a2"] = 6;
    registerCodes["a3"] = 7;
    registerCodes["t0"] = 8;
    registerCodes["t1"] = 9;
    registerCodes["t2"] = 10;
    registerCodes["t3"] = 11;
    registerCodes["t4"] = 12;
    registerCodes["t5"] = 13;
    registerCodes["t6"] = 14;
    registerCodes["t7"] = 15;
    registerCodes["s0"] = 16;
    registerCodes["s1"] = 17;
    registerCodes["s2"] = 18;
    registerCodes["s3"] = 19;
    registerCodes["s4"] = 20;
    registerCodes["s5"] = 21;
    registerCodes["s6"] = 22;
    registerCodes["s7"] = 23;
    registerCodes["t8"] = 24;
    registerCodes["t9"] = 25;
    registerCodes["k0"] = 26;
    registerCodes["k1"] = 27;
    registerCodes["gp"] = 28;
    registerCodes["sp"] = 29;
    registerCodes["fp"] = 30;
    registerCodes["ra"] = 31;
  }


  unordered_map <string, int> getLabels() {return this->labels;}
  void setLabels(unordered_map <string, int> setting){this->labels=setting;}
  unordered_map <string, int> getOpCodes() {return this->opCodes;}
  unordered_map <string, int> getRegisterCodes() {return this->registerCodes;}
  unordered_map <string, int> getFunctionCodes() {return this->functionCodes;}

};

#endif
