/**
 * @file Node.h
 * @brief Definicja wezla drzewa BST.
 */

#ifndef NODE_H
#define NODE_H

 /**
  * @brief Struktura reprezentujaca pojedynczy wezel drzewa.
  */
struct Node {
    int value;      ///< Wartosc wezla.
    Node* left;     ///< Lewe dziecko.
    Node* right;    ///< Prawe dziecko.

    /**
     * @brief Konstruktor wezla.
     * @param val Wartosc wezla.
     */
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

#endif