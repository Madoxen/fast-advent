#include <iostream> 
#include <fstream> 
#include <sstream>

int main() {
	//Read the data
	
	std::stringstream ss;
	std::fstream input_file("a.input");
	ss << input_file.rdbuf();	

	std::string buff = ss.str();
	int floor = 0; //Santa starts on floor 0
	for(char& c: buff)
	{
		if(c == '(') {
			floor++;
		}
		else if (c == ')')
		{
			floor--;
		}
	}
	std::cout << floor << std::endl;
	return 0;
}

