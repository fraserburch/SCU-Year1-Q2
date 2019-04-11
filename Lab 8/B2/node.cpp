#include "node.h"
#include <iostream>

node::node(const value_type & init_data, node * init_link)
{

    _data = init_data;
    _link = init_link;
}

node::value_type node::data() const
{
    return _data;
}

node * node::link()
{
    return _link;
}

void node::set_data(const value_type & new_data)
{
    _data = new_data;
}

void node::set_link(node * new_link)
{
    _link = new_link;
}

std::size_t list_index(node * head_ptr, int target){
  std::size_t counter = 0;
  std::size_t index = 0;
  int initialBoot = 0;
  for(node* p = head_ptr;  p != nullptr && initialBoot == 0; p = p->link()){
    if(p -> data() == target){
      std::cout<<"THIS IS the counter: " << index <<" THIS IS item find: " << p -> data() <<std::endl;
      initialBoot = 1;
    }
    else{index++;}
  }
  return index;
}


int main(){
  node *head = new node(4, nullptr);
  node *tail(head);
  node *temp;
  temp = new node(1, nullptr);
  tail->set_link(temp);
  tail = temp;
  head = new node(1, head);
  head = new node(3, head);
  temp = new node(5, nullptr);
  tail->set_link(temp);
  tail = temp;

  size_t indexOf = list_index(head, 4);
  std::cout<< indexOf <<std::endl;


  return 0;
}
