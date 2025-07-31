// ���鼯ģ��(ţ��)
// ·��ѹ�� + С�Ҵ�
// �������� : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372
// ��ͬѧ����زο����´����й������롢����Ĵ���
// ���������������Ч�ʺܸߵ�д��
// �ύ���µ�code���ύʱ��������ĳ�"Main"������ֱ��ͨ��

#include<vector>
#include<iostream>
namespace
{
	constexpr int MAX = 1000001;
	std::vector<int> fathers;
	std::vector<int> size;
	int N, M, x, y, opt;


	int find(int num)
	{
		int ptr = num;
		int father;
		while (fathers[ptr] != ptr)
		{
			ptr = fathers[ptr];
		}

		while (fathers[num] != num)
		{
			father = fathers[num];
			fathers[num] = ptr;
			num = father;
		}

		return ptr;
	}

	int findRecursive(int num)
	{
		if (fathers[num] == num)
		{
			return num;
		}

		int result = findRecursive(fathers[num]);
		fathers[num] = result;
		return result;
	}


	bool isSameSet(int a, int b)
	{
		return find(a) == find(b);
	}

	bool isSameSetRe(int a, int b)
	{
		return findRecursive(a) == findRecursive(b);
	}


	void Union(int a, int b)
	{
		int Ancestor_a = find(a);
		int Ancestor_b = find(b);

		if (Ancestor_a == Ancestor_b)
		{
			return;
		}

		if (size[Ancestor_a] < size[Ancestor_b])
		{
			fathers[Ancestor_a] = Ancestor_b;
			size[Ancestor_b] += size[Ancestor_a];
		}
		else
		{
			fathers[Ancestor_b] = Ancestor_a;
			size[Ancestor_a] += size[Ancestor_b];
		}

	}

	void UnionRe(int a, int b)
	{
		int Ancestor_a = findRecursive(a);
		int Ancestor_b = findRecursive(b);

		if (Ancestor_a == Ancestor_b)
		{
			return;
		}

		if (size[Ancestor_a] < size[Ancestor_b])
		{
			fathers[Ancestor_a] = Ancestor_b;
			size[Ancestor_b] += size[Ancestor_a];
		}
		else
		{
			fathers[Ancestor_b] = Ancestor_a;
			size[Ancestor_a] += size[Ancestor_b];
		}

	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		fathers.resize(MAX);
		
		while (std::cin >> N >> M)
		{
			size.resize(MAX, 1);
			for (int i = 1; i <= N; i++)
			{
				fathers[i] = i;
			}

			for (int j = 0; j < M; j++)
			{
				std::cin >> opt >> x >> y;
				if (opt == 1)
				{
					std::cout << (isSameSet(x, y) ? "Yes" : "No") << "\n";
				}
				else
				{
					Union(x, y);
				}
			}
		}
	}
}


