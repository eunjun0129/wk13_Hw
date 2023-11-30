#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

class Queue {
public:

	//constructor
	Queue() { NI = 30, NO = 30; }
	Queue(int p, int q, int r) {
		NI = p; NO = q; capacity = r;
	}

	//member data
	int NI, NO, capacity;
	int lost = 0;
	int ni, no, itime;
	int NofPackets[120];
	vector <int> q_vec;

	//member function
	void run();
	float AverageP();
	float maxValue();
};