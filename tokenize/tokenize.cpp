#include "tokenize.h"

bool PlusToken::operator==(const PlusToken&) const {
  return true;
}

bool MinusToken::operator==(const MinusToken&) const {
  return true;
}

bool MultiplyToken::operator==(const MultiplyToken&) const {
  return true;
}

bool DivideToken::operator==(const DivideToken&) const {
  return true;
}

bool ResidualToken::operator==(const ResidualToken&) const {
  return true;
}

bool OpeningBracketToken::operator==(const OpeningBracketToken&) const {
  return true;
}

bool ClosingBracketToken::operator==(const ClosingBracketToken&) const {
  return true;
}

bool SqrToken::operator==(const SqrToken&) const {
  return true;
}

bool MaxToken::operator==(const MaxToken&) const {
  return true;
}

bool MinToken::operator==(const MinToken&) const {
  return true;
}

bool AbsToken::operator==(const AbsToken&) const {
  return true;
}

NumberToken::NumberToken(const int& value) : value(value) {
}

bool NumberToken::operator==(const NumberToken& nt) const {
  return (value == nt.value);
}

UnknownToken::UnknownToken(const std::string& value) : value(value) {
}

bool UnknownToken::operator==(const UnknownToken& ut) const {
  return (value == ut.value);
}

std::vector<Token> Tokenize(const std::string_view& old) {
  std::vector<Token> vk;
  std::string temp;
  int k = 0;
  for (size_t i = 0; i < old.size(); ++i) {
    if (old[i] != ' ' and (i != old.size() - 1)) {
      temp.push_back(old[i]);
      k = 0;
    } else {
      if ((i == old.size() - 1) and old[i] != ' ') {
        temp.push_back(old[i]);
      }
      k += 1;
      if (k == 1 and (!temp.empty())) {
        if (temp == "+") {
          vk.emplace_back(PlusToken());
        } else if (temp == "-") {
          vk.emplace_back(MinusToken());
        } else if (temp == "*") {
          vk.emplace_back(MultiplyToken());
        } else if (temp == "/") {
          vk.emplace_back(DivideToken());
        } else if (temp == "%") {
          vk.emplace_back(ResidualToken());
        } else if (temp == "(") {
          vk.emplace_back(OpeningBracketToken());
        } else if (temp == ")") {
          vk.emplace_back(ClosingBracketToken());
        } else if (temp == "sqr") {
          vk.emplace_back(SqrToken());
        } else if (temp == "max") {
          vk.emplace_back(MaxToken());
        } else if (temp == "min") {
          vk.emplace_back(MinToken());
        } else if (temp == "abs") {
          vk.emplace_back(AbsToken());
        } else {
          int t = 0;
          if (temp[0] == '-' or temp[0] == '+' or ('0' <= temp[0] and temp[0] <= '9')) {
            for (size_t i = 1; i < temp.size(); ++i) {
              if (!('0' <= temp[i] and temp[i] <= '9')) {
                t = 1;
                break;
              }
            }
          } else {
            t = 1;
          }
          if (t == 0) {
            vk.emplace_back(NumberToken(std::stoi(temp)));
          } else {
            vk.emplace_back(UnknownToken(temp));
          }
        }
        temp = std::string();
      }
    }
  }
  return vk;
}