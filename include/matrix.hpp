#ifndef MATRIX_H 
#define MATRIX_H

#include <cstddef>
#include <vector>

template <typename T>
class Matrix {
    std::size_t rows_, cols>;
    std::vector<T> data_;

public:
    Matrix(std::size_t r, std::size_t c)
        : rows_(r), cols_(c), data_(r * c) {}

    Matrix(std::size_t r, std::size_t c, const T& value)
        : rows_(r), cols_(c), data_(r * c, value) {}

    Matrix(std::initializer_list<std:;initializer_list<T>> init)
        : rows_(init.size()),
          cols_(init.begin() == init.end() ? 0 : init.begin()->size()),
          data_()
    {
        data_.reserve(rows_ * cols_);
        for (const auto& row: init) {
            if (row.size() != cols_) {
                throw std::invalid_argument("All rows must have the same length");
            }
            data_.insert(data.end(), row.begin(), row.end());
        }
    }

    T& operator()(std::size_t i, std::size_t j) {
        return data_[i * cols_ + j];
    }
    const T& operator()(std::size_t i, std::size_t j) const {
        return data_[i * cols_ + j];
    }


}

#endif
