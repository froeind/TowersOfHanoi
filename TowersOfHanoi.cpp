
#include <iostream>
#include <array>
#include <vector>

#include "tools.h"

using namespace std;

using tower = vector<unsigned int>;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TowersOfHanoi
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void tohShow(array<tower,3>& towers) {
	for (unsigned int i = 0; i < towers[0].size(); i++) {
		cout << "Slices:  " << (towers[0].at(i) == 0 ? " " : to_string(towers[0].at(i))) << "       " << (towers[1].at(i) == 0 ? " " : to_string(towers[1].at(i))) << "       " << (towers[2].at(i) == 0 ? " " : to_string(towers[2].at(i))) << "\n";
	}
	cout << "\n";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void tohMove(array<tower,3>& towers, array<unsigned int,3>& tops, unsigned int i, unsigned int j) {
    tops[j]--;
    towers[j].at(tops[j]) = towers[i].at(tops[i]);
    towers[i].at(tops[i]) = 0;
    tops[i]++;
    tohShow(towers);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void tohType3(array<tower,3>& towers, array<unsigned int,3>& tops, unsigned int i, unsigned int j, unsigned int k) {
    tohMove(towers, tops, i, j);
    tohMove(towers, tops, i, k);
    tohMove(towers, tops, j, k);
    tohMove(towers, tops, i, j);
    tohMove(towers, tops, k, i);
    tohMove(towers, tops, k, j);
    tohMove(towers, tops, i, j);
	cout << "- - - - - - - - - - - - - - - - - " << __func__ << "\n\n";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void tohTypeX(unsigned int level, array<tower,3>& towers, array<unsigned int,3>& tops, unsigned int i, unsigned int j, unsigned int k) {
	cout << "- - - - - - - - - - - - Starting  " << __func__ << " level " << level << "\n\n";
    level = (unsigned int) (level - 1);
    if (level == 3) {
        tohType3(towers, tops, i, j, k);
    } else {
        tohTypeX(level, towers, tops, i, k, j);
        tohMove(towers, tops, i, j);
        tohTypeX(level, towers, tops, k, j, i);
    }
	cout << "- - - - - - - - - - - - Ending    " << __func__ << " level " << (level + 1) << "\n\n";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void towersofhanoi(unsigned int slices) {

	mystd::Timer timer(__func__);
	
	array<tower,3> towers{tower(slices, 0), tower(slices, 0), tower(slices, 0)};

	for (unsigned int i = 0; i < slices; i++) {
		towers[0].at(i) = i + 1;
	}
    array<unsigned int,3> tops{0, slices, slices};

	//cout << "Size:    " << towers[0].size() << " " << towers[1].size() << " " << towers[2].size() << "\n";
    tohShow(towers);
    tohType3(towers, tops, 0, 1, 2);
    unsigned int level = 4;
    unsigned int from = 1;
    unsigned int to = 2;
    while (tops[0] < slices) {
        tohMove(towers, tops, 0, to);
        tohTypeX(level, towers, tops, from, to, 0);
        from = 3 - from;
        to = 3 - to;
        level++;
    }
    
    /*
	delete ...;
    */

	//cout << "- - - - - - - - - - - - - - - - - " << __func__ << "\n\n";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main() {

	mystd::Timer timer(__func__);
	
	// VS meckert über maxlevel, dass es als Arraygrenze konstant sein muss
	// aber dieses Konstrukt stellt VS nicht zufrieden
	//const int maxlevel = 4;
	//towersofhanoi(maxlevel);
	// also bleibe ich dabei, die anderen IDEs scheinen keine Probleme damit zu haben
	// und hatte dank Gemini das Problem "gelöst", nun ja, C++ beharrt halt bei den alten C-Arrays auf seine alten Einschränkungen
    // const unsigned t = 4u;
	// towersofhanoi(t);
    // aber C-Arrays sind so oder so zu einschränkend für meine Logik ...
    // ... ich brauche jetzt ein array<vector<int>> ...
    for (unsigned int s = 3; s <= 15; s++) {
        // für 16 Scheiben braucht es schon mehr als 4 Minuten, bei 20 mehr als 85 Minuten
        cout << "Towers Of Hanoi        with " << s << " Slices:\n\n";
        towersofhanoi(s);
    }

    return 0;
}
