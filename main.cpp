#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int args, char **argv)
{
	ofstream outFile(argv[3], ifstream::trunc);
	ifstream inFile1,inFile2;

	inFile1.open(argv[1]);
	inFile2.open(argv[2]);

	string data_file1,data_file2;

	inFile1 >> data_file1;
	inFile2 >> data_file2;
	
	while((!inFile1.eof()) || (!inFile2.eof()))
	{	
		if(atoi(data_file1.c_str()) <= atoi(data_file2.c_str()))
		{
			outFile << data_file1 << endl;
			inFile1 >> data_file1;
		}
		if(atoi(data_file1.c_str()) >= atoi(data_file2.c_str()))
		{
			outFile << data_file2 << endl;
			inFile2 >> data_file2;
		}
	}		
	if(!inFile1.eof())
	{
		while(inFile1 >> data_file1)
			outFile << data_file1 << endl;
	}
	if(!inFile2.eof())
	{
		while(inFile2 >> data_file2)
			outFile << data_file2 << endl;
	}
	
	if(data_file1 == "\n")
		outFile << data_file1;
	else
		outFile << data_file2;
	
	inFile1.close();
	inFile2.close();
	outFile.close();

	return 0;
}