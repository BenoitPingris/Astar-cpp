/*
** EPITECH PROJECT, 2018
** Astar
** File description:
** DSF
*/

#include "DSF.hpp"

Pos &Pos::operator=(const Pos &rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

bool Pos::operator==(const Pos &rhs) const
{
	return x == rhs.x && y == rhs.y;
}

Pos operator+(const Pos &lhs, const Pos &rhs)
{
	return {lhs.x + rhs.x, lhs.y + rhs.y};
}

bool DFS::dfs(const Pos &start, const Pos &goal)
{
	Pos tmp;

	if (start == goal)
		return true;
	if (!_visited[start.y][start.x]) {
		_visited[start.y][start.x] = true;
		for (std::size_t i = 0; i < _dirs.size(); i++) {
			tmp = start + _dirs[i];
			if (tmp.x >= 0 and
				tmp.y >= 0 and
				tmp.y < _visited.size() and
				tmp.x < _visited[tmp.y].size() and
				dfs(tmp, goal) == true)
				return _path.push_back(tmp), true;
		}
	}
	return false;
}

std::vector<Pos> DFS::findPath(const Pos &start_, const Pos &goal_)
{
	if (!_path.empty())
		_path.clear();
	_visited.resize(_map.size());
	for (std::size_t y = 0; y < _map.size(); y++) {
		for (std::size_t x = 0; x < _map[y].size(); x++) {
			if (_map[y][x] == '#')
				_visited[y].push_back(true);
			else
				_visited[y].push_back(false);
		}
	}
	dfs(start_, goal_);
	std::reverse(_path.begin(), _path.end());
	return _path;
}