#include "matrix.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

void print_matrix(const Matrix& matrix) {
    int size = matrix.get_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix.get_value(i, j);
        }
        std::cout << std::endl;
    }
}

Matrix read_matrix(std::ifstream& file, int size) {
    std::vector<std::vector<int>> data(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> data[i][j];
    return Matrix(data);
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    int size;
    file >> size;

    Matrix A = read_matrix(file, size);
    Matrix B = read_matrix(file, size);

    std::cout << "\nMatrix A:\n";
    print_matrix(A);

    std::cout << "\nMatrix B:\n";
    print_matrix(B);

    std::cout << "\nA + B:\n";
    Matrix sum = A + B;
    print_matrix(sum);

    std::cout << "\nA * B:\n";
    Matrix product = A * B;
    print_matrix(product);

    std::cout << "\nMain diagonal sum of A: " << A.sum_diagonal_major() << "\n";
    std::cout << "Secondary diagonal sum of A: " << A.sum_diagonal_minor() << "\n";

    std::cout << "\nA after swapping rows 0 and 3:\n";
    A.swap_rows(0, 3);
    print_matrix(A);

    std::cout << "\nA after swapping columns 1 and 2:\n";
    A.swap_cols(1, 2);
    print_matrix(A);

    std::cout << "\nA after setting value at (2,2) to 99:\n";
    A.set_value(2, 2, 99);
    print_matrix(A);

    return 0;
}
