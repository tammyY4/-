#ifndef STRINGVIEW_H_
#define STRINGVIEW_H_

#include <stdexcept>

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
  const char* arr_;
  size_t size_ = 0;

 public:
  StringView() {
    arr_ = nullptr;
  }

  StringView(const char* ar) {  // NOLINT
    arr_ = ar;
    const char* all_str = arr_;
    while (*all_str != '\0') {
      ++all_str;
      ++size_;
    }
  }

  StringView(const char* ar, size_t size) {
    arr_ = ar;
    size_ = size;
  }

  const char& operator[](size_t i) const {
    return arr_[i];
  }

  const char& At(size_t idx) const {
    if (idx < size_) {
      return arr_[idx];
    }
    throw StringViewOutOfRange{};
  }

  const char& Front() const {
    return arr_[0];
  }

  const char& Back() const {
    return arr_[size_ - 1];
  }

  const char* Data() const {
    return arr_;
  }

  size_t Size() const {
    return size_;
  }

  bool Empty() const {
    return size_ == 0;
  }

  size_t Length() const {
    return size_;
  }

  void Swap(StringView& change) {
    std::swap(arr_, change.arr_);
    std::swap(size_, change.size_);
  }

  void RemovePrefix(size_t prefix_size) {
    arr_ = arr_ + prefix_size;
    size_ = size_ - prefix_size;
  }

  void RemoveSuffix(size_t suffix_size) {
    size_ = size_ - suffix_size;
  }

  StringView Substr(size_t pos, size_t count = -1) {
    if (pos <= size_) {
      size_t mini = (size_ - pos > count ? count : size_ - pos);
      return StringView(arr_ + pos, mini);
    }
    throw StringViewOutOfRange{};
  }
};
#endif