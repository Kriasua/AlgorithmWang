//比较使用暴力递归和缓存表加速和动态规划
// 斐波那契数
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列
// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
// 也就是：F(0) = 0，F(1) = 1
// F(n) = F(n - 1) + F(n - 2)，其中 n > 1
// 给定 n ，请计算 F(n)
// 测试链接 : https://leetcode.cn/problems/fibonacci-number/
// 注意：最优解来自矩阵快速幂，时间复杂度可以做到O(log n)
// 后续课程一定会讲述！本节课不涉及！
#include <vector>
#include <chrono> // 用于演示
#include <string>
#include<iostream>

namespace
{
    //暴力递归的斐波那契数列
    int f1(int i)
    {
        if (i == 1)
        {
            return 1;
        }

        if (i == 0)
        {
            return 0;
        }

        return f1(i - 1) + f1(i - 2);
    }

    //用缓存表加速的斐波那契数列
    //这就是记忆化搜索，自顶向低的
    void compute(int i, std::vector<long long int>& LUT)
    {
        if (i == 1)
        {
            LUT[1] = 1;
            return;
        }

        if (i == 0)
        {
            LUT[0] = 0;
            return;
        }

        if (LUT[i - 1] == -1)
        {
            compute(i - 1, LUT);
        }

        if (LUT[i - 2] == -1)
        {
            compute(i - 2, LUT);
        }

        LUT[i] = LUT[i - 1] + LUT[i - 2];

    }

    int f2(int i)
    {
        std::vector<long long int> LUT(i + 1,-1);
        compute(i,LUT);
        return LUT[i];
    }


    //这是第三种方法，自底向顶的正宗动态规划
    //不写了，就是最普通最常规的从左往右递推算，一般人想到的都是这种
    //不如说上面用递归来算的其实才是一般人想不到的
    //就是为了要引出从递归到dp的一步步优化才有了上面两种算法

}





