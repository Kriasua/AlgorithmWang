#include"Random.h"
#include<random>


int randomInRange(int a, int b) {
    // ʹ������豸��ʼ�����������
    std::random_device rd;  // ��ȡ�������
    std::mt19937 gen(rd()); // ʹ�� Mersenne Twister ����
    std::uniform_int_distribution<> dis(a, b); // ������ȷֲ�

    return dis(gen); // ���������
}