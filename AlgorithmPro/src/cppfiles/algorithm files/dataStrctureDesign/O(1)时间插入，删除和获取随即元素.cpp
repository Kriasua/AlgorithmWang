/*ʵ��RandomizedSet �ࣺ

RandomizedSet() ��ʼ�� RandomizedSet ����
bool insert(int val) ��Ԫ�� val ������ʱ���򼯺��в����������� true �����򣬷��� false ��
bool remove(int val) ��Ԫ�� val ����ʱ���Ӽ������Ƴ���������� true �����򣬷��� false ��
int getRandom() ����������м����е�һ�����������֤���ô˷���ʱ���������ٴ���һ��Ԫ�أ���
ÿ��Ԫ��Ӧ���� ��ͬ�ĸ��� �����ء�*/

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
            // ʹ������豸��ʼ�����������
            std::random_device rd;  // ��ȡ�������
            std::mt19937 gen(rd()); // ʹ�� Mersenne Twister ����
            std::uniform_int_distribution<> dis(a, b); // ������ȷֲ�

            return dis(gen); // ���������
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
    //��ǿ�棺�������ظ�������ô�죿

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

            //�����������������������
            if (val == endValue) {//�����㣡��������
                // ֱ��ɾ��ĩβ����
                it->second.erase(arr.size() - 1);
            }
            else {
                // ��������������
                arr[removeIndex] = endValue;
                auto endIt = map.find(endValue);
                endIt->second.erase(arr.size() - 1);
                endIt->second.insert(removeIndex);
                it->second.erase(removeIndex);
            }

            arr.pop_back();

            //���þ������֣�����������
            if (it->second.empty()) map.erase(val);
            return true;
        }

        int getRandom() {
            int random = rand() % arr.size();
            return arr[random];
        }
    };

}