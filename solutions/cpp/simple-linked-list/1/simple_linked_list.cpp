#include "simple_linked_list.h"

#include <stdexcept>
namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    auto e = new Element(entry);
    if(tail) tail->next = e;
    else head = e;

    tail = e;
    ++current_size;
}

int List::pop() {
    if(current_size == 0) return 0;
    
    auto itr = head;
    while(tail != head && itr->next != tail) itr = itr->next;

    int value = tail->data;
    delete tail;
    tail = itr;
    --current_size;

    if(current_size == 0) head = tail = nullptr;

    return value;
}

void List::reverse() {
    if (!head || !head->next) return;

    auto curr = head;
    Element* prev = nullptr;
    while (curr) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    std::swap(head, tail);
}

List::~List() {
    auto itr = head;
    while(current_size>0){
        itr = itr->next;
        delete head;
        head = itr;
        --current_size;
    }
}

}  // namespace simple_linked_list
