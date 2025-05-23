#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Vector {
    std::vector<T> data;
public:
    void push_back(const T& value) { data.push_back(value); }
    T& operator[](size_t index) { return data[index]; }
    size_t size() const { return data.size(); }
    void insert(size_t pos, const T& value) { data.insert(data.begin() + pos, value); }
    void erase(size_t pos) { data.erase(data.begin() + pos); }
};

template <>
class Vector<bool> {
private:
    std::vector<unsigned char> data;
    size_t bit_count = 0;

    static size_t byte_index(size_t bit_pos) { return bit_pos / 8; }
    static size_t bit_offset(size_t bit_pos) { return bit_pos % 8; }
    static unsigned char bit_mask(size_t bit_pos) { return 1 << bit_offset(bit_pos); }

    void check_bounds(size_t index) const {
        if (index >= bit_count) {
            throw std::out_of_range("Vector<bool> index out of range");
        }
    }

public:
    class BitProxy {
        Vector<bool>& container;
        size_t bit_pos;
    public:
        BitProxy(Vector<bool>& cont, size_t pos) : container(cont), bit_pos(pos) {}

        // Преобразование в bool
        operator bool() const {
            return (container.data[byte_index(bit_pos)] & bit_mask(bit_pos)) != 0;
        }

        // Присваивание значения
        BitProxy& operator=(bool value) {
            if (value) {
                container.data[byte_index(bit_pos)] |= bit_mask(bit_pos);
            } else {
                container.data[byte_index(bit_pos)] &= ~bit_mask(bit_pos);
            }
            return *this;
        }

        // Присваивание другого BitProxy
        BitProxy& operator=(const BitProxy& other) {
            *this = static_cast<bool>(other);
            return *this;
        }
    };

    void push_back(bool value) {
        if (bit_count % 8 == 0) {
            data.push_back(0);
        }

        if (value) {
            data[byte_index(bit_count)] |= bit_mask(bit_count);
        } else {
            data[byte_index(bit_count)] &= ~bit_mask(bit_count);
        }

        bit_count++;
    }

    bool operator[](size_t index) const {
        check_bounds(index);
        return (data[byte_index(index)] & bit_mask(index)) != 0;
    }

    BitProxy operator[](size_t index) {
        check_bounds(index);
        return BitProxy(*this, index);
    }

    size_t size() const { return bit_count; }

    void insert(size_t pos, bool value) {
        if (pos > bit_count) throw std::out_of_range("Insert position out of range");

        push_back(false);

        for (size_t i = bit_count - 1; i > pos; --i) {
            bool prev_val = (*this)[i-1];
            (*this)[i] = prev_val;
        }

        (*this)[pos] = value;
    }

    void erase(size_t pos) {
        check_bounds(pos);

        for (size_t i = pos; i < bit_count - 1; ++i) {
            bool next_val = (*this)[i+1];
            (*this)[i] = next_val;
        }

        bit_count--;

        if (bit_count % 8 == 0 && !data.empty()) {
            data.pop_back();
        }
    }

    void print() const {
        std::cout << "Vector<bool> (size=" << size() << "): ";
        for (size_t i = 0; i < size(); ++i) {
            std::cout << ((*this)[i] ? '1' : '0');
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<bool> vbool;

    vbool.push_back(true);
    vbool.push_back(false);
    vbool.push_back(true);
    vbool.push_back(true);
    vbool.push_back(false);
    vbool.print();

    vbool[1] = true;
    vbool[3] = false;
    vbool.print();

    vbool.insert(2, false);
    vbool.print();

    vbool.erase(1);
    vbool.print();

    std::cout << "Size: " << vbool.size() << std::endl;

    return 0;
}