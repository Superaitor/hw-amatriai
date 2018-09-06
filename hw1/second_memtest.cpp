#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  flexCharManager simplest_mem_manager;
  string sentence;
  sentence = "Hello World!";

  /*write driver code as described in the assignment to replace this */
  char* c1 = simplest_mem_manager.alloc_chars(sentence.size());
  int size_sent = sentence.size();
  for(int i = 0; i < size_sent; i++)
  {
  	c1[i] = sentence[i];
  }
  
  //char* c2 = simplest_mem_manager.alloc_chars(3);
  for(int i =0; i < size_sent; i++)
  {
  	cout << c1[i]; 
  }
  cout << "" << endl;

  simplest_mem_manager.free_chars(c1);
  
  return 0;
}

