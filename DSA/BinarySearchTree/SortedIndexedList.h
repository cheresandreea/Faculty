#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
#define NULL_TCOMP -11111

class SortedIndexedList {
private:
	friend class ListIterator;
private:
	//TODO - Representation
    struct Node
    {
        TComp info;
        Node* left;
        Node* right;
        int countLeft;

        Node(TComp v): info(v), left(nullptr), right(nullptr), countLeft(0){}
    };

    Node* root;
    Relation relation;
    int count;



public:

    TComp lastIndexOf(TComp elem) const;
	// constructor
	SortedIndexedList(Relation r);

	// returns the size of the list
	int size() const;

	//checks if the list is empty
	bool isEmpty() const;

	// returns an element from a position
	//throws exception if the position is not valid
	TComp getElement(int pos) const;

	// adds an element in the sortedList (to the corresponding position)
	void add(TComp e);

	// removes an element from a given position
	//returns the removed element
	//throws an exception if the position is not valid
	TComp remove(int pos);

	// searches for an element and returns the first position where the element appears or -1 if the element is not in the list
	int search(TComp e) const;

	// returns an iterator set to the first element of the list or invalid if the list is empty
	ListIterator iterator();

	//destructor
	~SortedIndexedList();

    void deleteBTS(Node *node);


};
