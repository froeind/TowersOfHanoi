
#pragma once

#include <chrono>
#include <string>

//using namespace std;

namespace mystd {

    std::string fctToLower(std::string);

	struct Timer {
		std::chrono::time_point<std::chrono::high_resolution_clock> start, ende;
		//std::chrono::duration<double> duration;
		std::chrono::duration<double> duration = std::chrono::seconds(0);
		std::string funktion;
		int praezision;
		Timer(std::string, int praezisionI = 5);
		~Timer();
	};

}

