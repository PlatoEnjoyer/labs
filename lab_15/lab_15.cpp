#include <iostream>
#include <stdexcept>

class MyVector {
private:
    int* data;          
    size_t size_;       
    size_t capacity_;  

public:
    MyVector() : data(nullptr), size_(0), capacity_(0) {}

    MyVector(const MyVector& other) : size_(other.size_), capacity_(other.capacity_) 
    {
        data = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    MyVector& operator=(const MyVector& other) 
    {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data = new int[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~MyVector() 
    {
        delete[] data;
    }

    void resize(size_t new_size) 
    {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        size_ = new_size;
    }

    void reserve(size_t new_capacity) 
    {
        if (new_capacity > capacity_) {
            int* new_data = new int[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }
    }

    void shrink_to_fit() 
    {
        if (size_ < capacity_) {
            int* new_data = new int[size_];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity_ = size_;
        }
    }

    int& front() 
    {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    int& back() 
    {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[size_ - 1];
    }

    size_t size() 
    {
        return size_;
    }

    bool empty() 
    {
        return size_ == 0;
    }

    size_t capacity() 
    {
        return capacity_;
    }

    void push_back(int value) {
        if (size_ >= capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data[size_++] = value;
    }

    void insert(size_t index, int value) 
    {
        if (index > size_) {
            return;
        }
        if (size_ >= capacity_) 
        {
            if (capacity_ == 0)
            {
                reserve(1);
            }
            else
            {
                capacity_ *= 2;
                reserve(capacity_);
            } 
        }

        for (size_t i = size_; i > index; --i) 
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size_;
    }

    void erase(size_t index) 
    {
        if (index >= size_) {
            return;
        }
        for (size_t i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
    }

    int& operator[](size_t index) 
    {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};


int main() {
    MyVector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    vec.insert(1, 4);
    std::cout << "After insert: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.erase(2);
    std::cout << "After erase: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}