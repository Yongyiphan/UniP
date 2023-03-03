// File header documentation is required!!!
/*!*****************************************
 \file      listint.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 8
 \date      03-03-2023
 \brief     File-header Documentation for listint.cpp
 \brief     Contains delcaration of class listint
            Type allias declaration
            3 Constructor:
                Default Constructor
                Constructor using another ListInt object
                Constructor using std::initializer_list object
            1 Destructor
            2 Operator overloads, with version that takes in std::initializer_list or another ListInt object:
                = copy assignment
                += Addition assignment
                [] subscript accessor
                << format for output stream
                + Addition that takes in variants taking in 
                    -> two ListInt Object
                    -> std::initializer_list and ListInt
                    -> ListInt and std::initializer_list
            Functions:
                push_back() -> add a given value at the end of the list
                push_front()-> add a given value at the start of the list
                pop_front() -> remove the first element of the list and return it's value
                clear()     -> empties out the list
                swap()      -> swap contents between two ListInt objects
                empty()     -> check if list is empty
                size()      -> get the number of elements in the list
 \brief     Definition for the struct Node and
            Function new_node() to create a new node with a given value

*/
////////////////////////////////////////////////////////////////////////////////

#include "listint.hpp"
namespace hlp2{
    
    ListInt::size_type ListInt::count = 0;
    ListInt::size_type ListInt::object_count(){return count;}

    /*
    \brief  Default constructor
    */
    ListInt::ListInt(){
      count++;
    }


    /*
    \brief      Constructor using another ListInt Object
    \param[in]  rhs     -> reference to ListInt object
    */
    ListInt::ListInt(ListInt const &rhs){
      Node * iter = rhs.head;
      while(iter){
        push_back(iter->data);
        iter = iter->next;        
      }
      count++;
    }

    /*
    \brief      Constructor using a std::initializer_list object
    \param[in]  rhs     -> reference to std::initializer_list object
    */
    ListInt::ListInt(std::initializer_list<value_type> const &rhs){
      for(const value_type &i : rhs){
        push_back(i);
      }
      count++;
    }

    /*
    \brief      Default deconstructor
    */
    ListInt::~ListInt(){clear();count--;}


    /*
    \brief      Copy Assignment operator overload
    \param[in]  rhs     -> reference to ListInt object
    \return     reference to current object
    */
    ListInt& ListInt::operator=(const ListInt& rhs){
      ListInt temp{rhs};
      swap(temp);
      return *this;
    }

    /*
    \brief      Copy Assignment operator overload
    \param[in]  rhs     -> reference to std::initializer_list object
    \return     reference to current object
    */
    ListInt& ListInt::operator=(std::initializer_list<value_type>& rhs){
      ListInt temp{rhs};
      swap(temp);
      return *this;
    }


    /*
    \brief      Addition Assignment operator overload
    \param[in]  rhs     -> reference to ListInt object
    \return     reference to current object
    */
    ListInt& ListInt::operator+=(const ListInt& rhs){
      Node * iter = rhs.head;
      while(iter){
        push_back(iter->data);
        iter = iter->next;        
      }
      return*this;
    }

    /*
    \brief      Addition Assignment operator overload
    \param[in]  rhs     -> reference to std::initializer_list object
    \return     reference to current object
    */
    ListInt& ListInt::operator+=(std::initializer_list<value_type>&rhs){
      for(const value_type &i : rhs){
        push_back(i);
      }
      return*this;
    }

    /*
    \brief      Subscript operator overload
    \param[in]  i       -> index to access list
    \return     value at given index
    */
    ListInt::reference ListInt::operator[](size_type i){
      Node* iter = head;
      size_type c{};
      while(iter){
        if(c == i){
          return iter->data;
        }
        c++;
        iter = iter->next;
      }
      return iter->data;
    }

    /*
    \brief      const Subscript operator overload
    \param[in]  i       -> index to access list
    \return     value at given index
    */
    ListInt::const_reference ListInt::operator[](size_type i) const{
        Node* iter = head;
        size_type c{};
        while(iter){
          if(c == i){
            return iter->data;
          }
          c++;
          iter = iter->next;
        }
      return iter->data;
    }



