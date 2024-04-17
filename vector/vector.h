#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <type_traits>
#include <stdexcept>

class VectorOutOfRange : public std::out_of_range {
 public:
  VectorOutOfRange() : std::out_of_range("VectorViewOutOfRange") {
  }
};

template <typename T>
class Vector {
  T* ptr_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;

 public:
  using ValueType = T;
  using Pointer = T*;
  using ConstPointer = const T*;
  using Reference = T&;
  using ConstReference = const T&;
  using SizeType = size_t;
  using Iterator = T*;
  using ConstIterator = const T*;
  using ReverseIterator = std::reverse_iterator<Iterator>;
  using ConstReverseIterator = std::reverse_iterator<ConstIterator>;

  Vector();
  explicit Vector(size_t size);
  Vector(size_t size, const T& value);
  template <class It, class = std::enable_if_t<std::is_base_of<
                          std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value>>
  Vector(It first, It last);
  Vector(std::initializer_list<T> init);
  Vector(const Vector& other);
  Vector(Vector&& other) noexcept;
  ~Vector();
  Vector& operator=(const Vector& other);
  Vector& operator=(Vector&& other) noexcept;
  size_t Size() const noexcept;
  size_t Capacity() const noexcept;
  bool Empty() const noexcept;
  const T& operator[](const size_t& ind) const noexcept;
  T& operator[](const size_t& ind) noexcept;
  const T& At(const size_t& ind) const;
  T& At(const size_t& ind);
  const T& Front() const;
  T& Front();
  const T& Back() const;
  T& Back();
  const T* Data() const;
  T* Data();
  void Swap(Vector& other);
  void Resize(size_t new_size);
  void Resize(size_t new_size, const T& value);
  void Reserve(size_t new_cap);
  void ShrinkToFit();
  void Clear();
  void PushBack(const T& value);
  void PushBack(T&& value);
  void PopBack();
  template <typename U>
  friend bool operator<(const Vector<U>& first, const Vector<U>& second);
  template <typename U>
  friend bool operator>(const Vector<U>& first, const Vector<U>& second);
  template <typename U>
  friend bool operator<=(const Vector<U>& first, const Vector<U>& second);
  template <typename U>
  friend bool operator>=(const Vector<U>& first, const Vector<U>& second);
  template <typename U>
  friend bool operator==(const Vector<U>& first, const Vector<U>& second);
  template <typename U>
  friend bool operator!=(const Vector<U>& first, const Vector<U>& second);

  Iterator begin() {  // NOLINT
    return ptr_;
  }

  ConstIterator begin() const {  // NOLINT
    return ptr_;
  }

  ConstIterator cbegin() const {  // NOLINT
    return ptr_;
  }

  Iterator end() {  // NOLINT
    return ptr_ + size_;
  }

  ConstIterator end() const {  // NOLINT
    return ptr_ + size_;
  }

  ConstIterator cend() const {  // NOLINT
    return ptr_ + size_;
  }

  std::reverse_iterator<Iterator> rbegin() {  // NOLINT
    return std::reverse_iterator<Iterator>(ptr_ + size_);
  }

  std::reverse_iterator<ConstIterator> rbegin() const {  // NOLINT
    return std::reverse_iterator<ConstIterator>(ptr_ + size_);
  }

  std::reverse_iterator<ConstIterator> crbegin() const {  // NOLINT
    return std::reverse_iterator<ConstIterator>(ptr_ + size_);
  }

  std::reverse_iterator<Iterator> rend() {  // NOLINT
    return std::reverse_iterator<Iterator>(ptr_);
  }

  std::reverse_iterator<ConstIterator> rend() const {  // NOLINT
    return std::reverse_iterator<ConstIterator>(ptr_);
  }

  std::reverse_iterator<ConstIterator> crend() const {  // NOLINT
    return std::reverse_iterator<ConstIterator>(ptr_);
  }
};

template <typename T>
Vector<T>::Vector() = default;

template <typename T>
Vector<T>::Vector(size_t size) try : size_(size), capacity_(size) {
  if (size != 0) {
    ptr_ = new T[size];
  }
} catch (...) {
  ptr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  throw;
}

template <typename T>
Vector<T>::Vector(size_t size, const T& value) try : size_(size), capacity_(size) {
  if (size != 0) {
    ptr_ = new T[size];
    try {
      std::fill(ptr_, ptr_ + size_, value);
    } catch (...) {
      delete[] ptr_;
      throw;
    }
  }
} catch (...) {
  ptr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  throw;
}

