
#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

#include "tools.h"

using namespace std;

string mystd::fctToLower(string transe) {
    transform(transe.begin(), transe.end(), transe.begin(), [] (unsigned char c) { return tolower(c); });
    return transe;
}

mystd::Timer::Timer(string funktionI, int praezisionI) {
	start = chrono::high_resolution_clock::now();
	this->funktion = funktionI;
	this->praezision = praezisionI;
}

mystd::Timer::~Timer() {
	ende = chrono::high_resolution_clock::now();
	// ... mit der Differenzbildung
	duration = ende - start;
	// oder alleine nur mit dieser Zeile
	//chrono::duration<double> duration = ende - start;
	double ms = duration.count() * 1000;
	cout << "'" << this->funktion << "'" << " ausgeführt in " << fixed << setprecision(praezision) << ms << "ms\n\n";
}
