#pragma once

#include <iostream>
#include <memory>

namespace linked_list {

template<typename T>
class List {
public:
class Node {
    public:
    Node(T& value, std::shared_ptr<Node> next = nullptr, std::shared_ptr<Node> prev = nullptr) :
        value(value), next(next), prev(prev){};
        T value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
    };
    List() : root(nullptr), tail(nullptr), size(0) {};
    void push(T value) {
        auto node = std::make_shared<Node>(value, nullptr, tail);
        if (tail) tail->next = node;
        else root = node;
        tail = node;
        ++size;
    };
    T pop() {
        if (size == 0) throw std::runtime_error("");
        auto node = tail;
        tail = node->prev;
        if (tail != nullptr) tail->next = nullptr;
        else root = nullptr;
        --size;
        return node->value;
    };
    T shift() {
        if (size == 0) throw std::runtime_error("");
        auto node = root;
        root = node->next;
        if (root) root->prev = nullptr;
        else tail = nullptr;
        --size;
        return node->value;
    };
    void unshift(T value) {
        auto node = std::make_shared<Node>(value, root, nullptr);
        if(root) root->prev = node;
        else tail = node;
        root = node;
        ++size;
    };
    bool erase(T value) {
        auto itr = root;
        while (itr && itr->value != value) {
            itr = itr->next;
        }
        if(itr && itr->value == value) {
            auto prev = itr->prev;
            auto next = itr->next;
            if (prev) prev->next = itr->next;
            if (next) next->prev = itr->prev;
            if (itr == root) root = next;
            if (itr == tail) tail = prev;
            --size;
            return true;
        }
        return false;
    };
    int count() {
        return size;
    }
protected:
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> tail;
    int size;
};

}  // namespace linked_list
