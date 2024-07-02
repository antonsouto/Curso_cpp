#include <gtest/gtest.h>
#include "../binaryTree.h"

TEST(BinaryTreeTest, InsertAndInOrderTraversal) {
    P_Node root = nullptr;
    root = Push(root, 5);
    root = Push(root, 3);
    root = Push(root, 7);
    root = Push(root, 2);
    root = Push(root, 4);
    root = Push(root, 6);
    root = Push(root, 8);

    testing::internal::CaptureStdout();
    InOrderTraversal(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 3 4 5 6 7 8 ");
}
