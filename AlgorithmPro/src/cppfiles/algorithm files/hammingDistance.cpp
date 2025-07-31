/*��������֮��� �������� ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
������������ x �� y�����㲢��������֮��ĺ������롣*/

namespace{
    class Solution {
    public:

        int countone(int X)
        {
            unsigned int x = static_cast<unsigned int>(X);
            x = (x & 0x55555555) + ((x>>1) & 0x55555555);
            x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
            x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
            x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
            x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
            return x;
        }

     
        int hammingDistance(int x, int y) {
            int eor = x ^ y;
            return countone(eor);
        }
    };

}

