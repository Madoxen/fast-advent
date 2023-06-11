#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "timing.h"

int main() {
	Timer<std::chrono::microseconds> t;
	t.tick();

	//Data load
	std::fstream input_file("a.input");	

	unsigned int total_area = 0;
	std::string line;
	while(std::getline(input_file, line)) 
	{
		size_t first = line.find('x');
		size_t second = line.find('x', first + 1);

		unsigned int x = std::stoi(line.substr(0, first));
		unsigned int y = std::stoi(line.substr(first + 1, second - (first+1)));
		unsigned int z = std::stoi(line.substr(second+1, line.length() - (second+1)));
		
		total_area += (2*x*y) + (2*y*z) + (2*x*z);
		total_area += std::min({x*y, y*z, x*z});

	}
	std::cout << total_area << std::endl;
	t.tock();
	std::cout << t.duration().count() << "us" << std::endl;
}
