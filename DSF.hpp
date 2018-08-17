/*
** EPITECH PROJECT, 2018
** Astar
** File description:
** DSF
*/

#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using MapStr = std::vector<std::string>;
using MapBool = std::vector<std::vector<bool>>;

struct Pos {
public:
	Pos() = default;
	Pos(const int &x, const int &y) : x(x), y(y) {}
	Pos(const Pos &pos) : x(pos.x), y(pos.y) {}
	int x;
	int y;
	Pos &operator=(const Pos &);
	bool operator==(const Pos &) const;
};

Pos operator+(const Pos &, const Pos &);

class DFS {
public:
	DFS(const MapStr &map) : _map(map)
	{}
	std::vector<Pos> findPath(const Pos &start_, const Pos &goal_);
	bool dfs(const Pos &, const Pos &);

private:
	MapStr _map;
	MapBool _visited;
	std::vector<Pos> _path;
	std::vector<Pos> _dirs = {{-1, 0},{0, -1},{1, 0},{0, 1}};
	std::size_t rows;
	std::size_t cols;
};