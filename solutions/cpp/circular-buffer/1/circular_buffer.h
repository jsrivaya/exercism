#pragma once

#include <vector>
#include <iostream>

namespace circular_buffer {

template<typename T>
class circular_buffer {
    public:
        circular_buffer<T>(std::size_t size) : buffer(size), capacity(size) {};
        [[nodiscard]]T read() {
            if (count == 0) {
                throw std::domain_error("buffer empty");
            }
            auto value = buffer[read_it];
            read_it = (read_it + 1) % capacity;
            --count;
            return value;
        }
        void insert(T value) {
            if (count == capacity) {
                read_it = (read_it + 1) % capacity;
            }
            buffer[write_it] = value;
            write_it = (write_it + 1) % capacity;
            if (count < capacity) {
                ++count;
            }
        }
        void write(T value) {
            if (count == capacity) {
                throw std::domain_error("buffer full");
            }
            insert(value);
        }
        void overwrite(T value) {
            insert(value);
        }
        void clear () {
            read_it = write_it;
            count = 0;
        }
    private:
        std::vector<T> buffer;
        std::size_t read_it = 0;
        std::size_t write_it = 0;
        std::size_t capacity = 0;
        std::size_t count = 0;
};

}  // namespace circular_buffer
