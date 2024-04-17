#ifndef RANGE_H_
#define RANGE_H_
#define REVERSE_RANGE_IMPLEMENTED
#include <iostream>

class RIterator {
  int begin_;
  int step_;

 public:
  RIterator(const int& beg, const int& step) : begin_(beg), step_(step) {
  }
  bool operator==(const RIterator& sec) {
    if (begin_ != sec.begin_) {
      if (begin_ > sec.begin_ and step_ > 0) {
        return true;
      }
      if (begin_ < sec.begin_ and step_ < 0) {
        return true;
      }
      return false;
    }
    return true;
  }
  bool operator!=(const RIterator& sec) {
    return !(*this == sec);
  }
  RIterator& operator++() {
    begin_ += step_;
    return *this;
  }
  int operator*() const {
    return begin_;
  }
};

class Range {
  int begin_;
  int end_;
  int step_;

 public:
  explicit Range(const int& end) : end_(std::max(end, 0)) {
    step_ = 1;
    begin_ = 0;
  }
  explicit Range(const int& beg, const int& end, const int& step = 1) {
    begin_ = beg;
    end_ = end;
    step_ = step;
    if (beg > end and step > 0) {
      end_ = beg;
    }
    if (beg < end and step < 0) {
      end_ = beg;
    }
    if (step == 0) {
      end_ = beg;
    }
  }
  RIterator begin() const {  // NOLINT
    return RIterator(begin_, step_);
  }
  RIterator end() const {  // NOLINT
    return RIterator(end_, step_);
  }
  RIterator rbegin() const {  // NOLINT
    if (step_ == 0) {
      return RIterator(end_, step_);
    }
    if ((end_ - begin_) % step_ == 0) {
      return RIterator(end_ - step_, -step_);
    }
    return RIterator(end_ - ((end_ - begin_) % step_), -step_);
  }
  RIterator rend() const {  // NOLINT
    return RIterator(begin_ - step_, -step_);
  }
};
#endif