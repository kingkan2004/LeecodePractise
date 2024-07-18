#include <iostream>

using namespace std;
// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int firstData = 0;
        int secondData = 0;
        int carry = 0; // 进位

        // 初始化：创建一个新的链表用于存储结果，以及一个变量用于跟踪进位值
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        // 遍历链表：同时遍历两个输入链表，从头结点开始，直到两个链表都遍历完毕。
        while (l1 != nullptr || l2 != nullptr) {
            // 获取当前节点的值，如果节点为空则取0
            firstData = l1 == nullptr ? 0 : l1->val;
            secondData = l2 == nullptr ? 0 : l2->val;

            // 逐位相加：对于每一对对应的节点，将它们的值相加，再加上之前的进位值。
            sum = firstData + secondData + carry;
            carry = sum > 9 ? 1 : 0; // 更新进位：计算当前位的进位，并更新进位变量。
            sum %= 10; // 取余，保证为0~9
            cur->next = new ListNode(sum);
            cur = cur->next;

            // 移动到下一个节点
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }

        // 处理最后的进位：如果最后还有进位（进位值为1），需要在结果链表的末尾添加一个额外的节点来表示进位。
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }

        // 返回结果：返回构建好的结果链表，即表示两个数相加的链表形式。
        return head->next;
    }
};

// 测试函数，用于打印链表
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
        cout << std::endl;
}

int main() {
    // 创建测试用例链表
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // 创建解决方案对象
    Solution solution;

    // 计算两数相加的结果链表
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // 打印结果链表
    printList(result);

    // 清理内存
    delete l1;
    delete l2;

    ListNode* tmp;
    while (result) {
        tmp = result;
        result = result->next;
        delete tmp;
    }

    return 0;
}
