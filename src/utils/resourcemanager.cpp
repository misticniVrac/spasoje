#include "resourcemanager.h"


#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>


using namespace std;

namespace spasoje
{
namespace resourceManager
{

string readFile(string fpath)
{
	ifstream f(fpath);
	string res;

	if(!(f.good()))
	{
		cout << "could not open file " << fpath << "\n";
		return "";
	}

	f.seekg(0,ios::end);
	res.reserve(f.tellg());
	f.seekg(0,ios::beg);

	res.assign((istreambuf_iterator<char>(f)),istreambuf_iterator<char>());

	return res;
}

}
}

