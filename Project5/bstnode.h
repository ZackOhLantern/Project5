#ifndef BST_NODE_DEF_H
#define BST_NODE_DEF_H

// Node implementation: Implemented
template<typename Item>
class Node {
public:
	Node(Item i, Node* l, Node* r) :it(i), l(l), r(r) {}
	Node() :Node(0, nullptr, nullptr) {}

	Node* left() { return l; }
	Node* right() { return r; }

	void left(Node * lft) { l = lft; }
	void right(Node * rht){r = rht;}

	Item item() { return it; }
	void item(Item itm) { it = itm; }

private:
	Item it;
	Node *l, *r;
};


#endif