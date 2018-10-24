#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

// empty map container

class Node 
{
  public:
   int value;
   vector<Node*> edges;
   bool isVisited;
   Node* parent;

  public:
    Node(int value): value(value) {isVisited = false;};
    
};

ostream& operator<<(ostream& os, const Node& node)
{
  os << "Node(" << node.value << ")";
  return os;
}

vector<int>& getVectors()
{
  vector<int> numbers;
  numbers.push_back(3);
  numbers.push_back(1);
  numbers.push_back(11);
  return numbers;
}
int main()
{
 
 int myints[] = {3, 4, 5, 6};

  vector<int>& n = getVectors();

  vector<int>::iterator i;
  vector<int>::iterator start = n.begin();
  vector<int>::iterator end = n.end();
  for( i  = start; i < end;++i)
  {
    cout << *i << endl;
  }
 
 
}


