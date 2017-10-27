/*
 * BitMagic.hpp
 *
 *  Created on: Apr 24, 2015
 *      Author: johnny
 */

#ifndef BITMAGIC_HPP_
#define BITMAGIC_HPP_
#include "ChallengeBase.hpp"
#include <cstdint>

class BitMagic : public ChallengeBase {
  public:
    BitMagic() {}
    void test() override;

    ~BitMagic() {}

  private:
    // LeetCode 190  Reverse Bits  27.8%  Easy
    uint32_t reverseBits(uint32_t n);
    uint32_t swapBits(uint32_t x, uint32_t i, uint32_t j);
    void test190();

    // LeetCode 191  Number of 1 Bits  36.9%  Easy
    int hammingWeight(uint32_t n);
    void test191();
    // LeetCode 201  Bitwise AND of Numbers Range  26.2%  Medium

    // LeetCode 136 Single Number   45.4%   Medium
    int singleNumber(vector<int> &nums);
    void test136();
};

#endif /* BITMAGIC_HPP_ */
