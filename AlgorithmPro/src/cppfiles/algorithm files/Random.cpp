#include"Random.h"
#include<random>


int randomInRange(int a, int b) {
    // 使用随机设备初始化随机数引擎
    std::random_device rd;  // 获取随机种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
    std::uniform_int_distribution<> dis(a, b); // 定义均匀分布

    return dis(gen); // 返回随机数
}