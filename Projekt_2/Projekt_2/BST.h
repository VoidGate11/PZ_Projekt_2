
#ifndef BST_H
#define BST_H

#include "Node.h"
#include <vector>
#include <string>

class BST {
private:
    Node* root;


    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    Node* search(Node* node, int value);
    void clear(Node* node);

    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);

    void printTree(Node* node, int space);
    void saveText(Node* node, std::string& output);

    void saveBinary(Node* node, std::vector<int>& values);

public:
    BST();
    ~BST();

    void add(int value);
    void remove(int value);
    void clearTree();

    bool searchPath(int value);

    void displayPreorder();
    void displayInorder();
    void displayPostorder();

    void displayTree();

    void saveToTextFile(const std::string& filename);
    void loadFromValues(const std::vector<int>& values);

    void saveToBinaryFile(const std::string& filename);
    void loadFromBinaryFile(const std::string& filename);
};

#endif
