#include "queue.h"

void main() {
	Queue q1, q2, q3;
	q1 = Queue(15, 20, 120);
	q2 = Queue(25, 30, 120);
	q3 = Queue(40, 20, 100);
	q1.run(); q2.run(); q3.run();

	int length = q1.capacity;
	ofstream xx1("q1.txt");                // nam1.txt 파일 생성
	for (int i = 0; i < length; i++) {       // NofPackets 배열의 값을 파일에 저장
		xx1 << q1.NofPackets[i] << endl;
	}

	length = q2.capacity;
	ofstream xx2("q2.txt");                // nam1.txt 파일 생성
	for (int i = 0; i < length; i++) {       // NofPackets 배열의 값을 파일에 저장
		xx2 << q2.NofPackets[i] << endl;
	}


	length = q3.capacity;
	ofstream xx3("q3.txt");                // nam1.txt 파일 생성
	for (int i = 0; i < length; i++) {       // NofPackets 배열의 값을 파일에 저장
		xx3 << q3.NofPackets[i] << endl;
	}

	xx1.close();
	xx2.close();
	xx3.close();
	cout << endl;
	cout << "q1 max: " << q1.maxValue() << endl;
	cout << "q1 average: " << q1.AverageP() << endl;
	cout << "q1 lost: " << q1.lost << endl << endl;

	cout << "q2 max: " << q2.maxValue() << endl;
	cout << "q2 average: " << q2.AverageP() << endl;
	cout << "q2 lost: " << q2.lost << endl << endl;

	cout << "q3 max: " << q3.maxValue() << endl;
	cout << "q3 average: " << q3.AverageP() << endl;
	cout << "q3 lost: " << q3.lost << endl << endl;
}