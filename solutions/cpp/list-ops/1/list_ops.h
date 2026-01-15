#pragma once

#include <functional>
#include <vector>

namespace list_ops {

template<typename T>
void append(std::vector<T>& left, const std::vector<T>& right) {
    for(const auto& e : right) {
        left.emplace_back(e);
    }
}

template<typename T>
std::vector<T> concat(std::vector<std::vector<T>>& input) {
    std::vector<T> result;
    for (const auto& v : input) {
        for(const auto& element : v) {
            result.emplace_back(element);
        }
    }
    return result;
}

template<typename T, typename Pred>
std::vector<T> filter(const std::vector<T>& input, Pred lambda_func) {
    std::vector<T> result;
    std::for_each(input.begin(), input.end(), [&lambda_func, &result](const T& e){
        if (lambda_func(e)) result.emplace_back(e);
    });
    return result;
}

template<typename T>
size_t length(const std::vector<T>& input) {
    return std::distance(input.begin(), input.end());
}


template<typename T, typename Pred>
std::vector<T> map(const std::vector<T>& input, Pred lambda_func) {
    std::vector<T> result(input.size());
    std::transform(input.begin(), input.end(), result.begin(), lambda_func);

    return result;
}

template<typename T, typename Pred>
T foldl(const std::vector<T>& input, const T& init, Pred lambda_func) {
    T result = init;
    for (const auto& e : input) {
        result = lambda_func(result, e);
    }
    return result;
}

template<typename T, typename Pred>
T foldr(const std::vector<T>& input, const T& init, Pred lambda_func) {
    T result = init;

    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        result = lambda_func(result, *it);
    }
    return result;
}

template<typename T>
std::vector<T> reverse(const std::vector<T>& input) {
    std::vector<T> result;

    std::for_each(input.rbegin(), input.rend(), [&result](const T& element){
        result.emplace_back(element);
    });
    
    return result;
}
}  // namespace list_ops
