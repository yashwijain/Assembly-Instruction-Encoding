#ifndef __PROJECT1_CPP__
#define __PROJECT1_CPP__

#include "methods.h"
#include "project1.h"
#include <algorithm>

int main(int argc, char *argv[])
{

  project1 asmInfo = project1();
//  unordered_map <string, int> asmInfoExample= start.getOpCodes();

  // If there are more or less arguments than the names of the input and output files
  if (argc != 3)
  {
    // Give a useful usage message
    cout << argc << "\n";
    cerr << "Usage: " << argv[0] << " [input file]" << " [output file]" <<"\n";
    exit(1);
  }

  // Open the input file
  ifstream fin(argv[1]);

  if (!fin.is_open())
  {
    // Error printing if file can't be opened
    cerr << "Error: could not open file: " << argv[1] << "\n";
    exit(1);
  }

  // Error printing in case the input file has a bad format
  if (fin.fail() && !fin.eof())
  {
      cerr << "Error: bad file format: " << argv[1] << "\n";
      exit(1);
  }

  // Open the output file in binary mode
  ofstream fout(argv[2],ios::binary);

  if (!fout.is_open())
  {
      // If file can't be opened, need to let the user know
      cerr << "Error: could not open file: " << argv[1] << "\n";
      exit(1);
  }

  vector<int> binaryLines; //Stores lines as int to be converted to binary
  string line;

  int lineNum=0;
  // parse file to record labels into label hashmap with line number
   while(getline(fin, line))
   {

     if (line.find("#") != std::string::npos){
       int comment_pos = line.find("#"); //position of next occuring # in file
       line = line.substr(0,comment_pos);
     }
     if(line.find(' ') != std::string::npos) { //remove all whitespace
       line.erase(remove(line.begin(), line.end(), ' '), line.end());
     }
     if (line == ""){
         continue; // Skip if the line is empty
     }
     if(line.find(":") != std::string::npos){
       //line in format label:
       string labelName;
       labelName=line.substr(0,line.find(":")); //label name
       unordered_map <string, int> lab= asmInfo.getLabels();
       lab[labelName]=lineNum; //label hashmap holds labelName and line number of first instruction
       asmInfo.setLabels(lab); //set label hashmap to include new values
     }
     else if (line.find(".") == std::string::npos){
       lineNum++;
     }

   }

   //reset getline cursor
   fin.clear();
   fin.seekg(0);

   lineNum=0;
  // Reading the input file and parsing in this while loop
  while(getline(fin, line))
  {
      if (line.find("#") != std::string::npos){
        int comment_pos = line.find("#"); //position of next occuring # in file
        line = line.substr(0,comment_pos);
      }
      if(line.find(' ') != std::string::npos) { //remove all whitespace
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
      }
      if (line == ""){
          continue; // Skip if the line is empty
      }

      if (line.find("add")!=string::npos && line.find("addi")==string::npos){ //line.substr(0,2) == "add" testing?
        //call method and store int in rawLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(addInstruction(line, op, reg, func));
      }
      else if (line.find("addi")!=string::npos){
        //call method and store int in rawLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(addiInstruction(line, op, reg, func));
      }
      else if (line.find("sub")!=string::npos){
        //call method and store int in rawLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(subInstruction(line, op, reg, func));
      }
      //create cases for mult, div, mflo, mfhi - ask how to start the class
      //for these and does each class need to contain a header?
      else if (line.find("mult")!=string::npos) {
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op = asmInfo.getOpCodes();
        unordered_map <string, int> reg = asmInfo.getRegisterCodes();
        unordered_map <string, int> func = asmInfo.getFunctionCodes();
        binaryLines.push_back(multInstruction(line, op, reg, func));
      }
      else if (line.find("div")!=string::npos) {
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op = asmInfo.getOpCodes();
        unordered_map <string, int> reg = asmInfo.getRegisterCodes();
        unordered_map <string, int> func = asmInfo.getFunctionCodes();
        binaryLines.push_back(divInstruction(line, op, reg, func));
      }
      else if (line.find("mflo")!=string::npos) {
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op = asmInfo.getOpCodes();
        unordered_map <string, int> reg = asmInfo.getRegisterCodes();
        unordered_map <string, int> func = asmInfo.getFunctionCodes();
        binaryLines.push_back(mfloInstruction(line, op, reg, func));
      }
      else if (line.find("mfhi")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op = asmInfo.getOpCodes();
        unordered_map <string, int> reg = asmInfo.getRegisterCodes();
        unordered_map <string, int> func = asmInfo.getFunctionCodes();
        binaryLines.push_back(mfhiInstruction(line, op, reg, func));
      }
      else if(line.find("sll")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(sllInstruction(line, op, reg, func));
      }
      else if(line.find("srl")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(srlInstruction(line, op, reg, func));
      }
      else if(line.find("lw")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        binaryLines.push_back(lwInstruction(line, op, reg));
      }
      else if(line.find("sw")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        binaryLines.push_back(swInstruction(line, op, reg));
      }
      else if(line.find("slt")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(sltInstruction(line, op, reg, func));
      }
      else if(line.find("beq")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> labs= asmInfo.getLabels();
        binaryLines.push_back(beqInstruction(line, op, reg, labs, lineNum));
      }
      else if(line.find("bne")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> labs= asmInfo.getLabels();
        binaryLines.push_back(bneInstruction(line, op, reg, labs, lineNum));
      }
      else if(line.find("j")!=string::npos
      && line.find("jal")==string::npos && line.find("jalr")==string::npos
      && line.find("jr")==string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> lab= asmInfo.getLabels();
        binaryLines.push_back(jInstruction(line, op, lab, lineNum));
      }
      else if(line.find("jal")!=string::npos && line.find("jalr")==string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> lab= asmInfo.getLabels();
        binaryLines.push_back(jalInstruction(line, op, lab, lineNum));
      }
      else if(line.find("jr")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(jrInstruction(line, op, reg, func));
      }
      else if(line.find("jalr")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> reg= asmInfo.getRegisterCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        unordered_map <string, int> labs= asmInfo.getLabels();
        binaryLines.push_back(jalrInstruction(line, op, reg, func, labs));
      }
      else if(line.find("syscall")!=string::npos){
        //call method and store int in binaryLines vector
        lineNum++;
        unordered_map <string, int> op= asmInfo.getOpCodes();
        unordered_map <string, int> func= asmInfo.getFunctionCodes();
        binaryLines.push_back(syscallInstruction(line, op, func));
      }

    }

    //Lines for outputting binary to output files
    for (int i=0; i<binaryLines.size(); i++){
      fout.write((char *) &binaryLines.at(i), sizeof(int));
    //  cout<<hex<<binaryLines.at(i)<<endl; //test

    }


  // Closing the input and output files
  fin.close();
  fout.close();

  return 0;
}

#endif
