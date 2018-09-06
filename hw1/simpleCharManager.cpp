#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager(){
	for(int i = 0; i < BUF_SIZE; i++)
	{
		buffer[i] = '\0';
	}
free_place = buffer;
} 

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n)
{
	char* ch = '\0';
	int x = 0;
	//char array[n];
	if(n == 0){
		return NULL;
	}
	if(n > 10000 || n <= 0)
	{
		return NULL;
	}
	
	while(buffer[x] != '\0')
	{
		x++;
	}
	if (x+n > BUF_SIZE)
	{
		return NULL;
	}
	
	//free_place = (buffer + x);
	ch = (buffer+x);
	free_place = (buffer+n);
	
	//for(int i = x; i < n+x; i++)
	//{
	//	array[i-x] = buffer[i];
	//}
	return ch;

}

void simpleCharManager::free_chars(char* p){
	int x = 0;
	while(&buffer[x] != p)
	{
		x++;
	}

	if(&buffer[x] == p)
	{
		for(int i=x; i < BUF_SIZE-x; i++)
		{
			buffer[i] = '\0';
		}
	}

}         


