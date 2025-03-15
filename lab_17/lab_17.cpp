#include <iostream>
#include <vector>
#include <stdexcept>



class BitVector {
private:
    std::vector<unsigned char> data;
    size_t bit_count;

public:
    BitVector(): bit_count(0) {}

    void push_back(bool value) {
        size_t byte_index = bit_count / 8;
        size_t bit_index = bit_count % 8;

        if (byte_index >= data.size()) {
            data.push_back(0);
        }

        if (value) {
            data[byte_index] |= (1 << bit_index);
        }
        else {
            data[byte_index] &= ~(1 << bit_index);
        }

        bit_count++;
    }

    bool get(size_t index) {
        if (index >= bit_count) {
            throw std::out_of_range("Index out of range");
        }

        size_t byte_index = index / 8;
        size_t bit_index = index % 8;

        return (data[byte_index] >> bit_index) & 1;
    }

    bool operator[](size_t index) {
        return get(index);
    }

    size_t size() {
        return bit_count;
    }

    void insert(size_t index, bool value) {
        
    }
};