    /*
    \brief      add value to front of list
    \param[in]  d       -> value to add to list
    */
    void ListInt::push_front(value_type d){
      Node*newfront = new_node(d);
      if(empty()){
        head = tail = newfront;  
      }
      else{
        newfront->next = head;
        head = newfront;
      }
      counter++;
    }


    /*
    \brief      add value to back of list
    \param[in]  d       -> value to add to list
    */
    void ListInt::push_back(value_type d){
      Node* newnode = new_node(d);
      if(empty()){
        head = tail = newnode;
      }
      else{
        tail->next = newnode;
        tail = newnode;
      }
      counter++;
    }



    /*
    \brief      remove the value at the front of list
    \return     value of the first value of the list before removing it from the list
    */
    ListInt::value_type ListInt::pop_front(){
      Node*temp = head;
      value_type frontvalue = temp->data;      
      head = head->next;
      delete temp;
      counter--;
      return frontvalue;
    }



    /*
    \brief      Empty out list
    */
    void ListInt::clear(){
        while(head){
          Node*temp = head;
          head = head->next;
          counter--;
          delete temp;
        }
    }
    
    /*
    \brief      swap elements between two ListInt Objects
    \param[in]  reference to ListInt object to swap contents with
    */
    void ListInt::swap(ListInt&rhs){
        Node* tempHead, *tempTail;
        size_type tempCounter;

        tempHead = head;
        tempTail = tail;
        tempCounter = counter;
        head = rhs.head;
        tail = rhs.tail;
        counter = rhs.counter;

        rhs.head = tempHead;
        rhs.tail = tempTail;
        rhs.counter = tempCounter;        
    }


    /*
    \brief      return size of list
    \return     size of list
    */
    ListInt::size_type ListInt::size(){return counter;}

    /*
    \brief      check if list is empty
    \returns    true if list is empty, else false
    */
    bool ListInt::empty(){ return head ? false : true;}


    /*
    \brief      Create a new node with a given value
    \param[in]  data    -> value to be contained in the newly created node
    \return     pointer to newly created node
    */
    ListInt::Node* ListInt::new_node(value_type data) const{
        return new Node(data);
    }


// This function definition is provided:
////////////////////////////////////////////////////////////////////////////////
// Function: operator<<
//  Purpose: Output the list into an ostream object
//   Inputs: os - ostream object
//           list - the List to output
//  Outputs: Returns an ostream object.
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const ListInt& rhs) {
  // Start at the first node
  ListInt::Node *pnode = rhs.head;

  // Until we reach the end of the list
  while (pnode != 0) {
    os << std::setw(4) << pnode->data; // print the data in this node
    pnode = pnode->next;               // move to the next node
  }
  
  os << std::endl; // extra newline for readability
  return os;
}


/*
\brief      Addition operator overload
\param[in]  lhs     -> reference to ListInt object
\param[in]  rhs     -> reference to ListInt object to be added
\return     new list containing values from both ListInt object
*/
ListInt operator+(ListInt const& lhs, ListInt const & rhs){
  ListInt n = ListInt(lhs);
  n += rhs;
  return n;

}

/*
\brief      Addition operator overload
\param[in]  lhs     -> reference to ListInt object
\param[in]  rhs     -> reference to contaniner of type initializer_list
\return     new list containing values from both ListInt object
*/
ListInt operator+(ListInt const& lhs, std::initializer_list<ListInt::value_type>& rhs ){

  ListInt n = ListInt(lhs);
  n += rhs;
  return n;
}

/*
\brief      Addition operator overload
\param[in]  lhs     -> reference to contaniner of type initializer_list
\param[in]  rhs     -> reference to ListInt object to be added
\return     new list containing values from both ListInt object
*/
ListInt operator+(std::initializer_list<ListInt::value_type> & lhs,  ListInt const& rhs ){

  ListInt n = ListInt(lhs);
  n += rhs;
  return n;
}

}