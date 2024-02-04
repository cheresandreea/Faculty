#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	//TODO - Implementation tetha(1)
    root = nullptr;
    relation = r;
    count = 0;

}

int SortedIndexedList::size() const {
	//TODO - Implementation tetha(1)
	return count;
}

bool SortedIndexedList::isEmpty() const {
	//TODO - Implementation tetha(1)
    if(count == 0)
        return true;
	return false;
}

TComp SortedIndexedList::getElement(int i) const {
    //TODO - Implementation best case - tetha(1), worst, average case - tetha(n), total O(n)

    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid position");
    }

    Node *current = root;
    while (current != nullptr) {
        if (current->countLeft == i)
            return current->info;
        else
        if (current->countLeft < i)
        {

            i = i - current->countLeft - 1;
            current = current->right;
        }

        else current = current->left;

    }

}

TComp SortedIndexedList::remove(int i) {
	//TODO - Implementation best case - tetha(1), worst, average case - tetha(n)
    if (i < 0 || i >= count) {
        throw std::out_of_range("Invalid position");
    }

    Node* current = root;
    Node* parent = nullptr;
    int currentPos = 0;

    while(current != nullptr)
    {
        int leftCount;

        if(current->left != nullptr)
            leftCount = current->countLeft;
        else leftCount = 0;

        if(i == currentPos + leftCount) {
            TComp removedEL = current->info;

            if (current->left == nullptr && current->right == nullptr) {
                //Case 1: the node is a leaf
                if (parent == nullptr) {
                    root = nullptr;
                } else if (parent->left == current)
                    parent->left = nullptr;
                else parent->right = nullptr;
                delete current;

            } else if (current->left == nullptr)
            {
                //Case 2: the node has only the right part
                if(parent == nullptr)
                {
                    root = current->right;
                }
                else if(parent->left == current)
                    parent->left = current->right;
                else parent->right = current->right;
                delete current;
            }
            else
                if(current->right == nullptr)
                {
                    //case 3: only the left part
                    if(parent == nullptr)
                        root = current->left;
                    else if(parent->left == current)
                        parent->left = current->left;
                    else parent->right = current->right;
                    delete current;
                }
            else {
                //case 4: has both
                /*Node* successorParent = current;
                Node* successor = current->right;

                while(successor->left != nullptr)
                {
                    successorParent = successor;
                    successor = successor->left;
                }

                current->info = successor->info;
                if(successorParent == current)
                    successorParent->right = successor->right;
                else successorParent->left = successor->left;

                delete successor;*/
            }
            count--;
            return removedEL;

        }
        else if(i < currentPos + leftCount)
        {
            parent = current;
            current = current->left;
        }
        else {
            currentPos += leftCount + 1;
            parent = current;
            current = current->right;
        }


    }
    throw std::out_of_range("Invalid position");
}




int SortedIndexedList::search(TComp e) const {
	//TODO - Implementation best case - tetha(1), worst, average case - tetha(n)
    Node* currentNode = root;
    int pos = 0;

    while(currentNode!= nullptr)
    {
        if(e == currentNode->info)
        {
            return pos + currentNode->countLeft;
        }
        if(relation(e, currentNode->info))
            currentNode = currentNode->left;
        else {
            pos += currentNode->countLeft + 1;
            currentNode = currentNode->right;
        }
    }
	return -1;
}

void SortedIndexedList::add(TComp e) {
	//TODO - Implementation best case - tetha(1), worst, average - tetha(n), total - O(n)

    Node* newNode = new Node(e);

    if(root == nullptr)
    {
        root = newNode;
        count++;
        return;
    }
    Node* current = root;
    Node* parent = nullptr;

    while(current != nullptr)
    {
        parent = current;

        if(relation(e, current->info))//if e <= info
        {
            current->countLeft++;
            current = current->left;
        }
        else current = current->right;
    }
    if(relation(e, parent->info))
    {
        parent->left = newNode;
    }
    else parent->right = newNode;

    count++;

}

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//TODO - Implementation tetha(n)
    delete(root);
}

void SortedIndexedList::deleteBTS(Node* node)
{
    //TODO - Implementation
    if(root != nullptr)
    {
        deleteBTS(node->left);
        deleteBTS(node->right);

        delete(node);

    }
}

int SortedIndexedList::lastIndexOf(TComp elem) const {

   /* //TODO - Implementation best case - tetha(1), worst, average case - tetha(n)
    Node* currentNode = root;
    int pos = 0;

    while(currentNode!= nullptr)
    {
        if(elem == currentNode->info)
        {
            pos = pos + currentNode->countLeft;
            while(currentNode->right->info == elem)
            {
                pos = pos + currentNode->countLeft;
                currentNode = currentNode->right;
            }
            return pos;
        }
        if(relation(elem, currentNode->info))
            currentNode = currentNode->left;
        else {
            pos += currentNode->countLeft + 1;
            currentNode = currentNode->right;
        }
    }
    return -1;*/

}


