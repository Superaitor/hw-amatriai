#include "flexCharManager.h"

flexCharManager::flexCharManager(){
 free_mem = BUF_SIZE;
 active_requests = 0;
 used_mem_size = 2;

 

 used_memory = new Mem_Block*[used_mem_size];

 
 
}

flexCharManager::~flexCharManager(){
	delete[] used_memory;
}
             
char* flexCharManager::alloc_chars(int n){
	
	Mem_Block* block = new Mem_Block;
	int address = 0;
	bool flex = false;
	
	
	if(active_requests == used_mem_size)
	{
		Mem_Block** temporary = new Mem_Block*[used_mem_size*2];
		for(int i =0; i < used_mem_size; i++)
		{
			temporary[i] = used_memory[i];
			delete used_memory[i];
		}

		//If valgrind fails, make for loop
		delete[] used_memory;

	used_memory = new Mem_Block*[used_mem_size*2];
	used_memory = temporary;
	delete[] temporary;
	}

	for(int i =0; i < BUF_SIZE; i++)
	{
		if( buffer[i] == '\0')
		{
			int x = 0;
			while( x < n )
			{
				if( buffer[i+x] == '\0')
				{
					x++;
				}
				else
				{
					break;
				}
			}
			if(x == n)
			{
				address = i;
				flex = true;
				break;

			}
		}
	}
	if(flex)
	{
		block->physical_location = &buffer[address];
		block->size = n;
		free_mem-=n;

	}
	used_memory[active_requests] = block;
	active_requests++;
	if(flex)
	{
	return block->physical_location;
	}
	
		

       return NULL;
}

void flexCharManager::free_chars(char* p)
{
	int index=0;
	for(int i=0; i < BUF_SIZE; i++)
	{
		if( &buffer[i] == p )
		{
			break;
		}
		
		index++;
	
	}
	


	for(int i = 0; i < used_mem_size; i++)
	{
		if(used_memory[i] != '\0')
		{
			if(used_memory[i]->physical_location == p)
			{
				for(int j = index; j < used_memory[i]->size; j++)
				{
					buffer[j] = '\0';
				}
				delete[] used_memory[i];
			}
		}
	} 
}

     


