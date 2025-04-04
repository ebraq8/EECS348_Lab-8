#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix(std::vector<std::vector<int>> input) : data(input) {}

int Matrix::get_size() const {
    return data.size();
}

int Matrix::get_value(size_t row, size_t col) const {
    if (row >= data.size() || col >= data[row].size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[row][col];
}

void Matrix::set_value(size_t row, size_t col, int value) {
    if (row >= data.size() || col >= data[row].size()) {
        throw std::out_of_range("Index out of bounds");
    }
    data[row][col] = value;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < data.size(); ++i)
        sum += data[i][i];
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    size_t N = data.size();
    for (size_t i = 0; i < N; ++i)
        sum += data[i][N - i - 1];
    return sum;
}

void Matrix::swap_rows(size_t r1, size_t r2) {
    if (r1 >= data.size() || r2 >= data.size()) {
        throw std::out_of_range("Row index out of bounds");
    }
    std::swap(data[r1], data[r2]);
}

void Matrix::swap_cols(size_t c1, size_t c2) {
    for (auto& row : data) {
        if (c1 >= row.size() || c2 >= row.size()) {
            throw std::out_of_range("Column index out of bounds");
        }
        std::swap(row[c1], row[c2]);
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (data.size() != other.data.size())
        throw std::invalid_argument("Matrix sizes must match for addition");

    Matrix result = *this;
    for (size_t i = 0; i < data.size(); ++i)
        for (size_t j = 0; j < data[i].size(); ++j)
            result.data[i][j] += other.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    size_t N = data.size();
    if (N != other.data.size())
        throw std::invalid_argument("Matrix sizes must match for multiplication");

    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            for (size_t k = 0; k < N; ++k)
                result[i][j] += data[i][k] * other.data[k][j];

    return Matrix(result);
}
