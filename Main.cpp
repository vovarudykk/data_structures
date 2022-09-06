// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "SinglyList.h"
#include "DoublyList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"

#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#include <memory>
#include "SortMethods.h"
#include "AVLTree.h"
#include "SearchMethods.h"

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
//static std::string ch_hor = "\u2500" /*─*/, ch_ver = "\u2502" /*│*/, ch_ddia = "\u250C" /*┌*/, ch_rddia = "\u2510" /*┐*/, ch_udia = "\u2514" /*└*/, ch_ver_hor = "\u251C\u2500" /*├─*/, ch_udia_hor = "\u2514\u2500" /*└─*/, ch_ddia_hor = "\u250C\u2500" /*┌─*/, ch_ver_spa = "\u2502 " /*│ */;

using namespace std;

void dump4(BinaryTree::Node const* node, bool high = true, std::vector<std::string> const& lpref = std::vector<std::string>(), std::vector<std::string> const& cpref = std::vector<std::string>(), std::vector<std::string> const& rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr) {
    if (!node) return;
    typedef std::vector<std::string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = std::make_shared<std::vector<VS>>();
    if (node->left)
        dump4(node->left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })), VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), false, true, lines);
    auto sval = std::to_string(node->data);
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i)
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { std::string(1, sval[i]) }));
    if (node->right)
        dump4(node->right, high, VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);
    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            std::string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                }
                else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            std::cout << out[i] << std::endl;
    }
};

void dump5(AVLTree::Node const* node, bool high = true, std::vector<std::string> const& lpref = std::vector<std::string>(), std::vector<std::string> const& cpref = std::vector<std::string>(), std::vector<std::string> const& rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr) {
    if (!node) return;
    typedef std::vector<std::string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = std::make_shared<std::vector<VS>>();
    if (node->left)
        dump5(node->left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })), VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), false, true, lines);
    auto sval = std::to_string(node->data);
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i)
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { std::string(1, sval[i]) }));
    if (node->right)
        dump5(node->right, high, VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);
    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            std::string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                }
                else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            std::cout << out[i] << std::endl;
    }
};


int main() {

    //=========================================================
    // Test call Doubly and Singly Lists
    //=========================================================

    //SinglyList<int> linear_lst;

    //DoublyList<int> doubly_lst;

    //doubly_lst.push_back(12);
    //doubly_lst.push_back(3);
    //doubly_lst.push_back(54);
    //doubly_lst.push_back(100);


    //for (int i = 0; i < doubly_lst.GetSize(); i++) {
    //    cout << doubly_lst[i] << endl;
    //}

    //=========================================================
    // Test call Stack
    //=========================================================

    //Stack<int> stack;
    //stack.push(4);
    //stack.push(8);
    //stack.push(15);
    //stack.push(16);
    //stack.push(22);
    //stack.pop();
    //stack.push(23);
    //stack.push(42);

    //for (int i = 0; i < stack.getSize()-1; i++) {
    //    cout << stack[i] << endl;
    //}

    //=========================================================
    // Test call Queue
    //=========================================================

    //Queue<int> queue;
    //queue.push(123456);
    //queue.push(4);
    //queue.push(8);
    //queue.push(15);
    //queue.push(16);
    //queue.pop();
    //queue.push(23);
    //queue.push(42);

    //queue.print();

    //=========================================================
    // Test call Binary tree 
    //=========================================================


    //BinaryTree tree;
    //tree.add(4);
    //tree.add(15);
    //tree.add(8);
    //tree.add(15);
    //tree.add(16);
    //tree.add(42);
    //tree.add(23);
    //tree.add(100);
    //tree.add(200);

    //dump4(tree.root);

    //tree.deleteNode(100);

    //dump4(tree.root);

    //tree.search(5);
    //tree.search(42);
    //tree.search(15);
    //tree.search(1);


    //=========================================================
    // Test call Array Sort Methods 
    //=========================================================


    //int n;
    //cout << "Enter array`s size:" << endl;
    //cin >> n;

    //int *arr = new int[n];
    //int max = 10;
    //int min = -10;
    //
    //cout << "Generate random numbers..." << endl;
    //SortMethods<int>::generateRandomNumbers(arr, n, max, min);
    //cout << endl;

    //cout << "Sorting by selection..." << endl;
    //SortMethods<int>::Selection(arr, n);
    //SortMethods<int>::printConsole(arr, n);
    //cout << endl;

    //SortMethods<int>::generateRandomNumbers(arr, n, max, min);
    //cout << "Sorting by insertion..." << endl;
    //SortMethods<int>::Insertion(arr, n);
    //SortMethods<int>::printConsole(arr, n);
    //cout << endl;
    //
    //SortMethods<int>::generateRandomNumbers(arr, n, max, min);
    //cout << "Sorting by bubble..." << endl;
    //SortMethods<int>::Bubble(arr, n);
    //SortMethods<int>::printConsole(arr, n);
    //cout << endl;

    //SortMethods<int>::generateRandomNumbers(arr, n, max, min);
    //cout << "Sorting by Shaker..." << endl;
    //SortMethods<int>::Shaker(arr, n);
    //SortMethods<int>::printConsole(arr, n);
    //cout << endl;

    //SortMethods<int>::generateRandomNumbers(arr, n, max, min);
    //cout << "Sorting by Shell..." << endl;
    //SortMethods<int>::Shell(arr, n);
    //SortMethods<int>::printConsole(arr, n);
    //cout << endl;

    //SortMethods<int>::generateRandomNumbers(arr, n, max, min);
    //cout << "Sorting by QuickSort..." << endl;
    //SortMethods<int>::startQuickSort(arr, n);
    //SortMethods<int>::printConsole(arr, n);
    //cout << endl;


    //cout << SearchMethods::binarySearch(arr, 0, n-1, arr[2]) << endl;
    //cout << SearchMethods::binarySearch(arr, 0, n - 1, 25) << endl;


    //string s = "fjweiofjweiofjweiojweopdj32pojdjpo4jripjd2p";
    //cout << "Sorting string..." << endl;
    //SortMethods<int>::sortString(s, s.length());
    //cout << endl;

    //delete [] arr;

    //=========================================================
    // Test call AVL Tree 
    //=========================================================

    //int numbers[8] {5, 4, 1, -10, 10, 2, 6, 12};

    //AVLTree avl_tree;
    //AVLTree::Node* root;
    //root = nullptr;

    //for (int i = 0; i < 8; i++) {
    //    dump5(root);
    //    cout << i+1 << ". Add " << numbers[i] << endl;
    //    avl_tree.insert(root, numbers[i]);
    //    cout << endl;
    //}

    //cout << "final" << endl;
    //dump5(root);
    //cout << endl;

    //avl_tree.deleteNode(root, 10);
    //cout << "delete element" << endl;
    //dump5(root);
    //cout << endl;

    //cout << "Breadth traversal" << endl;
    //avl_tree.BreadthFirstSearch(root);
    //cout << endl;

    //cout << "Depth traversal (preorder)" << endl;
    //avl_tree.DFT_Preorder(root);
    //cout << endl;

    //cout << "Depth traversal (inorder)" << endl;
    //avl_tree.DFT_Inorder(root);
    //cout << endl;

    //cout << "Depth traversal (postorder)" << endl;
    //avl_tree.DFT_Postorder(root);
    //cout << endl;


    return 0;
}