#include <iostream>

using namespace std;

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для видалення дублікатів з відсортованого списку
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        }
        else {
            current = current->next;
        }
    }

    return head;
}

// Функція для виводу списку
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Приклад 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);

    cout << "Original List 1: ";
    printList(head1);

    head1 = deleteDuplicates(head1);

    cout << "List 1 after removing duplicates: ";
    printList(head1);

    // Приклад 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);

    cout << "Original List 2: ";
    printList(head2);

    head2 = deleteDuplicates(head2);

    cout << "List 2 after removing duplicates: ";
    printList(head2);

    return 0;
}
