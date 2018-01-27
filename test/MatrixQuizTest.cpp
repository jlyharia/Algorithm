//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"

using namespace std;

template<typename BidirIt>
bool next_per(BidirIt first, BidirIt last) {
	if (first == last) {
		return false;
	}
	BidirIt i = last;
	if (first == --i) {
		return false;
	}
	// i  = last
	while (true) {
		BidirIt i1, i2;

		i1 = i;
		auto t = *--i;
		auto s = *i1;
//		if (*--i < *i1) {
		if (t < s) { // non increasing suffix
			i2 = last;
//			while (!(*i < *--i2)){
			while (*i >= *--i2){
//				cout<< *i2<<endl;
			}
			std::iter_swap(i, i2);
			std::reverse(i1, last);
			return true;
		}
		if (i == first) { // become non-increasing order then reverse back before break
			std::reverse(first, last);
			return false;
		}
	}
}

int isEven() {
	return 2;
}

TEST (SquareRootTest, PositiveNos) {
//	EXPECT_EQ (3, isEven());

	std::string s = "abc";
//	std::sort(s.begin(), s.end());
	cout<<'\n';
	do {
		std::cout << s << '\n';
	} while (next_per(s.begin(), s.end()));

//	vector<vector<int> > matrix = {{1,  3,  5,  7},
//								   {10, 11, 16, 20},
//								   {23, 30, 34, 50}};
//
//	MatrixQuiz mxQ;
//	mxQ.test();
//	cout << searchMatrix(matrix, 50) << endl;
}