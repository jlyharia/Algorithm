/*
 * BinaryTreeTraversal.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: johnny
 */
#include "TreeQuiz.hpp"

BSTstring *TreeQuiz::getSample() {
    //             a
    //	      b          c
    //   d       e
    //     f   g
    //	 h       i
    BSTstring *i = new BSTstring("i");
    BSTstring *h = new BSTstring("h");
    BSTstring *g = new BSTstring("g", nullptr, i);
    BSTstring *f = new BSTstring("f", h, nullptr);
    BSTstring *e = new BSTstring("e", g, nullptr);
    BSTstring *d = new BSTstring("d", nullptr, f);
    BSTstring *c = new BSTstring("c");
    BSTstring *b = new BSTstring("b", d, e);
    BSTstring *a = new BSTstring("a", b, c);

    return a;
}

BSTint *TreeQuiz::getSampleInt() {
    //             1
    //	      2          3
    //   4       5
    //     6   7
    //	 8       9
    BSTint *i = new BSTint(9);
    BSTint *h = new BSTint(8);
    BSTint *g = new BSTint(7, nullptr, i);
    BSTint *f = new BSTint(6, h, nullptr);
    BSTint *e = new BSTint(5, g, nullptr);
    BSTint *d = new BSTint(4, nullptr, f);
    BSTint *c = new BSTint(3);
    BSTint *b = new BSTint(2, d, e);
    BSTint *a = new BSTint(1, b, c);
    // BSTint *a = new BSTint(1);

    return a;
}

/**
 * LeetCode 226  Invert Binary Tree  37.3%   Easy
 */
BSTstring *TreeQuiz::invertTree(BSTstring *root) {
    if (root != nullptr) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}

void TreeQuiz::test226() {
    cout << "LeetCode 226  Invert Binary Tree  37.3%   Easy" << endl;
    auto root = invertTree(this->getSample());
    this->inorderTranveralRecursive(root);
}

/**
 * LeetCode 230  Kth Smallest Element in a BST  31.2%  Medium
 * Given a binary search tree, write a function kthSmallest to
 * find the kth smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≦ k ≦ BST's total elements.
 */
string TreeQuiz::kthSmallest(BSTstring *root, int k) {
    stack<BSTstring *> stk;
    while (!stk.empty() || root) {
        if (root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            if (--k == 0) { return root->data; }
            root = root->right;
        }
    }
    return 0;
}

void TreeQuiz::test230() {
    cout << "LeetCode 230  Kth Smallest Element in a BST  31.2%  Medium" << endl;

    cout << kthSmallest(this->getSample(), 3) << endl;
}

// 199  Binary Tree Right Side View  28.2%  Medium
vector<string> TreeQuiz::rightSideView(BSTstring *node) {
    int max = 0;
    cout << max << endl;
    tranverse(node, 1, max);
    return result;
}

void TreeQuiz::tranverse(BSTstring *node, int level, int &max) {
    if (!node) return;
    if (max < level) {
        result.push_back(node->data);
        max = level;
    }
    tranverse(node->right, level + 1, max);
    tranverse(node->left, level + 1, max);
}

void TreeQuiz::test199() {
    auto *root = getSample();

    rightSideView(root);
    for (auto &i : this->result) {
        cout << i << " ";
    }
    cout << endl;
}

// LeetCode 103	Binary Tree Zigzag Level Order Traversal	26.6%	Medium
vector<vector<int>> TreeQuiz::zigzagLevelOrder(BSTint *root) {
    vector<vector<int>> ret;
    stack<BSTint *> stk1;
    stack<BSTint *> stk2;
    stk1.push(root);
    vector<int> row;
    bool dir = true;
    while (!stk1.empty() || !stk2.empty()) {
        auto cur = stk1.top();
        stk1.pop();
        if (cur) {
            // cout << cur->data << " ";
            row.push_back(cur->data);
            if (dir) {
                stk2.push(cur->left);
                stk2.push(cur->right);
            } else {
                stk2.push(cur->right);
                stk2.push(cur->left);
            }
        }
        if (stk1.empty()) {
            dir = !dir;
            std::swap(stk1, stk2);
            // cout << endl;
            if (!row.empty()) ret.push_back(row);
            row.clear();
        }
    }
    return ret;
}

