#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <cassert>
#include <utility>
#include <algorithm>
#include <concepts>

template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<Number T>
class Matrix {
    using Vec         = std::vector<std::vector<T>>;
    using Initializer = std::initializer_list<std::initializer_list<T>>;

public:
    using value_type     = T;
    using size_type      = typename Vec::size_type;
    using iterator       = typename Vec::iterator;
    using const_iterator = typename Vec::const_iterator;

    struct Size {
        size_type row;
        size_type col;
    };

    constexpr Matrix() = default;

    constexpr Matrix(size_type row, size_type col) {
        alloc(row, col);
    }

    constexpr Matrix(Size s) {
        alloc(s.row, s.col);
    }

    constexpr Matrix(Initializer list)
        : m_{ list }
    {
    }

    constexpr Matrix(const Matrix<T>& m)
        : m_{ m.m_ }
    {
    }

    constexpr Matrix(Matrix<T>&& m) 
        : m_{ std::move(m.m_) }
    {
    }

    constexpr Matrix<T>& operator*(const Matrix& m) {
        assert(size().row == m.size().col && size().col == m.size().col);
        T sum = 0;
        Matrix<T> c(size().row, m.size().col);

        for(size_type i = 0; i < m_.size(); ++i) {
            c[i] = [&]() {
                std::vector<T> tmp(m.m_[0].size());
                for (size_type j = 0; j < tmp.size(); ++j) {
                    tmp[j] = [&]() {
                        T sum = 0;
                        for (size_type k = 0; k < m_[0].size(); ++k) {
                            sum += m_[i][k] * m.m_[k][j];
                        }
                        return sum;
                    }();
                }
                return tmp;
            }();
        } 
        m_ = std::move(c.m_);
        return *this;
    } 

    constexpr Matrix<T>& operator+(const Matrix<T>& m) {
        assert(size().row == m.size().row && size().col == m.size().col);
        for(size_type i = 0; i < m_.size(); ++i){
              for(size_type j = 0; j < m_[i].size(); ++j){
                  m_[i][j] += m.m_[i][j]; 
              }
        }
        return *this;
    }

    constexpr Matrix<T>& operator-(const Matrix<T>& m) {
        assert(size().row == m.size().row && size().col == m.size().col);
        for(size_type i = 0; i < m.m_.size(); ++i){
            for(size_type j = 0; j < m.m_[i].size(); ++j){
                m_[i][j] -= m.m_[i][j];
            }
        }
        return *this;
    }


    constexpr inline Matrix<T>& operator=(const Matrix<T>& m){
        this->m_ = m.m_;
        return *this;
    }

    constexpr inline Matrix<T>& operator=(Matrix<T>&& m) {
        this->m_ = std::move(m.m_);
        return *this;
    }

    [[nodiscard]] constexpr inline std::vector<T>& operator[](size_t i) {
        return this->m_[i];
    }

    constexpr inline Size size() const noexcept {
        return { m_.size(), m_[0].size() };
    }

    constexpr iterator begin() noexcept { return m_.begin(); }

    constexpr iterator end() noexcept { return m_.end(); }

    constexpr const_iterator begin() const noexcept { return m_.cbegin(); }
    
    constexpr const_iterator end() const noexcept { return m_.cend(); }

    constexpr const_iterator cbegin() const noexcept { return m_.cbegin(); }
    
    constexpr const_iterator cend() const noexcept { return m_.cend(); }

    friend std::istream& operator>>(std::istream& is, Matrix<T>& m){
        size_type row, col;
        std::cout << "Enter the row size: ";
        is >> row;
        std::cout << "Enter the column size: ";
        is >> col;
        m.alloc(row, col);
        for(auto& vec : m) {
            for(auto& v : vec) {
                is >> v;
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
        for(const auto& vec : m) {
            for(const auto& v : vec) {
                os << v << "\t";
            }
            os << "\n";
        }
        return os;
    };

private:
    constexpr inline void alloc(size_t row, size_t col) {
        m_ = std::vector(
            row, std::vector<T>(col, 0)
        );
    }

    // Inner matrix
    Vec m_;
};

#endif // MATRIXFUNCTIONS_H
