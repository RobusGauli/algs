#include <iostream>
#include <vector>

using namespace std;


class Node {
  public:
    int value;
    Node* nextNode;
  public:
    Node(int value) {
      this -> value = value;
      this -> nextNode = NULL;
    }
    Node(int value, Node* nextNode)
     {
       this -> value = value;
       this -> nextNode = nextNode;
     }
};


ostream& operator<<(ostream& os, Node& node)
{
  os << "Node(" << node.value << ")";
  return os;
}

Node* fromList(vector<int> &alist)
{
  Node* currentNode = NULL;
  Node* firstNode = NULL;

  for(auto val: alist)
  {
    // create a node
    Node* node = new Node(val);
    if (firstNode == NULL)
    {
      firstNode = node;
    }
    if (currentNode)
    {
      currentNode -> nextNode = node;
      
    }
    currentNode = node;
  }

  return firstNode;
}


vector<int> traverse(Node* node)
{
  vector<int> result;
  while(node != NULL)
  {
    result.push_back(node -> value);
    node = node -> nextNode;
  }

  return result;
}
int main() {
  vector<int> alist = {3, 4, 5, 6, 7};
  // create a linked list from list
  Node* node = fromList(alist);
  // traverse a linked list to list
  vector<int> traversedList = traverse(node);
  // print out the list
  for(auto value: traversedList)
  {
    cout << value << endl;
  }
}