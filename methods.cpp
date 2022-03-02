
#ifndef __METHODS_H_
#define __METHODS_H_

#include "project1.h"

/*
  Return integer representation of an add instruction
 */
 int addInstruction(string asmInstruction, unordered_map <string, int> op,
 unordered_map <string, int> reg, unordered_map <string, int> func){
   //string is in format add$reg1,$reg2,$reg3
  vector<string> splitLine; //holds registers in order as string
  vector<int> registerName; //holds registers in order as ints

  //remove the substring "add"
  asmInstruction=asmInstruction.substr(3);

  //separate registers from instruction
  string delim="$";
  int start;
  int end = 0;
  while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
  {
      end = asmInstruction.find(delim, start);
      splitLine.push_back(asmInstruction.substr(start, end - start));
  }
  //remove commas
  for (int i=0; i<splitLine.size();i++){
    if (splitLine.at(i).find(',') != std::string::npos){
      splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
    }
    //splitLine.at(i) holds registers
    try {
      // code to covnert value of register
      registerName.push_back(stoi(splitLine.at(i)));
    } catch( invalid_argument e ) {
      // code to retrieve value of register name is Hashmap "reg"
      registerName.push_back(reg.at(splitLine.at(i)));
    }
  }
  int addOpCode= op.at("add");
  int addFunctionCode= func.at("add");

  int binary = (addOpCode<<26) + (registerName.at(1)<<21)
  + (registerName.at(2)<<16) + (registerName.at(0)<<11) + (0<<6) + (addFunctionCode);

   return binary;
 }

/*
  Return integer representation of an addi instruction
 */
int addiInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format addi$reg1,$reg2,$reg3
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "addi"
 asmInstruction=asmInstruction.substr(4);

 //separate registers from instruction
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove $
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find('$') != std::string::npos){
     splitLine.at(i).erase(remove(splitLine.at(i).begin(), splitLine.at(i).end(), '$'), splitLine.at(i).end());
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int addiOpCode= op.at("addi");

 int binary = (addiOpCode<<26) + (registerName.at(1)<<21)
 + (registerName.at(0)<<16) + (registerName.at(2) & 0xffff);

  return binary;
}

/*
  Return integer representation of a sub instruction
 */
int subInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format sub$reg1,$reg2,$reg3
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "sub"
 asmInstruction=asmInstruction.substr(3);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find(',') != std::string::npos){
     splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int subOpCode= op.at("sub");
 int subFunctionCode= func.at("sub");

 int binary = (subOpCode<<26) + (registerName.at(1)<<21)
 + (registerName.at(2)<<16) + (registerName.at(0)<<11) + (0<<6) + (subFunctionCode);

  return binary;
}

/*
  Return integer representation of a mult instruction
 */
int multInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format mult$reg1,$reg2
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "mult"
 asmInstruction=asmInstruction.substr(4);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find(',') != std::string::npos){
     splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int multOpCode= op.at("mult");
 int multFunctionCode= func.at("mult");

 int binary = (multOpCode<<26) + (registerName.at(0)<<21) + (registerName.at(1)<<16) +
 (0<<6) + (multFunctionCode);

  return binary;
}

/*
  Return integer representation of a div instruction
 */
int divInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format div$reg1,$reg2
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "div"
 asmInstruction=asmInstruction.substr(3);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find(',') != std::string::npos){
     splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int divOpCode= op.at("div");
 int divFunctionCode= func.at("div");

 int binary = (divOpCode<<26) + (registerName.at(0)<<21) + (registerName.at(1)<<16) +
 (0<<6) + (divFunctionCode);

  return binary;
}

/*
  Return integer representation of a mflo instruction
 */
int mfloInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format mflo$reg1
  vector<string> splitLine; //holds registers in order as string
  vector<int> registerName; //holds registers in order as ints

 //remove the substring "mflo"
 asmInstruction=asmInstruction.substr(4);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find(',') != std::string::npos){
     splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int mfloOpCode= op.at("mflo");
 int mfloFunctionCode= func.at("mflo");

 int binary = (mfloOpCode<<26) + (0<<16) + (registerName.at(0)<<11) + (0<<6) + (mfloFunctionCode);

  return binary;
}

/*
  Return integer representation of a mfhi instruction
 */
int mfhiInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format mfhi$reg1
  vector<string> splitLine; //holds registers in order as string
  vector<int> registerName; //holds registers in order as ints

 //remove the substring "mfhi"
 asmInstruction=asmInstruction.substr(4);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find(',') != std::string::npos){
     splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int mfhiOpCode= op.at("mfhi");
 int mfhiFunctionCode= func.at("mfhi");

 int binary = (mfhiOpCode<<26) + (0<<16) + (registerName.at(0)<<11) + (0<<6) + (mfhiFunctionCode);

  return binary;
}

/*
  Return integer representation of a sll instruction
 */
int sllInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format sll$reg1,$reg2,$reg3
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "sll"
 asmInstruction=asmInstruction.substr(3);

 //separate registers from instruction
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove $
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find('$') != std::string::npos){
     splitLine.at(i).erase(remove(splitLine.at(i).begin(), splitLine.at(i).end(), '$'), splitLine.at(i).end());
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int sllOpCode= op.at("sll");
 int sllFunctionCode= 0;
 int immediate= registerName.at(2);

 int binary = (sllOpCode<<26) + (0<<21) + (registerName.at(1)<<16)
 + (registerName.at(0)<<11) + (immediate<<6) + (sllFunctionCode);

  return binary;
}

/*
  Return integer representation of a srl instruction
 */
int srlInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format srl$reg1,$reg2,$reg3
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "srl"
 asmInstruction=asmInstruction.substr(3);

 //separate registers from instruction
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove $
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find('$') != std::string::npos){
     splitLine.at(i).erase(remove(splitLine.at(i).begin(), splitLine.at(i).end(), '$'), splitLine.at(i).end());
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int srlOpCode= op.at("srl");
 int srlFunctionCode= func.at("srl");
 int immediate= registerName.at(2);

 int binary = (srlOpCode<<26) + (0<<21) + (registerName.at(1)<<16)
 + (registerName.at(0)<<11) + (immediate<<6) + (srlFunctionCode);

  return binary;
}

/*
  Return integer representation of a lw instruction
 */
int lwInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg){
  //string is in format lw$reg1,offset($reg2)
 vector<string> splitLine; //holds registers in order as string

 //remove the substring "lw"
 asmInstruction=asmInstruction.substr(2);

 //separate based on commas
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }

string rt = splitLine.at(0);
rt = rt.substr(rt.find_first_not_of("$"));
int rtUpdate = reg.at(rt);

string offset = splitLine.at(1);
offset = offset.substr(0, offset.find("("));
int offsetUpdate = stoi(offset);

string base = splitLine.at(1);
base = base.substr(base.find_first_of("$"));
base = base.substr(base.find_first_not_of("$"));
base = base.substr(0, base.find(")"));
int baseUpdate = reg.at(base);

int lwOpCode= op.at("lw");

int binary = (lwOpCode<<26) + (baseUpdate<<21) + (rtUpdate<<16) + (offsetUpdate & 0xffff);

  return binary;
}

/*
  Return integer representation of a sw instruction
 */
int swInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg){
  //string is in format sw$reg1,offset($reg2)
 vector<string> splitLine; //holds registers in order as string

 //remove the substring "sw"
 asmInstruction=asmInstruction.substr(2);

 //separate based on commas
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }

string rt = splitLine.at(0);
rt = rt.substr(rt.find_first_not_of("$"));
int rtUpdate = reg.at(rt);

string offset = splitLine.at(1);
offset = offset.substr(0, offset.find("("));
int offsetUpdate = stoi(offset);

string base = splitLine.at(1);
base = base.substr(base.find_first_of("$"));
base = base.substr(base.find_first_not_of("$"));
base = base.substr(0, base.find(")"));
int baseUpdate = reg.at(base);

int swOpCode= op.at("sw");

int binary = (swOpCode<<26) + (baseUpdate<<21) + (rtUpdate<<16) + (offsetUpdate & 0xffff);

  return binary;
}

/*
  Return integer representation of a slt instruction
 */
int sltInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format slt$reg1,$reg2,$reg3
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "slt"
 asmInstruction=asmInstruction.substr(3);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   if (splitLine.at(i).find(',') != std::string::npos){
     splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
   }
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int sltOpCode= op.at("slt");
 int sltFunctionCode= func.at("slt");

 int binary = (sltOpCode<<26) + (registerName.at(1)<<21)
 + (registerName.at(2)<<16) + (registerName.at(0)<<11) + (0<<6) + (sltFunctionCode);

  return binary;
}

/*
  Return integer representation of a beq instruction
 */
int beqInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> lab, int lineNum){
  //string is in format beq$reg1,$reg2,offset
 vector<string> splitLine; //holds registers in order as string

 //remove the substring "beq"
 asmInstruction=asmInstruction.substr(3);

 //separate based on commas
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }

string rt = splitLine.at(0);
rt = rt.substr(rt.find_first_not_of("$"));
int rtUpdate = reg.at(rt);

string rs = splitLine.at(1);
rs = rs.substr(rs.find_first_not_of("$"));
int rsUpdate = reg.at(rs);

string offset = splitLine.at(2);
int offsetUpdate = lab.at(offset)-lineNum & 0xffff;

int beqOpCode= op.at("beq");

int binary = (beqOpCode<<26) + (rtUpdate<<21) + (rsUpdate<<16) + (offsetUpdate);

  return binary;

}

/*
  Return integer representation of a bne instruction
 */
int bneInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg,unordered_map <string, int> lab, int lineNum){
  //string is in format bne$reg1,$reg2,offset
 vector<string> splitLine; //holds registers in order as string

 //remove the substring "bne"
 asmInstruction=asmInstruction.substr(3);

 //separate based on commas
 string delim=",";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }

string rt = splitLine.at(0);
rt = rt.substr(rt.find_first_not_of("$"));
int rtUpdate = reg.at(rt);

string rs = splitLine.at(1);
rs = rs.substr(rs.find_first_not_of("$"));
int rsUpdate = reg.at(rs);

string offset = splitLine.at(2);
int offsetUpdate = lab.at(offset)-lineNum & 0xffff;

int bneOpCode= op.at("bne");

int binary = (bneOpCode<<26) + (rtUpdate<<21) + (rsUpdate<<16) + (offsetUpdate);

  return binary;
}

/*
  Return integer representation of a j instruction
 */
int jInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> lab, int lineNum){
  //string is in format jLabel

 //remove the substring "j"
 asmInstruction=asmInstruction.substr(1);

 //retrieve lineNumber of label
 int labelNumber= lab.at(asmInstruction);

 int jOpCode= op.at("j");

 int binary = (jOpCode<<26) + labelNumber;

  return binary;
}

/*
  Return integer representation of a jal instruction
 */
int jalInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> lab, int lineNum){
  //string is in format jalLabel

 //remove the substring "jal"
 asmInstruction=asmInstruction.substr(3);

 //retrieve lineNumber of label
 int labelNumber= lab.at(asmInstruction);

 int jOpCode= op.at("jal");

 int binary = (jOpCode<<26) + labelNumber;

  return binary;
}

/*
  Return integer representation of a jr instruction
 */
int jrInstruction(string asmInstruction, unordered_map <string, int> op,
unordered_map <string, int> reg, unordered_map <string, int> func){
  //string is in format jr$reg1
 vector<string> splitLine; //holds registers in order as string
 vector<int> registerName; //holds registers in order as ints

 //remove the substring "jr"
 asmInstruction=asmInstruction.substr(2);

 //separate registers from instruction
 string delim="$";
 int start;
 int end = 0;
 while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
 {
     end = asmInstruction.find(delim, start);
     splitLine.push_back(asmInstruction.substr(start, end - start));
 }
 //remove commas
 for (int i=0; i<splitLine.size();i++){
   //splitLine.at(i) holds registers
   try {
     // code to convert value of register
     registerName.push_back(stoi(splitLine.at(i)));
   } catch( invalid_argument e ) {
     // code to retrieve value of register name is Hashmap "reg"
     registerName.push_back(reg.at(splitLine.at(i)));
   }
 }
 int jrOpCode= op.at("jr");
 int jrFunctionCode= func.at("jr");

 int binary = (jrOpCode<<26) + (registerName.at(0)<<21) + (0<<6) +
 (jrFunctionCode);

  return binary;
}

/*
  Return integer representation of a jalr instruction
 */
int jalrInstruction(string asmInstruction, unordered_map <string, int> op,
  unordered_map <string, int> reg, unordered_map <string, int> func,
  unordered_map <string, int> lab){
    //string is in format jalr$reg1,$reg2
   vector<string> splitLine; //holds registers in order as string
   vector<int> registerName; //holds registers in order as ints

   //remove the substring "jalr"
   asmInstruction=asmInstruction.substr(4);

   //separate registers from instruction
   string delim="$";
   int start;
   int end = 0;
   while ((start = asmInstruction.find_first_not_of(delim, end)) != std::string::npos)
   {
       end = asmInstruction.find(delim, start);
       splitLine.push_back(asmInstruction.substr(start, end - start));
   }
   //remove commas
   for (int i=0; i<splitLine.size();i++){
     if (splitLine.at(i).find(',') != std::string::npos){
       splitLine.at(i)=splitLine.at(i).substr(0,splitLine.at(i).find(','));
     }
     //splitLine.at(i) holds registers
     try {
       // code to convert value of register
       registerName.push_back(stoi(splitLine.at(i)));
     } catch( invalid_argument e ) {
       // code to retrieve value of register name is Hashmap "reg"
       registerName.push_back(reg.at(splitLine.at(i)));
     }
   }
   int jalrOpCode= op.at("jalr");
   int jalrFunctionCode= func.at("jalr");

   int binary = (jalrOpCode<<26) + (registerName.at(1)<<21) + (0<<16) +
   (registerName.at(0)<<11) + (0<<6) + (jalrFunctionCode);

    return binary;
}

/*
  Return integer representation of a syscall instruction
 */
int syscallInstruction(string asmInstruction, unordered_map <string, int> op, unordered_map <string, int> func){

  int sysOpCode = op.at("syscall");
  int sysFunctionCode = func.at("syscall");

  int binary = (sysOpCode<<26) + (0<<6) + (sysFunctionCode);

  return binary;

}
#endif
