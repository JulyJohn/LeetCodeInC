//
// Created by yzjhh on 2019/4/10.
//
/**
 *
 * 二叉搜索树的后序遍历序列
 *
 * 题目描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。假设输入的数组的任意两个数字都互不相同。
 *
 * 如：层次遍历为 1 2 3 4 5 6 7，那么后序遍历为 4 5 2 6 7 3 1
 *
 * note：后序遍历，根节点一定在最后，找到根节点后，就可以将树分为左右两棵子树，其中左子树中的元素都小于根节点，右子树中的元素都大于根节点
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return true;
        }
        helper(sequence, 0, sequence.size() - 1);
    }

    bool helper(vector<int> &sequence, int first, int last) { // first和last表示树序列的开始和结束的位置
        if(first >= last){
            return true;
        }
        int curIdx = first;
        int rootVal = sequence[last]; // 后序遍历，根节点一定在最后，找到根节点后，就可以将树分为左右两棵子树，其中左子树中的元素都小于根节点，右子树中的元素都大于根节点
        while(curIdx < last && sequence[curIdx] < rootVal){
            ++curIdx;
        }
        int midIdx = curIdx; // 到curIdx的值大于根节点时，我们认为开始进入到右子树部分，用一个midIdx记录下当前的右子树开始的位置
        while (curIdx < last){
            if(sequence[curIdx] < rootVal){
                return false;
            }
            ++curIdx;
        }
        return helper(sequence, first, midIdx - 1) && helper(sequence, midIdx, last - 1);
    }
};

int main() {

    return 0;
}
