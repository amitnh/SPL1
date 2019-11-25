#include <iostream>
#include "../include/Session.h"
#include <nlohmann/json.hpp>
using namespace std;

int main(int argc, char** argv){
	if(argc!=2)
	{
		cout << "usage splflix input_file" << endl;
		return 0;
	}
	cout <<"hello amit"<<endl;
	Session s(argv[1]);
	s.start();
	return 0;
}
