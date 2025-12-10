#pragma once

#include <string>
#include <iostream>

namespace phone_number {

class phone_number {
public:
    // NXX NXX-XXXX
    // N [2-9]
    // X [0-9]
    phone_number(const std::string& s) {
        for (const auto& c : s) {
            if (std::isdigit(c)) {
                phone += c;
            }
        }
        auto length = phone.length();
        if (length < 10 || length > 11) throw std::domain_error("");
        if (length == 11 && phone[0] != '1') throw std::domain_error("");
        if (phone[length - 10] - '0' < 2) throw std::domain_error("");
        if (phone[length - 7] - '0' < 2) throw std::domain_error("");
        phone = phone.substr(length - 10, length);
    }
    std::string number() {
        return phone;
    }
protected:
    std::string phone;
};

}  // namespace phone_number
