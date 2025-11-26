// 扰乱字符串
// 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
// 步骤1 : 如果字符串的长度为 1 ，算法停止
// 步骤2 : 如果字符串的长度 > 1 ，执行下述步骤：
//        在一个随机下标处将字符串分割成两个非空的子字符串
//        已知字符串s，则可以将其分成两个子字符串x和y且满足s=x+y
//        可以决定是要 交换两个子字符串 还是要 保持这两个子字符串的顺序不变
//        即s可能是 s = x + y 或者 s = y + x
//        在x和y这两个子字符串上继续从步骤1开始递归执行此算法
// 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串
// 如果是，返回true ；否则，返回false
// 测试链接 : https://leetcode.cn/problems/scramble-string/

#include<vector>
#include<string>
namespace
{
    //暴力递归
    class Solution1 {
    public:

        bool f(std::string& s1, std::string& s2,int l1, int r1, int l2, int r2)
        {
            int n = s1.size();
            if (l1 == r1 && l2 == r2)
            {
                return s1[l1] == s2[l2];
            }

            bool ans = false;
            int i, j;
            for (i = l1, j = l2; i < r1; i++,j++)
            {
                if (f(s1, s2, l1, i, l2, j) && f(s1, s2, i + 1, r1, j + 1, r2))
                {
                    ans = true;
                    break;
                }
            }

            for (i = l1, j = r2; i < r1; i++, j--)
            {
                if (f(s1, s2, l1, i, j, r2) && f(s1, s2, i + 1, r1, l2, j-1))
                {
                    ans = true;
                    break;
                }
            }

            return ans;
        }

        bool isScramble(std::string s1, std::string s2) {
            int n1 = s1.size();
            int n2 = s2.size();
            if (n1 != n2)
            {
                return false;
            }

            return f(s1, s2, 0, n1 - 1, 0, n1 - 1);
        }
    };

    //记忆化搜索
    class Solution2 {
    public:

        bool f(std::string& s1, std::string& s2, int l1, int r1, int l2, int r2, std::vector<std::vector<std::vector<int>>>& dp)
        {
            int n = s1.size();
            if (l1 == r1 && l2 == r2)
            {
                return s1[l1] == s2[l2];
            }

            int length = r1 - l1;
            if (dp[l1][l2][length] != -1)
            {
                return dp[l1][l2][length] == 0 ? false : true;
            }

            bool ans = false;
            int i, j;
            for (i = l1, j = l2; i < r1; i++, j++)
            {
                if (f(s1, s2, l1, i, l2, j,dp) && f(s1, s2, i + 1, r1, j + 1, r2,dp))
                {
                    ans = true;
                    break;
                }
            }

            for (i = l1, j = r2; i < r1; i++, j--)
            {
                if (f(s1, s2, l1, i, j, r2,dp) && f(s1, s2, i + 1, r1, l2, j - 1,dp))
                {
                    ans = true;
                    break;
                }
            }

            dp[l1][l2][length] = ans;

            return ans;
        }

        bool isScramble(std::string s1, std::string s2) {
            int n1 = s1.size();
            int n2 = s2.size();
            if (n1 != n2)
            {
                return false;
            }

            std::vector<std::vector<std::vector<int>>> dp(n1, std::vector<std::vector<int>>(n1, std::vector<int>(n1+1,-1)));

            return f(s1, s2, 0, n1 - 1, 0, n1 - 1,dp);
        }
    };

    //动态规划
    //太变态了，日后再想吧，做的想吐了
    //位置依赖太复杂，还要考虑边界
    //我真服了呀
    class Solution3 {
    public:

        bool isScramble(std::string s1, std::string s2) {


        }
    };


}
