#ifndef REVERSED_H_
#define REVERSED_H_
#define REVERSE_REVERSED_IMPLEMENTED

template <class Container>
class Reversed {
  Container& container_;

 public:
  explicit Reversed(Container& container) : container_(container) {
  }
  auto begin() const {  // NOLINT
    return container_.rbegin();
  }
  auto begin() {  // NOLINT
    return container_.rbegin();
  }
  auto end() const {  // NOLINT
    return container_.rend();
  }
  auto end() {  // NOLINT
    return container_.rend();
  }
  auto rbegin() const {  // NOLINT
    return container_.begin();
  }
  auto rbegin() {  // NOLINT
    return container_.begin();
  }
  auto rend() const {  // NOLINT
    return container_.end();
  }
  auto rend() {  // NOLINT
    return container_.end();
  }
};
#endif