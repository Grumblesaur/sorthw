#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
	
	string arraySizeException = "Invalid array size! \n";
	string sortAlgorithmException = "Invalid algorithm! \n";
	
	//throw exception if there's no size given to create the array
	if (argv[2] == ""){
		throw arraySizeException;
	}

	//throw exception if array size is 0
	if (argv[2] == "0"){
		throw arraySizeException;
	}
	
	//throw exception if array size is passed as negative
	if (argv[2][0] == '-'){
		throw arraySizeException;
	}
	
	//throw exception if incorrect algorithm argument is given
	if (argv[1] != "bucket" || "bubble" || "heap"){
		throw sortAlgorithmException;
	}

	int arraySize = atoi(argv[2]);






	return 0;
}
