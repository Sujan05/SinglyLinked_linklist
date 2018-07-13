#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};
//implement the functions: createnode, display, insert_start_node, insert_position, delete_first, delete last, delete position
class list
{
private:
  node *head, *tail;
public:
  list(){
    head = NULL;
    tail = NULL;
  }

  void createnode_last(int value)
  {
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;

    if(head == NULL){
      head = temp;
      tail = temp;
      temp = NULL;
    }
    else {
      tail->next = temp;
      tail = temp;
    }
  }

  void createnode_first(int value)
  {
    node *temp = new node;
    temp->data = value;
    temp->next = head;

    if(tail == NULL){
      head = temp;
      tail = temp;
      temp = NULL;
    }
    else {
      head = temp;
    }

  }

  int get_length()
  {
    node *temp = new node;
    temp = head;
    int len = 0;
    while(temp!=NULL){
      len++;
      temp = temp->next;
    }
    return len;
  }

  void createnode_position(int value, int position)
  {
    int length = get_length();
    if(position > length){
      cout<<"Node position out of range"<<'\n';
    }
    else {
      node *temp = new node;
      node *pos;
      pos = head;
      int i = 1;
      while (i < position-1){
        pos = pos->next;
        i++;
      }
      temp->data = value;
      temp->next = pos->next;
      pos->next = temp;
    }
  }

  void display()
  {
    node *temp = new node;
    temp = head;
    while(temp!=NULL){
      cout <<temp->data<<"\t";
      temp = temp->next;
    }
    cout <<'\n';
  }
};



int main() {
  std::cout << "beginning of code" << '\n';
  list linklist;
  linklist.createnode_last(20);
  linklist.display();
  linklist.createnode_first(40);
  linklist.display();
  linklist.createnode_last(60);
  linklist.display();
  linklist.createnode_first(80);
  linklist.display();
  linklist.createnode_last(30);
  linklist.display();
  linklist.createnode_last(90);
  linklist.display();
  linklist.createnode_position(70, 6);
  linklist.display();
  int length = linklist.get_length();
  cout<<"linklist length:"<<length<<'\n';
  std::cout <<'\n'<< "end of code" << '\n';
  return 0;
}
