#include <iostream>
#include <string>
#include <sstream>
#include <cstring> 
#include <fstream>
#include <stdlib.h>

using namespace std; 
void words(ifstream &ifile, int num, int i);

int main (int argc, char * argv[])
{
	int num;
	int i  =1;
	ifstream ifile;
	ifile.open(argv[1]);
	ifile >> num;
	//cout << argv[0] << endl;
	//cout << word << endl;
	words(ifile, num, i);
}

void words(ifstream &ifile, int num, int i)
{
	string word;
	int num2 = 0;
	string word2;
	//cout << i << endl;
	
	ifile >> word;
	word2 = word;
	num2 ++;
	word = " ";
	i++;
	if(i <= num)
	{
		words(ifile, num, i);
	}
	cout << word2 << endl;
	
	
	ifile.close();
	//words(ifile);
	//cout << word << endl;
	//ifile.close();

}