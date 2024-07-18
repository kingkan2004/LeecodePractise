#include <iostream>

using namespace std;
// ��������ڵ�ṹ��
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
        int carry = 0; // ��λ

        // ��ʼ��������һ���µ��������ڴ洢������Լ�һ���������ڸ��ٽ�λֵ
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        // ��������ͬʱ������������������ͷ��㿪ʼ��ֱ����������������ϡ�
        while (l1 != nullptr || l2 != nullptr) {
            // ��ȡ��ǰ�ڵ��ֵ������ڵ�Ϊ����ȡ0
            firstData = l1 == nullptr ? 0 : l1->val;
            secondData = l2 == nullptr ? 0 : l2->val;

            // ��λ��ӣ�����ÿһ�Զ�Ӧ�Ľڵ㣬�����ǵ�ֵ��ӣ��ټ���֮ǰ�Ľ�λֵ��
            sum = firstData + secondData + carry;
            carry = sum > 9 ? 1 : 0; // ���½�λ�����㵱ǰλ�Ľ�λ�������½�λ������
            sum %= 10; // ȡ�࣬��֤Ϊ0~9
            cur->next = new ListNode(sum);
            cur = cur->next;

            // �ƶ�����һ���ڵ�
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }

        // �������Ľ�λ���������н�λ����λֵΪ1������Ҫ�ڽ�������ĩβ���һ������Ľڵ�����ʾ��λ��
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }

        // ���ؽ�������ع����õĽ����������ʾ��������ӵ�������ʽ��
        return head->next;
    }
};

// ���Ժ��������ڴ�ӡ����
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
        cout << std::endl;
}

int main() {
    // ����������������
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // ���������������
    Solution solution;

    // ����������ӵĽ������
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // ��ӡ�������
    printList(result);

    // �����ڴ�
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
