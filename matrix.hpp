#pragma once
#include <cstddef>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(std::vector<std::vector<int>> input);

    int get_size() const;
    int get_value(size_t row, size_t col) const;
    void set_value(size_t row, size_t col, int value);

    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;

    void swap_rows(size_t r1, size_t r2);
    void swap_cols(size_t c1, size_t c2);

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
};
