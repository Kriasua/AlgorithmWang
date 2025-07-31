/*实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。
每个元素应该有 相同的概率 被返回。*/

#include<unordered_map>
#include<vector>
#include"Random.h"
#include<random>
#include<unordered_set>
#include "pch.h"

namespace {
    class RandomizedSet {

    private:
        std::unordered_map<int, int> map;
        std::vector<int> arr;

        int randomInRange(int a, int b) {
            // 使用随机设备初始化随机数引擎
            std::random_device rd;  // 获取随机种子
            std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
            std::uniform_int_distribution<> dis(a, b); // 定义均匀分布

            return dis(gen); // 返回随机数
        }

    public:
        RandomizedSet() {

        }

        bool insert(int val) {
            auto it = map.find(val);
            if (it != map.end())
            {
                return false;
            }
            else
            {
                map.emplace(val, arr.size());
                arr.push_back(val);
                return true;
            }
        }

        bool remove(int val) {
            auto it = map.find(val);
            if (it == map.end())
            {
                return false;
            }
            else
            {
                arr[it->second] = arr[arr.size() - 1];
                map.at(arr[arr.size() - 1]) = it->second;
                map.erase(it);
                arr.pop_back();
                return true;
            }
        }

        int getRandom() {
            int random = randomInRange(0, arr.size() - 1);
            return arr[random];
        }
    };



    ///////////////////////////////////////////////////////////////
    //加强版：允许有重复数字怎么办？

    class RandomizedCollection {

    private:
        std::unordered_map<int, std::unordered_set<int>> map;
        std::vector<int> arr;

    public:
        RandomizedCollection() {

        }

        bool insert(int val) {
            auto it = map.find(val);
            if (it != map.end())
            {
                it->second.insert(arr.size());
                arr.push_back(val);
                return false;
            }
            else
            {
                map.emplace(val, std::unordered_set<int>{(int)arr.size()});
                arr.push_back(val);
                return true;
            }
        }

        bool remove(int val) {
            auto it = map.find(val);
            if (it == map.end()) return false;

            int removeIndex = *it->second.begin();
            int endValue = arr.back();

            //警惕这种情况！！！！！！
            if (val == endValue) {//就是你！！！！！
                // 直接删除末尾索引
                it->second.erase(arr.size() - 1);
            }
            else {
                // 交换并更新索引
                arr[removeIndex] = endValue;
                auto endIt = map.find(endValue);
                endIt->second.erase(arr.size() - 1);
                endIt->second.insert(removeIndex);
                it->second.erase(removeIndex);
            }

            arr.pop_back();

            //还得警惕这种！！！！！！
            if (it->second.empty()) map.erase(val);
            return true;
        }

        int getRandom() {
            int random = rand() % arr.size();
            return arr[random];
        }
    };

}