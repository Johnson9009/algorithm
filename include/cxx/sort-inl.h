// Copyright (c) 2016 Johnson9009. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files(the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef CXX_SORT_INL_H_
#define CXX_SORT_INL_H_

#include <cstdint>

template <typename RandomAccessIterator>
std::uint64_t partition(RandomAccessIterator first, std::uint64_t count) {
  auto pivot_value = first[count - 1];

  std::uint64_t l = 0; std::uint64_t r = count - 1;
  while (l != r) {
    while ((first[l] <= pivot_value) && (l < r)) {
      ++l;
    }

    if (l < r) {
      first[r] = first[l];
      --r;
    }

    while ((first[r] >= pivot_value) && (r > l)) {
      --r;
    }

    if (r > l) {
      first[l] = first[r];
      ++l;
    }
  }

  first[l] = pivot_value;
  return l;
}

#endif  // CXX_SORT_INL_H_
