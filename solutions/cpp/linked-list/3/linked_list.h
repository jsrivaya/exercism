#pragma once

#include <iostream>
#include <memory>

namespace linked_list {

template<typename T>
class List {
public:
class Node {
    public:
    Node(const T& value, std::shared_ptr<Node> next = nullptr, std::shared_ptr<Node> prev = nullptr) :
        value(value), next(next), prev(prev){};
        T value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
    };
    List() = default;
    void push(const T& value) {
        auto node = std::make_shared<Node>(value, nullptr, tail);
        if (tail) tail->next = node;
        else head = node;
        tail = node;
        ++size;
    };
    T pop() {
        if (size == 0) throw std::runtime_error("");
        auto node = tail;
        tail = node->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr;
        --size;
        return node->value;
    };
    T shift() {
        if (size == 0) throw std::runtime_error("");
        auto node = head;
        head = node->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        --size;
        return node->value;
    };
    void unshift(const T& value) {
        auto node = std::make_shared<Node>(value, head, nullptr);
        if(head) head->prev = node;
        else tail = node;
        head = node;
        ++size;
    };
    bool erase(const T& value) {
        auto itr = head;
        while (itr && itr->value != value) {
            itr = itr->next;
        }
        if(itr && itr->value == value) {
            auto prev = itr->prev;
            auto next = itr->next;
            if (prev) prev->next = itr->next;
            if (next) next->prev = itr->prev;
            if (itr == head) head = itr->next;
            if (itr == tail) tail = itr->prev;
            --size;
            return true;
        }
        return false;
    };
    size_t count() {
        return size;
    }
private:
    std::shared_ptr<Node> head = nullptr;
    std::shared_ptr<Node> tail = nullptr;
    size_t size = 0;
};

}  // namespace linked_list
