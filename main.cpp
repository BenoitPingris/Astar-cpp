#include "Astar.hpp"
// #include "DSF.hpp"

int main()
{
	Astar astar;
	MapStr m;

	m.push_back("###############");
	m.push_back("      #########");
	m.push_back("# ### #########");
	m.push_back("#        ######");
	m.push_back("### #### ######");
	m.push_back("### #### ######");
	m.push_back("### ####      #");
	m.push_back("### ######### #");
	m.push_back("###         # #");
	m.push_back("###############");

	astar.setMap(m);
	astar.findPath({1, 1}, {13, 8});
	return 0;
}