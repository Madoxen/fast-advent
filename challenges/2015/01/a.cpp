#include <iostream> 
#include <fstream> 
#include <sstream>
#include "timing.h"

int main() {
	Timer<std::chrono::microseconds> t;

	t.tick();
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
	t.tock();
	std::cout << t.duration().count() << "us" << std::endl;
	return 0;
}


