#include "opencv2/core.hpp"

using namespace cv;

class BinarySearchTreeNode {
public:
    int key;
    int cont;
    Mat image; // Imagen de tamano 25x25
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
};