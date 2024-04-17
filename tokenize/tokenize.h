#ifndef TOKENIZE_H_
#define TOKENIZE_H_

#include <iostream>
#include <variant>
#include <vector>
#include <string>

struct PlusToken {
  bool operator==(const PlusToken&) const;
};

struct MinusToken {
  bool operator==(const MinusToken&) const;
};

struct MultiplyToken {
  bool operator==(const MultiplyToken&) const;
};

struct DivideToken {
  bool operator==(const DivideToken&) const;
};

struct ResidualToken {
  bool operator==(const ResidualToken&) const;
};

struct OpeningBracketToken {
  bool operator==(const OpeningBracketToken&) const;
};

struct ClosingBracketToken {
  bool operator==(const ClosingBracketToken&) const;
};

struct SqrToken {
  bool operator==(const SqrToken&) const;
};

struct MaxToken {
  bool operator==(const MaxToken&) const;
};

struct MinToken {
  bool operator==(const MinToken&) const;
};

struct AbsToken {
  bool operator==(const AbsToken&) const;
};

struct NumberToken {
  int value;
  bool operator==(const NumberToken& nt) const;
  explicit NumberToken(const int& value);
};

struct UnknownToken {
  std::string value;
  bool operator==(const UnknownToken& ut) const;
  explicit UnknownToken(const std::string& value);
};

using Token = std::variant<PlusToken, MinusToken, MultiplyToken, DivideToken, ResidualToken, OpeningBracketToken,
                           ClosingBracketToken, SqrToken, MaxToken, MinToken, AbsToken, NumberToken, UnknownToken>;

std::vector<Token> Tokenize(const std::string_view& old);

#endif