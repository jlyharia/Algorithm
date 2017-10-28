/*
 * BitMagic.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: johnny
 */

#include "BitMagic.hpp"
#include <bitset>
/**
 * Reverse bits of a given 32 bits unsigned integer.
 * For example, given input 43261596 (represented in binary as
 *00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 *
 * If this function is called many times, how would you optimize it?
 */
uint32_t BitMagic::reverseBits(uint32_t n) {
    auto length = sizeof(n) * 8;

    auto end = length / 2;
    for (auto i = 0; i < end; i++) {
        n = swapBits(n, i, length - i - 1);
    }
    return n;
}

uint32_t BitMagic::swapBits(uint32_t n, uint32_t i, uint32_t j) {
    auto right = n >> i & 1;
    auto left = n >> j & 1;

    if (right ^ left) {
        // right != left
        n = n ^ (1U << i | 1U << j);
    }
    return n;
}
void BitMagic::test190() {
    cout << "LeetCode 190  Reverse Bits  27.8%  Easy" << endl;
    auto n = 11;
    cout << "input  = " << bitset<32>(n) << "\n";
    cout << "output = " << bitset<32>(reverseBits(n)) << endl;
    n = 9998;
    cout << "input  = " << bitset<32>(n) << "\n";
    cout << "output = " << bitset<32>(reverseBits(n)) << endl;
}
/**
 * LeetCode 191  Number of 1 Bits  36.9%  Easy
 */
int BitMagic::hammingWeight(uint32_t n) {
    int c = 0;
    while (n != 0) {
        n = n & (n - 1);
        c++;
    }
    return c;
}
void BitMagic::test191() {
    cout << "LeetCode 191  Number of 1 Bits  36.9%  Easy" << endl;
    auto count = hammingWeight(5);
    cout << count << endl;
}

/**
LeetCode 136 Single Number   45.4%   Medium
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra
memory?
*/
int BitMagic::singleNumber(vector<int> &nums) {

    auto ret = nums[0];
    for (auto i = 1; i < nums.size(); ++i) {
        ret = ret xor nums[i];
    }
    return ret;
}
void BitMagic::test136() {
    cout << "LeetCode 136 Single Number   45.4%   Medium" << endl;
    std::vector<int> nums = {2, 3, 4, 1, 3, 2, 4};
    for (const auto &i : nums)
        cout << i << ' ';

    cout << endl;
    cout << singleNumber(nums) << endl;
}
void BitMagic::test() {
    // test190();
    // test191();
    test136();
}
