#include <iostream>
#include "BinarySearchTree.hpp"
#include "BinarySearchTreeNode.hpp"
using namespace std;

void BinarySearchTree::insertI(Mat img){
    root = insertI(root , img);
}

void BinarySearchTree::insertV(Mat img) {
    root = insertV(root, img);
}

double BinarySearchTree::euclideanDistance(Mat img1, Mat img2) {
    return norm(img1, img2, NORM_L2);
}

BinarySearchTreeNode* BinarySearchTree::insertI(BinarySearchTreeNode * node, Mat image){
    if (node == nullptr) {
        node = new BinarySearchTreeNode();
        node->key = ++counter;
        node->image = image;
        node->left = nullptr;
        node->right = nullptr;

        cout << "ID: " << node->key << endl;
        return node;
    }

    else if(SIMILARi < euclideanDistance(node -> image, image) && DIFFERENTi > euclideanDistance(node->image, image)){
        node -> left = insertI(node -> left, image);
    }
    else if (DIFFERENTi <= euclideanDistance(node->image, image)) {
        node->right = insertI(node->right, image);
    }
    else{ // Cuando la distancia entre dos cuerpos es menor a lo permitido (son iguales)
        node -> cont++; // Se cambia la imagen por la nueva
    }
    return node;
}

BinarySearchTreeNode * BinarySearchTree::insertV(BinarySearchTreeNode* node, Mat image){
    // Tolerancia para considerar si una imagen es igual
    // si el arbol no tiene hijos
    if(node == nullptr){
        node = new BinarySearchTreeNode();
        node -> key = ++counter;
        node->image = image;
        node -> left = nullptr;
        node -> right = nullptr;

        cout << "ID: " << node->key << endl;
        return node;
    }
    else if (SIMILARv < euclideanDistance(node->image, image)
        && DIFFERENTv > euclideanDistance(node->image, image)) {
        node->left = insertV(node->left, image);
    }
    else if (DIFFERENTv <= euclideanDistance(node->image, image)) {
        node->right = insertV(node->right, image);
    }
    else{ // Cuando la distancia entre dos cuerpos es menor a lo permitido (son iguales)
        node->cont++; // Se cambia la imagen por la nueva
    }
    cout << "Distancia euclidea: " << euclideanDistance(node->image, image) << endl;
    return node;
}