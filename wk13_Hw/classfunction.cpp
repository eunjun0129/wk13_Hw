#include <iostream>
#include <Windows.h>
#include <vector>
#include "queue.h"
using namespace std;

void Queue::run() {

    for (itime = 0; itime < 120; itime++) {
        Sleep(0);                           // 1�� ���� ���
        ni = rand() % NI;                    // 0���� NI-1 ������ ������ ���� �����Ͽ� ni�� ����
        no = rand() % NO;                    // 0���� NO-1 ������ ������ ���� �����Ͽ� no�� ����

        if (capacity < q_vec.size() + ni) {  // ť�� �뷮�� �ʰ��ϴ� ���
            lost += q_vec.size() + ni - capacity;   // ��Ŷ �ս� ���� ����
            ni = capacity - q_vec.size();            // �����Ǵ� ��Ŷ ���� �����Ͽ� �뷮 �ʰ� ����
        }
        for (int i = 0; i < ni; i++) {       // ni��ŭ ������ ���� queue1 ���Ϳ� �߰�
            q_vec.push_back(rand() % NI);
        }

        for (int i = 0; i < no; i++) {       // no��ŭ q_vec���� ��Ŷ�� �����ϰ� ���
            if (q_vec.size() != 0) {
                cout << q_vec[0] << "\n";
                q_vec.erase(q_vec.begin());
            }
        }

        NofPackets[itime] = (int)q_vec.size();   // ���� �ð��� ���� q_vec�� ũ�⸦ �迭�� ����
    }

}

float Queue::AverageP() {
    float sum = 0;

    for (int i = 0; i < capacity; i++) {
        sum += *(NofPackets + i);  // �迭 a, b, c���� �ش� �ð��� ���� ��Ŷ ������ ����
    }

    return sum / capacity;                     // �� ��Ŷ ������ �ð��� 3��� ������ ��հ��� ����
}
float Queue::maxValue() {
    int max = 0;
    for (int i = 0; i < capacity; i++) {
        if (NofPackets[i] > max) {                      // �迭 a���� �ִ��� ã��
            max = NofPackets[i];
        }
    }

    return max;                               // �ִ� ��ȯ
};