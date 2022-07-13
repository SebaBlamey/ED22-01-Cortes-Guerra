#include <opencv2/core.hpp>

using namespace cv;

class BinarySearchTree
{
private:
    const int DIFFERENTi = 12000;
    const int SIMILARi = 10000;
    const int DIFFERENTv = 8000;
    const int SIMILARv = 6000;

    // Contador para asignar identificadores a las caras
    int counter;
    struct BinarySearchTreeNode* root;
    BinarySearchTreeNode* insertI(BinarySearchTreeNode* node, Mat);
    BinarySearchTreeNode* insertV(BinarySearchTreeNode* node, Mat);
    double euclideanDistance(Mat, Mat);

public:
    BinarySearchTree(){
        counter = 0;
        root = nullptr;
    }

    void insertI(Mat);
    void insertV(Mat);
};