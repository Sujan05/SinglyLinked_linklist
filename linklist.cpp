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
//Creating the node at the last position of linklist
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
//Creating the node at the first position of linklist
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
//getting the linklist length
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
//Creating the node at a particular position of linklist
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
//deleting the first node of linklist
  void delete_first()
  {
    node *temp = new node;
    temp = head;
    head = temp->next;
    delete temp;
  }
//delete last node
  void delete_last()
  {
    node *temp = new node;
    temp = tail;
    node *pos, *prev;
    pos = head;
    while (pos!=tail){
      prev = pos;
      pos = pos->next;
    }
    prev->next = NULL;
    tail = prev;
    delete temp;
  }
//deleting the node at a particular position
  void delete_position(int position)
  {
    int length = get_length();
    if(position > length){
      cout<<"Node position out of range"<<'\n';
    }
    else {
      node *temp = new node;
      node *pos, *prev;
      pos = head;
      int i = 1;
      while (i <= position-1){
        prev = pos;
        pos = pos->next;
        i++;
      }
      prev->next = pos->next;
      temp = pos;
      delete temp;
    }
  }
//printing the linklist
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
  linklist.delete_first();
  linklist.display();
  linklist.delete_last();
  linklist.display();
  linklist.delete_position(4);
  linklist.display();
  int length = linklist.get_length();
  cout<<"linklist length:"<<length<<'\n';
  std::cout <<'\n'<< "end of code" << '\n';
  return 0;
}
