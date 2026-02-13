#pragma once

#include <memory>
#include <stack>

namespace binary_search_tree {

template<typename T>
class binary_tree {
    public:
    binary_tree(const T& value) : val(value) {};
    void insert(const T& value) {
        binary_tree* current = this;
        while (true) {
            if (value <= current->val) {
                if(!current->left_ptr) {
                    current->left_ptr = std::make_unique<binary_tree>(value);
                    return;
                }
                current = current->left_ptr.get();
            } else if (value > current->val) {
                if(!current->right_ptr) {
                    current->right_ptr = std::make_unique<binary_tree>(value);
                    return;
                }
                current = current->right_ptr.get();
            }
        }
    }
    T data() { return val; }
    const std::unique_ptr<binary_tree<T>>& left() const { return left_ptr; }
    const std::unique_ptr<binary_tree<T>>& right() const { return right_ptr; }

    class BTIterator {
        public:
        BTIterator (binary_tree<T>* root) {
            push_left(root);
        };
        bool operator==(const BTIterator& other) const {
            if (store.empty() && other.store.empty()) return true;
            if (store.empty() || other.store.empty()) return false;
            return store.top() == other.store.top();
        }
        bool operator!=(const BTIterator& other) const { 
            return !(*this == other); 
        }   
        T& operator*() {
            return store.top()->val;
        }
        BTIterator& operator++(){
            auto current = store.top();
            store.pop();
           if (current->right_ptr) {
                push_left(current->right_ptr.get());
           }
            return *this;
        }
        
        private:
        std::stack<binary_tree<T>*> store;

        void push_left(binary_tree<T>* node) {
            while (node) {
                store.push(node);
                node = node->left_ptr.get();
            }
        }
    };
    BTIterator begin() { return BTIterator(this); }
    BTIterator end() { return BTIterator(nullptr); }
    
    private:
    T val;
    std::unique_ptr<binary_tree<T>> left_ptr = nullptr;
    std::unique_ptr<binary_tree<T>> right_ptr = nullptr;
};

}  // namespace binary_search_tree
