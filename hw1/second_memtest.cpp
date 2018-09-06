  #include <iostream>
  #include <stdlib.h>
  #include "simpleCharManager.h"
  using namespace std;

  int main(int argc, char *argv[])
  {
   
      flexCharManager simplest_mem_manager;
      string sentence;
      sentence = "Hello World!\n";

      /*write driver code as described in the assignment to replace this */
      char* c1 = simplest_mem_manager.alloc_chars(6);
      for(int i = 0; i < 6; i++)
      {
        c1[i] = sentence[i];
      }
      
      char* c2 = simplest_mem_manager.alloc_chars(7);
      for(int i = 6; i < 13; i++)
      {
        c2[i] = sentence[i];
      }
      for(int i = 0;  i < 13; i++)
      {
        if( i < 6)
        {
        cout << c1[i];
        } 
        else
        {
          cout << c2[i];
        }

      }
      
      string sentence2 = "moon! bye\n";
      simplest_mem_manager.free_chars(c2);
      char* c3 = simplest_mem_manager.alloc_chars(10);
      for( int i = 6 ; i < 16; i++ )
      {
        c3[i] = sentence2[i];
      }
      
      return 0;
        }



