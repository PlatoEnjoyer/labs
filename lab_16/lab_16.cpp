#include <iostream>
#include <stdexcept>


template<typename T, size_t N, size_t M>
class Matrix
{
    static_assert(N <= 3 && M <= 3, "Matrix must be <= 3x3");

private:
    T data[N][M];

public:
    Matrix()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                data[i][j] = T();
            }
        }
    }

    Matrix(const Matrix& other)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, Matrix& matrix)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Matrix& matrix)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j =0; j < M; j++)
            {
                out << matrix.data[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    Matrix operator+(const Matrix& other) const 
    {
        Matrix result;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    template<size_t K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& other) const
    {
        Matrix<T, N, K> result;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < K; j++)
            {
                result(i, j) = T();
                for (int k = 0; k < M; k++)
                {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

    template<size_t K>
    Matrix<T, N, K> operator*=(const Matrix<T, M, K>& other)
    {
        return (*this * other); 
    }

    void operator++(int)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                data[i][j]++;
            }
        }
    }

    T determinant() const 
    {
        static_assert (N == M, "Determinant is only defined for square matrices");

        if constexpr (N == 1)
        {
            return data[0][0];
        }
        else if constexpr (N == 2)
        {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        else if constexpr (N == 3) 
        {
            return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
                data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
                data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
        }
    }

    T& operator()(size_t i, size_t j)
    {
        if (i >= N || j >= M) {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return data[i][j];
        }
    }

    const T& operator()(size_t i, size_t j) const 
    {
        if (i >= N || j >= M) {
            throw std::out_of_range("Index out of range");
        }
        return data[i][j];
    }
};





int main()
{
    Matrix<float, 2, 2> matrix1;
    std::cout << "Enter 2x2 matrix elements:" << std::endl;
    std::cin >> matrix1;

    Matrix<float, 2, 2> matrix2;
    std::cout << "Enter another 2x2 matrix elements:" << std::endl;
    std::cin >> matrix2;

    std::cout << "Matrix 1:" << std::endl << matrix1;
    std::cout << "Matrix 2:" << std::endl << matrix2;

    Matrix<float, 2, 2> matrix3 = matrix1 + matrix2;
    std::cout << "Matrix 1 + Matrix 2:" << std::endl << matrix3;

    Matrix<float, 2, 2> mat4 = matrix1 * matrix2;
    std::cout << "Matrix 1 * Matrix 2:" << std::endl << mat4;

    return 0;
}