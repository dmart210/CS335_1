// --> YOUR NAME here
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
#include <vector>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
    template<typename Object>
    class Points2D {
    public:
        // Default "big five" -- you have to alter them for your assignment.
        // That means that you will remove the "= default" statement.
        //  and you will provide an implementation.

        // Zero-parameter constructor.
        // Set size to 0.
        Points2D(){
            size_ = 0;
            sequence_ = nullptr;
        }

        // Copy-constructor.
        Points2D(const Points2D &rhs)
        {
            size_ = rhs.size_;
            sequence_ = new std::array<Object,2>[size_];
            for (size_t i = 0; i < (2*size_); i++){
                (*sequence_)[i] = (*rhs.sequence_)[i];
            }
        }

        // Copy-assignment. If you have already written
        // the copy-constructor and the move-constructor
        // you can just use:

        Points2D& operator=(const Points2D &rhs){
            if (this != &rhs) {
                size_ = rhs.size_;
                for (size_t i = 0; i < (2*size_); i++) (*sequence_)[i] = (*rhs.sequence_)[i];
            }
            return *this;
        }

        // Move-constructor.
        Points2D(Points2D &&rhs){
            size_ = rhs.size_;
            sequence_ = rhs.sequence_;
            rhs.size_ = 0;
            rhs.sequence_ = nullptr;
        }

        // Move-assignment.
        // Just use std::swap() for all variables.
        Points2D& operator=(Points2D &&rhs){
            std::swap(size_, rhs.size_);
            std::swap(sequence_, rhs.sequence_);
            return *this;
        }

        ~Points2D(){
            if(sequence_ != nullptr){
                delete [] sequence_;
                sequence_ = nullptr;
            }
        }
        // End of big-five.

        // One parameter constructor.
        Points2D(const std::array<Object, 2>& item) {
            size_ = 1;
            sequence_= new std::array<Object,2>[size_];
            (*sequence_)[0] = item[0];
            (*sequence_)[1] = item[1];

        }

        size_t size() const {
            // Code missing.
            return size_;
        }

        // @location: an index to a location in the sequence.
        // @returns the point at @location.
        // const version.
        // abort() if out-of-range.
        const std::array<Object, 2>& operator[](size_t location) const {
            // Code missing
            if (location > size_ > location) abort();
            return sequence_[location];
        }
        //  @c1: A sequence.
        //  @c2: A second sequence.
        //  @return their sum. If the sequences are not of the same size, append the
        //    result with the remaining part of the larger sequence.
        friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
            Points2D<Object> addition;
            size_t max_size, min_size;
            if (c1.size_ > c2.size_){
                max_size = c1.size_;
                min_size = c2.size_;
            }
            else{
                max_size = c2.size_;
                min_size = c1.size_;
            }
            addition.sequence_ = new std::array<Object,2> [max_size];
            addition.size_ = max_size;
            for (size_t i = 0; i < 2*max_size; ++i){
                (*addition.sequence_)[i] = (*c1.sequence_)[i] + (*c2.sequence_)[i];
            }
            return addition;
        }
// Code missing
        // Overloading the << operator.
        friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
            if (some_points.sequence_ == nullptr) {
                out << "(" << ")" << std::endl;
                return out;
            }
            else {
                for (long unsigned int n = 0; n < some_points.size_; n++) {
                    out << '(' << (*some_points.sequence_)[(2 * n)] << ',' << (*some_points.sequence_)[(2 * n) + 1] << ')';
                }
                std::cout << std::endl;
                return out;
            }
        }

        // Overloading the >> operator.
        // Read a chain from an input stream (e.g., standard input).
        friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
            // Code missing.
            in >> some_points.size_;
            some_points.sequence_ = new std::array<Object,2>[some_points.size_];
            for (size_t i = 0; i < (2*some_points.size_)-1; i++){
                in >> (*some_points.sequence_)[i] >> (*some_points.sequence_)[++i];
            }
            return in;
        }



    private:
        // Sequence of points.
        std::array<Object, 2> *sequence_;
        // Size of sequence.
        size_t size_;
    };

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
