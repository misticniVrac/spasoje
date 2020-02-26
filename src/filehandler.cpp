
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>

using namespace std;
namespace spasoje{


string
read_file(string fpath)
{
	ifstream f(fpath);
	string str;

	if(!(f.good()))
	{
		cout << "could not open file " << fpath << "\n";
		return "";
	}

	f.seekg(0,ios::end);   
	str.reserve(f.tellg());
	f.seekg(0,ios::beg);


	str.assign((istreambuf_iterator<char>(f)),istreambuf_iterator<char>());

	return str;
}




}