void TreeQuiz::test103() {
    cout << "LeetCode 103	Binary Tree Zigzag Level Order Traversal 26.6% Medium" << endl;
    auto sample = this->getSampleInt();
    auto result = zigzagLevelOrder(sample);

    for (auto row : result) {
        for (auto e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> TreeQuiz::levelOrder(TreeNode<int> *root) {
    std::queue<TreeNode<int> *> que = {};
    que.push(root);
    vector<vector<int>> ans;
    vector<int> row;
    int size = que.size();
    while (size != 0) {
        auto front = que.front();
        if (front != nullptr) {
            row.push_back(front->data);
            if (front->left != nullptr) {
                que.push(front->left);
            }
            if (front->right != nullptr) {
                que.push(front->right);
            }
        }

        que.pop();
        size--;
        if (size == 0) {
            size = que.size();
            ans.push_back(row);
            row.clear();
        }
    }

}

void TreeQuiz::test() {
    //    cout << "-- LeetCode 94 Binary Tree Inorder Traversal 36.1% Medium" <<
    //    endl;
    //    auto *root = getSample();
    //    cout << "inorderTranveralRecursive = ";
    //    inorderTranveralRecursive(root);
    //    cout << endl;
    //    cout << "inorderTranveralLoop =      ";
    //    inorderTranveralLoop(root);
    //    cout << endl << endl;
    //
    //    cout << "-- LeetCode 144 Binary Tree Preorder Traversal 36.2% Medium"
    //         << endl;
    //    cout << "preorderTranveralRecursive = ";
    //    preorderTranveralRecursive(root);
    //    cout << endl;
    //
    //    cout << "preorderTranveralLoop =      ";
    //    preorderTranveralLoop(root);
    //    cout << endl << endl;
    //
    //    cout << "-- LeetCode 145 Binary Tree Postorder Traversal 32.1% Hard"
    //         << endl;
    //
    //    cout << "postorderTranveralRecursive = ";
    //    postorderTranveralRecursive(root);
    //    cout << endl;
    //
    //    cout << "postorderTranveralLoop =      ";
    //    postorderTranveralLoop(root);
    //    cout << endl;
    //
    //    test226();
    //
    //    test230();
    // test199();
    test103();
}

void TreeQuiz::preorderTranveralRecursive(BSTstring *node) {

    if (node) {
        cout << node->data << " ";
        preorderTranveralRecursive(node->left);
        preorderTranveralRecursive(node->right);
    }
}

void TreeQuiz::preorderTranveralLoop(BSTstring *node) {
    stack<BSTstring *> st;
    auto current = node;
    while (!st.empty() || current) {
        if (current) {
            cout << current->data << " ";
            if (current->right) st.push(current->right);
            current = current->left;
        } else {
            current = st.top();
            st.pop();
        }
    }
}

void TreeQuiz::inorderTranveralRecursive(BSTstring *node) {
    if (node) {
        inorderTranveralRecursive(node->left);
        cout << node->data << " ";
        inorderTranveralRecursive(node->right);
    }
}

/**
 * consider the current node or consider the next node would result in different
 *algorithm
 * ex: if(current->left)  vs if(current)
 *
 * think carefully that every scenario in recursion need to take into account
 *when implement loop version
 * loop version need to take into account that recursion would go into null
 *node.
 */
void TreeQuiz::inorderTranveralLoop(BSTstring *node) {
    stack<BSTstring *> st;
    auto current = node;
    while (!st.empty() || current) {
        if (current) {
            st.push(current);
            current = current->left;
        } else {
            current = st.top();
            cout << current->data << " ";
            st.pop();
            current = current->right;
        }
    }
}

void TreeQuiz::postorderTranveralRecursive(BSTstring *node) {
    if (node) {
        postorderTranveralRecursive(node->left);
        postorderTranveralRecursive(node->right);
        cout << node->data << " ";
    }
}

/**
 * http://articles.leetcode.com/2010/10/binary-tree-post-order-traversal.html
 */
void TreeQuiz::postorderTranveralLoop(BSTstring *node) {
    stack<BSTstring *> st;
    st.push(node);
    BSTstring *prev = nullptr;
    BSTstring *current;
    while (!st.empty()) {
        current = st.top();
        if (!prev || prev->left == current || prev->right == current) {
            if (current->left)
                st.push(current->left);
            else if (current->right)
                st.push(current->right);
            else {
                cout << current->data << " ";
                st.pop();
            }
        } else if (current->left == prev) {
            if (current->right)
                st.push(current->right);
            else {
                cout << current->data << " ";
                st.pop();
            }
        } else {
            cout << current->data << " ";
            st.pop();
        }
        prev = current;
    }
}

BSTint *TreeQuiz::str2tree(string s) {
    if (s.empty()) return NULL;
    auto found = s.find('(');
    int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
    BSTint *cur = new BSTint(val);
    if (found == string::npos) return cur;
    int start = found, cnt = 0;
    for (int i = start; i < s.size(); ++i) {
        if (s[i] == '(') ++cnt;
        else if (s[i] == ')') --cnt;
        if (cnt == 0 && start == found) {
            cur->left = str2tree(s.substr(start + 1, i - start - 1));
            start = i + 1;
        } else if (cnt == 0) {
            cur->right = str2tree(s.substr(start + 1, i - start - 1));
        }
    }
    return cur;
}