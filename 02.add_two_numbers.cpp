#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        int sum = l1->val + l2->val;
        ListNode *node = new ListNode(sum % 10);
        node->next = addTwoNumbers(l1->next, l2->next);
        if (sum >= 10)
            node->next = addTwoNumbers(node->next, new ListNode(1));
        return node;

    }

    ListNode * linkCreate(const vector<int> nums) {
        ListNode *head =  new ListNode(-1);
        ListNode *tmp = head;
        for (int i=0; i<nums.size(); i++) {
            ListNode *cur = new ListNode(nums[i]);
            tmp->next = cur;
            tmp = cur;
        }
        return head->next;
    }

    void linkPrint(ListNode* s) {
        if (s == nullptr) {
            cout << "link is null" << endl;
        }
        while (s) {
            cout << s->val << "->";
            s = s->next;
        }
        cout << endl;
    }
};

int main(void) {

    Solution *s = new Solution();
    vector<int> l1_nums = {2,4,3};
    vector<int> l2_nums = {5,6,4};

    ListNode *l1 = s->linkCreate(l1_nums);
    ListNode *l2 = s->linkCreate(l2_nums);

    s->linkPrint(l1);
    s->linkPrint(l2);

    ListNode *res;
    res = s->addTwoNumbers(l1, l2);

    s->linkPrint(res);

    return 0;
}