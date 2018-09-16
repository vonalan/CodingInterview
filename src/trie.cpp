#include <iostream> 
#include <map>
#include <memory>

class TrieNode {
public:
	TrieNode(char c) : value(c) {}
	TrieNode() { TrieNode(0); }

	void add(std::string::iterator begin, std::string::iterator end);
	int count_unique();
private:
	char value;
	int count = 0;
	std::map<char, std::shared_ptr<TrieNode>> nodes;
};

void TrieNode::add(std::string::iterator begin, std::string::iterator end) {
	if (begin == end) return;

	count++;
	if (nodes.find(*begin) == nodes.cend()) {
		nodes[*begin] = std::make_shared<TrieNode>(*begin);
	}

	nodes[*begin]->add(++begin, end);
}

int TrieNode::count_unique() {
	int _count = 0;

	for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
		_count += (*iter).second->count_unique();
	}

	return _count;
}
