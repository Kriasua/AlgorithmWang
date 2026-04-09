#include<vector>
#include<unordered_set>
#include<string>
#include<queue>
namespace 
{
	class SnakeGame
	{
	public:
		int width;
		int height;
		std::vector<std::vector<int>> foods;
		std::deque<std::vector<int>> bodys;
		std::unordered_set<int> set;
		int score = 0;

		SnakeGame(int w, int h, std::vector<std::vector<int>>& f) : width(w), height(h), foods(f)
		{
			bodys.push_back({ 0,0 });
			set.emplace(0);
		}

		std::vector<int> getMovement(std::string movement)
		{
			if (movement == "R")
			{
				return { 0,1 };
			}

			if (movement == "L")
			{
				return { 0,-1 };
			}

			if (movement == "U")
			{
				return { -1,0 };
			}

			if (movement == "D")
			{
				return { 1,0 };
			}
		}


		bool isCrashed(std::string movement)
		{
			int headX = bodys.front()[0];
			int headY = bodys.front()[1];
			if (headX < 0 || headX >= height || headY < 0 || headY >= width)
			{
				return true;
			}

			if (set.contains(headX * width + headY))
			{
				return true;
			}

			return false;
		}

		int move(std::string movement)
		{
			std::vector<int> move = getMovement(movement);
			int newX = bodys.front()[0] + move[0];
			int newY = bodys.front()[1] + move[1];

			if (score < foods.size() && newX == foods[score][0] && newY == foods[score][1])
			{
				score++;
				set.emplace(newX * width + newY);
				bodys.push_front({ newX,newY });
			}
			else
			{
				set.erase(bodys.back()[0] * width + bodys.back()[1]);
				set.emplace(newX * width + newY);
				bodys.pop_back();
				bodys.push_front({ newX,newY });
			}

			if (isCrashed(movement))
			{
				return -1;
			}
			else
			{
				return score;
			}
		}

	};
}