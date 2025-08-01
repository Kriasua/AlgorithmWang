// 相似字符串组
// 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等
// 那么称 X 和 Y 两个字符串相似
// 如果这两个字符串本身是相等的，那它们也是相似的
// 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)；
// "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似
// 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}
// 注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似
// 形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
// 给你一个字符串列表 strs列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。
// 返回 strs 中有多少字符串组
// 测试链接 : https://leetcode.cn/problems/similar-string-groups/

#include<string>
#include<vector>
namespace
{
    class Solution {
    public:
        std::vector<int> fathers;
        int sets;

        bool isSimilar(std::vector<std::string>& strs, int a, int b)
        {
            int cnt = 0;
            for (int i = 0; i < strs[a].size() && cnt < 3; i++)
            {
                if (strs[a][i] != strs[b][i])
                {
                    cnt++;
                }
            }

            return cnt == 2 || cnt == 0;
        }

        int find(int num)
        {
            if (num == fathers[num])
            {
                return num;
            }

            int result = find(fathers[num]);
            fathers[num] = result;
            return result;
        }

        void Union(int a, int b)
        {
            int fa = find(a);
            int fb = find(b);

            if (fa == fb)
            {
                return;
            }

            fathers[fa] = fb;
            sets--;
        }

        int numSimilarGroups(std::vector<std::string>& strs) {
            fathers.resize(strs.size());
            sets = strs.size();
            for (int i = 0; i < fathers.size(); i++)
            {
                fathers[i] = i;
            }

            for (int i = 0; i < strs.size(); i++)
            {
                for (int j = i + 1; j < strs.size(); j++)
                {
                    if (isSimilar(strs, i, j))
                    {
                        Union(i, j);
                    }
                }
            }

            return sets;
        }
    };
}