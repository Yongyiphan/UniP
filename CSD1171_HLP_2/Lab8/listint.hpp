// File header documentation is required!!!
/*!*****************************************
 \file      listint.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 8
 \date      03-03-2023
 \brief     File-header Documentation for listint.hpp
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
#ifndef LISTINT_HPP
#define LISTINT_HPP

#include <iostream>
#include <initializer_list>
#include <cstddef>
#include <iomanip>

namespace hlp2{
class ListInt{
public:
/*
\brief      Type allias
*/
  using size_type = size_t;
  using value_type = int;
  using reference = value_type&;
  using const_reference = const reference;
  using pointer = value_type*;
  using const_pointer = const value_type*;
public:
/*
\brief      return number of lists created
\return     numbers of lists created
*/
    static size_type object_count();
public:
    
    ListInt();

    /*
    \brief      Constructor using another ListInt Object
    \param[in]  rhs     -> reference to ListInt object
    */
    ListInt(ListInt const &rhs);

    /*
    \brief      Constructor using a std::initializer_list object
    \param[in]  rhs     -> reference to std::initializer_list object
    */
    ListInt(std::initializer_list<value_type> const&rhs);
    /*
    \brief      Default deconstructor
    */
    ~ListInt();

    /*
    \brief      Copy Assignment operator overload
    \param[in]  rhs     -> reference to ListInt object
    \return     reference to current object
    */
    ListInt& operator=(const ListInt&rhs);

    /*
    \brief      Copy Assignment operator overload
    \param[in]  rhs     -> reference to std::initializer_list object
    \return     reference to current object
    */
    ListInt& operator=(std::initializer_list<value_type>&rhs);

    /*
    \brief      Addition Assignment operator overload
    \param[in]  rhs     -> reference to ListInt object
    \return     reference to current object
    */
    ListInt& operator+=(const ListInt&rhs);

    /*
    \brief      Addition Assignment operator overload
    \param[in]  rhs     -> reference to std::initializer_list object
    \return     reference to current object
    */
    ListInt& operator+=(std::initializer_list<value_type>&rhs);

    /*
    \brief      Subscript operator overload
    \param[in]  i       -> index to access list
    \return     value at given index
    */
    reference operator[](size_type i);

    /*
    \brief      const Subscript operator overload
    \param[in]  i       -> index to access list
    \return     value at given index
    */
    const_reference operator[](size_type i) const;

    /*
    \brief      add value to front of list
    \param[in]  d       -> value to add to list
    */
    void push_front(value_type d);

    /*
    \brief      add value to back of list
    \param[in]  d       -> value to add to list
    */
    void push_back(value_type  d);

    /*
    \brief      remove the value at the front of list
    \return     value of the first value of the list before removing it from the list
    */
    value_type pop_front();


    /*
    \brief      Empty out list
    */
    void clear();
    
    /*
    \brief      swap elements between two ListInt Objects
    \param[in]  reference to ListInt object to swap contents with
    */
    void swap(ListInt&rhs);

    /*
    \brief      return size of list
    \return     size of list
    */
    size_type size();

    /*
    \brief      check if list is empty
    \returns    true if list is empty, else false
    */
    bool empty();


    /*
    \brief      << operator overload
    \param[in]  os      -> reference to output stream
    \param[in]  rhs     -> reference to ListInt
    \return     returns given output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const ListInt& rhs);
private:
    /*
    \brief      declaration and definition of struct Node
    */
    struct Node{
        value_type data{};
        Node*next{nullptr};
        Node(value_type t, ListInt::Node* nextptr = nullptr){
            data = t;
            next = nextptr;
        }

    };

private:
    Node*head{nullptr}, *tail{nullptr};
    size_type counter {0};
    static size_type count;

private:
    /*
    \brief      Create a new node with a given value
    \param[in]  data    -> value to be contained in the newly created node
    \return     pointer to newly created node
    */
    Node* new_node(value_type data) const;
};

/*
\brief      Addition operator overload
\param[in]  lhs     -> reference to ListInt object
\param[in]  rhs     -> reference to ListInt object to be added
\return     new list containing values from both ListInt object
*/
ListInt operator+(ListInt const& lhs, ListInt const & rhs);

/*
\brief      Addition operator overload
\param[in]  lhs     -> reference to ListInt object
\param[in]  rhs     -> reference to contaniner of type initializer_list
\return     new list containing values from both ListInt object
*/
ListInt operator+(ListInt const& lhs, std::initializer_list<ListInt::value_type>& rhs );

/*
\brief      Addition operator overload
\param[in]  lhs     -> reference to contaniner of type initializer_list
\param[in]  rhs     -> reference to ListInt object to be added
\return     new list containing values from both ListInt object
*/
ListInt operator+(std::initializer_list<ListInt::value_type> & lhs,  ListInt const& rhs );

}


#endif//LISTINT_HPP