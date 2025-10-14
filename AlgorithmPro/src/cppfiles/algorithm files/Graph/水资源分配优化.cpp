// ˮ��Դ�����Ż�
// ������һ���� n �����ӡ�����ϣ��ͨ������ˮ��������ܵ���Ϊ���з��ӹ�ˮ��
// ����ÿ������ i�����������ֿ�ѡ�Ĺ�ˮ������һ����ֱ���ڷ����ڽ���ˮ��
// �ɱ�Ϊ wells[i - 1] ��ע�� -1 ����Ϊ ������0��ʼ ��
// ��һ���Ǵ���һ�ھ�����ܵ���ˮ������ pipes �������ڷ��Ӽ�����ܵ��ĳɱ���
// ����ÿ�� pipes[j] = [house1j, house2j, costj] 
// �����ùܵ��� house1j �� house2j������һ��ĳɱ���������˫��ġ�
// �뷵�� Ϊ���з��Ӷ���ˮ������ܳɱ�
// �������� : https://leetcode.cn/problems/optimize-water-distribution-in-a-village/

#include<vector>
#include<array>
#include<algorithm>
namespace
{
	std::vector<int> fathers;
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

	bool Union(int a, int b)
	{
		int fa = find(a);
		int fb = find(b);

		if (fa != fb)
		{
			fathers[fa] = fb;
			return true;
		}
		else
		{
			return false;
		}
	}
	int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes)
	{
		//ֱ���ڷ����ڽ�ˮ�����Կ����������һ��ˮԴ����������������ܵ�
		for (int i = 1; i <= n; i++)
		{
			pipes.push_back({ i, n + 1, wells[i - 1] });
		}

		fathers.resize(n+2);
		for (int i = 1; i <= n+1; i++)
		{
			fathers[i] = i;
		}

		std::sort(pipes.begin(), pipes.end(), [](std::vector<int>& a, std::vector<int>& b)
			{
				return a[2] < b[2];
			});

		int ans = 0;
		for (auto& col : pipes)
		{
			if (Union(col[0], col[1]))
			{
				ans += col[2];
			}
		}

		return ans;

	}
}