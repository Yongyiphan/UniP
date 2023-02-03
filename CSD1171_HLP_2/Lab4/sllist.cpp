/*!*****************************************
 \file      sllist.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 4
 \date      27-01-2023
 \brief     File-header Documentation for sllist.cpp
 \brief     Contains definition of  function 
            1) Allow for creation of a linked list
            2) Delete a created linked list
            3) Push a new value to the start of a linked list
            4) Push a new value to the end of a linked list
            5) Push a new value to a specifc index of a linked list
            6) Remove first instance of a provided value from a linked list
            7) 8) Two implementation of getting the first node of a linked list
            9) Find a node containing specified value in a linked list
            10) Check if linked list is empty
            11) Get the size of a linked list
*/
#include "sllist.hpp"
// Other than sllist.hpp, you really don't have to include any other files except when testing your code.
// When you're ready to submit, don't include either of the following two headers: <forward_list> and <list>

// Private functions must be declared and defined in an anonymous namespace!!!

// See the spec for structure and interface definitions!!!

namespace hlp2{
    struct node{
        int value;
        node *next;
    };
    struct sllist{
        node *head;
    };


}
namespace{
    /*
    \brief      Create a node with a specified linked list
    \param[in]  value   -> value to fill the node with
    \param[in]  next    -> pointer to the next node in a linked list
    \return     Node filled with given parameters
    */
    hlp2::node* create_node(int value, hlp2::node *next = nullptr);
    hlp2::node* create_node(int value, hlp2::node* next) {
        return new hlp2::node {value, next};
    }
}


namespace hlp2{

    // interface to individual elements of singly-linked list
    int         data(node const *p){return p->value;} // accessor to node's data
    void        data(node *p, int newval){p->value = newval;} // mutator to node's data
    node*       next(node *p){return p->next;} // pointer to successor node
    node const* next(node const *p){return p->next;} // pointer to successor node

    /*
    \brief      1) construct a empty linked list
    \return     pointer to created empty linked list
    */
    sllist* construct(){
        return new sllist{nullptr};
    }

    /*
    \brief      2) delete the created linked list
    \param[in]  ptr_sll -> pointer to a singly linked list
    */
    void destruct(sllist *ptr_sll){
        node* head = ptr_sll->head, *next;
        while(head){
            next = head->next;
            delete head;
            head = next;
        }
        delete ptr_sll;
    }

    /*
    \brief      3) add a node with a specified value to start of linked list
    \param[in]  ptr_sll -> pointer to linked list
    \param[in]  value   -> value to be added
    */
    void push_front(sllist *ptr_sll, int value){
        ptr_sll->head = create_node(value, ptr_sll->head);
    }

    /*
    \brief      4) add a node with a specified value to end of linked list
    \param[in]  ptr_sll -> pointer to linked list
    \param[in]  value   -> value to be added
    */
    void push_back(sllist *ptr_sll, int value){
        if(empty(ptr_sll)){
            push_front(ptr_sll, value);
        }
        else{
            node*head = ptr_sll->head;
            while(head->next){
                head = head->next;
            }
            head->next = create_node(value);
        }
    }

    /*
    \brief      5) add a node with a specified value to specified index of linked list
    \param[in]  ptr_sll -> pointer to linked list
    \param[in]  value   -> value to be added
    \param[in]  index   -> index of the linked list to be added at
    */
    void insert(sllist *ptr_sll, int value, size_t index){
        //start from zero
        if(index == 0){
            push_front(ptr_sll, value);
            return;
        }
        node* head = ptr_sll->head;
        while(--index && head->next){
            head = head->next;
        }
        head->next = create_node(value, head->next);
    }

    /*
    \brief      6) remove first instance of node with specified value
    \param[in]  ptr_sll -> pointer to linked list
    \param[in]  value   -> value of node to be deleted
    */
    void remove_first(sllist *ptr_sll, int value){
        //empty list
        if(empty(ptr_sll))return;
        //delete first
        node* head = ptr_sll->head;
        if(head->value == value){
            ptr_sll->head = head->next;
            delete head;
            return;
        }
        while(head->next){
            if(head->next->value == value){
                node*temp = head->next;
                head->next = temp->next;
                delete temp;
                break;;
            }
            head = head->next;
        }
    }


    /*
    \brief      7) retrieve front of linked list
    \param[in]  ptr_sll -> pointer to linked list
    \return     node at the front of the linked list
    */
    node* front(sllist *ptr_sll){return ptr_sll->head;}

    /*
    \brief      8) retrieve front of linked list
    \param[in]  ptr_sll -> pointer to linked list
    \return     node at the front of the linked list
    */
    node const* front(sllist const *ptr_sll){return ptr_sll->head;}

    /*
    \brief      9) Find node which contains specified value
    \param[in]  ptr_sll -> pointer to linked list
    \param[in]  value   -> value to find in linked list
    \return     node which contains specified value
    */
    node* find(sllist const *ptr_sll, int value){
        node* head = ptr_sll->head;
        while(head){
            if(head->value == value){
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }

    /*
    \brief      10) Check is a linked list is empty
    \param[in]  ptr_sll -> pointer to linked list
    \returns    boolean value representing is linked list is empty
    */
    bool empty(sllist const *ptr_sll){
        return ptr_sll->head ? false : true;
    }

    /*
    \brief      11) Find the size of a linked list
    \param[in]  ptr_sll -> pointer to linked list
    \return     size of linked list
    */
    size_t size(sllist const *ptr_sll){
        size_t cnt {};
        for (node *head = ptr_sll->head; head; head = next(head)) {
            ++cnt;
        }
        return cnt;
    }
}