template <typename T>
template <class It, class>
Vector<T>::Vector(It first, It last) try : size_(std::distance(first, last)), capacity_(size_) {
  if (size_ != 0) {
    ptr_ = new T[std::distance(first, last)];
    try {
      for (size_t i = 0; i < size_; ++i) {
        *(ptr_ + i) = *(first++);
      }
    } catch (...) {
      delete[] ptr_;
      throw;
    }
  }
} catch (...) {
  ptr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  throw;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) try : size_(init.size()), capacity_(init.size()) {
  if (size_ != 0) {
    ptr_ = new T[init.size()];
    try {
      T* p = ptr_;
      for (const auto& elem : init) {
        *p = elem;
        ++p;
      }
    } catch (...) {
      delete[] ptr_;
      throw;
    }
  }
} catch (...) {
  ptr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  throw;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) try : size_(other.size_), capacity_(other.capacity_) {
  if (other.capacity_ != 0) {
    ptr_ = new T[other.capacity_];
    try {
      for (size_t i = 0; i < size_; ++i) {
        *(ptr_ + i) = *(other.ptr_ + i);
      }
    } catch (...) {
      delete[] ptr_;
      throw;
    }
  }
} catch (...) {
  ptr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  throw;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : ptr_(other.ptr_), size_(other.size_), capacity_(other.capacity_) {
  other.ptr_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename T>
Vector<T>::~Vector() {
  delete[] ptr_;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
  if (this != &other) {
    if (capacity_ < other.size_) {
      delete[] ptr_;
      try {
        ptr_ = new T[other.size_];
      } catch (...) {
        ptr_ = nullptr;
        size_ = 0;
        capacity_ = 0;
        throw;
      }
      capacity_ = other.size_;
    }
    size_ = other.size_;
    try {
      for (size_t i = 0; i < size_; ++i) {
        ptr_[i] = other.ptr_[i];
      }
    } catch (...) {
      size_ = 0;
      throw;
    }
  }
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
  if (this != &other) {
    delete[] ptr_;
    ptr_ = std::exchange(other.ptr_, nullptr);
    size_ = std::exchange(other.size_, 0);
    capacity_ = std::exchange(other.capacity_, 0);
  }
  return *this;
}

template <typename T>
size_t Vector<T>::Size() const noexcept {
  return size_;
}

template <typename T>
size_t Vector<T>::Capacity() const noexcept {
  return capacity_;
}

template <typename T>
bool Vector<T>::Empty() const noexcept {
  return (size_ == 0);
}

template <typename T>
const T& Vector<T>::operator[](const size_t& ind) const noexcept {
  return ptr_[ind];
}

template <typename T>
T& Vector<T>::operator[](const size_t& ind) noexcept {
  return ptr_[ind];
}

template <typename T>
const T& Vector<T>::At(const size_t& ind) const {
  if (ind < size_) {
    return ptr_[ind];
  }
  throw VectorOutOfRange{};
}

template <typename T>
T& Vector<T>::At(const size_t& ind) {
  if (ind < size_) {
    return ptr_[ind];
  }
  throw VectorOutOfRange{};
}

template <typename T>
const T& Vector<T>::Front() const {
  return ptr_[0];
}

template <typename T>
T& Vector<T>::Front() {
  return ptr_[0];
}

template <typename T>
const T& Vector<T>::Back() const {
  return ptr_[size_ - 1];
}

template <typename T>
T& Vector<T>::Back() {
  return ptr_[size_ - 1];
}

template <typename T>
const T* Vector<T>::Data() const {
  return ptr_;
}

template <typename T>
T* Vector<T>::Data() {
  return ptr_;
}

template <typename T>
void Vector<T>::Swap(Vector<T>& other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(ptr_, other.ptr_);
}

template <typename T>
void Vector<T>::Resize(size_t new_size) {
  if (new_size > capacity_) {
    auto temp = new T[new_size]{};
    for (size_t i = 0; i < size_; ++i) {
      temp[i] = std::move(ptr_[i]);
    }
    delete[] ptr_;
    ptr_ = temp;
    capacity_ = new_size;
  }
  size_ = new_size;
}

template <typename T>
void Vector<T>::Resize(size_t new_size, const T& value) {
  if (new_size > capacity_) {
    auto temp = new T[new_size]{};
    try {
      for (size_t i = size_; i < new_size; ++i) {
        temp[i] = value;
      }
    } catch (...) {
      delete[] temp;
      throw;
    }
    for (size_t i = 0; i < size_; ++i) {
      temp[i] = std::move(ptr_[i]);
    }
    delete[] ptr_;
    ptr_ = temp;
    capacity_ = new_size;
    size_ = new_size;
  } else {
    try {
      for (size_t i = size_; i < new_size; ++i) {
        ptr_[i] = value;
      }
    } catch (...) {
      for (size_t i = size_; i < new_size; ++i) {
        ptr_[i].~T();
      }
      throw;
    }
    size_ = new_size;
  }
}

template <typename T>
void Vector<T>::Reserve(size_t new_cap) {
  size_t t = std::max(capacity_, new_cap);
  if (t != capacity_) {
    auto temp = new T[t]{};
    for (size_t i = 0; i < size_; ++i) {
      temp[i] = std::move(ptr_[i]);
    }
    delete[] ptr_;
    ptr_ = temp;
    capacity_ = t;
  }
}

template <typename T>
void Vector<T>::ShrinkToFit() {
  if (size_ != capacity_) {
    if (size_ != 0) {
      auto temp = new T[size_]{};
      for (size_t i = 0; i < size_; ++i) {
        temp[i] = std::move(ptr_[i]);
      }
      delete[] ptr_;
      ptr_ = temp;
      capacity_ = size_;
    } else {
      delete[] ptr_;
      ptr_ = nullptr;
      capacity_ = 0;
    }
  }
}

template <typename T>
void Vector<T>::Clear() {
  size_ = 0;
}

template <typename T>
void Vector<T>::PushBack(const T& value) {
  if (size_ == capacity_) {
    size_t capacity;
    if (capacity_ == 0) {
      capacity = 1;
    } else {
      capacity = capacity_ * 2;
    }
    auto temp = new T[capacity]{};
    for (size_t i = 0; i < size_; ++i) {
      temp[i] = std::move(ptr_[i]);
    }
    try {
      temp[size_] = value;
    } catch (...) {
      delete[] temp;
      throw;
    }
    delete[] ptr_;
    ptr_ = temp;
    ++size_;
    capacity_ = capacity;
  } else {
    try {
      ptr_[size_] = value;
    } catch (...) {
      ptr_[size_].~T();
      throw;
    }
    ++size_;
  }
}

template <typename T>
void Vector<T>::PushBack(T&& value) {
  if (size_ == capacity_) {
    size_t capacity;
    if (capacity_ == 0) {
      capacity = 1;
    } else {
      capacity = capacity_ * 2;
    }
    auto temp = new T[capacity]{};
    for (size_t i = 0; i < size_; ++i) {
      temp[i] = std::move(ptr_[i]);
    }
    temp[size_] = std::move(value);
    ++size_;
    delete[] ptr_;
    ptr_ = temp;
    capacity_ = capacity;
  } else {
    ptr_[size_] = std::move(value);
    ++size_;
  }
}

template <typename T>
void Vector<T>::PopBack() {
  --size_;
  ptr_[size_].~T();
}

template <typename T>
bool operator<(const Vector<T>& first, const Vector<T>& second) {
  size_t min = std::min(first.size_, second.size_);
  for (size_t i = 0; i < min; ++i) {
    if (first.ptr_[i] != second.ptr_[i]) {
      return first.ptr_[i] < second.ptr_[i];
    }
  }
  return first.size_ < second.size_;
}

template <typename T>
bool operator>(const Vector<T>& first, const Vector<T>& second) {
  size_t min = std::min(first.size_, second.size_);
  for (size_t i = 0; i < min; ++i) {
    if (first.ptr_[i] != second.ptr_[i]) {
      return first.ptr_[i] > second.ptr_[i];
    }
  }
  return first.size_ > second.size_;
}

template <typename T>
bool operator<=(const Vector<T>& first, const Vector<T>& second) {
  return !(first > second);
}

template <typename T>
bool operator>=(const Vector<T>& first, const Vector<T>& second) {
  return !(first < second);
}

template <typename T>
bool operator==(const Vector<T>& first, const Vector<T>& second) {
  if (first.size_ == second.size_) {
    for (size_t i = 0; i < first.size_; ++i) {
      if (first.ptr_[i] != second.ptr_[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <typename T>
bool operator!=(const Vector<T>& first, const Vector<T>& second) {
  return !(first == second);
}
#endif