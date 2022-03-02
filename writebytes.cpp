#include <iostream>
#include<fstream>
using namespace std;
  
//main program
int main() {
  int i = 28786720;

  //Open file called test1.txt
  ofstream file;
  file.open("test1.txt"); //Open file in default mode (ascii)
  file << i << endl; //Write to file as ascii
  file.close();

  file.open("test2.txt"); //Open file in default mode (ascii)
  file << hex << i << endl; //Write to file as std::hex (ascii)
  file.close();

  file.open("test3.txt",ios::binary); //Open file in binary mode
  file.write((char *) &i, sizeof(int)); //Write to file as true binary
  file.close();
  //Open file called test1.txt
  return 0;
}
