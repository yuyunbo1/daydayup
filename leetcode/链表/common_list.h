#ifndef _LIST_H_
#define _LIST_H_
/**����һ���궨����Ժܺõ���֯�������Բ����û�����Ľṹ��ɶ���ģ�����������Щ�ӿڣ�������ʱû��ʹ��pre*/
typedef struct TagListNode {
    struct TagListNode* pre;
    struct TagListNode* next;
}ListNode;
/**1.
    �û���������������һ����ΪoneList�Ŀ������������
    ListNode* userList = NULL;
    ListCreate(userList);
*/
#define ListCreate(head)                                    \
{                                                           \
    head = (ListNode*)calloc(1, sizeof(ListNode));          \
    head->next = NULL;                                      \
    head->pre = NULL;                                       \
}
/**2.���
    �û�������ͷ�ڵ�����ӽڵ�
    ListAddTohead(userList, &Type.listNode)
*/
#define ListAddTohead(head, add)                            \
{                                                           \
    ListNode* _temp = NULL;                                  \
    _temp = head->next;                                      \
    head->next = (add);                                     \
    (add)->next = _temp;                                     \
}
/**3.����
    ListNode* res = NULL;
    ListFind(head, targetNode, res);
    �ϲ��ж�res�Ƿ���NULL,���жϽڵ��Ƿ���������
*/
#define ListFind(head, _target, _res)         \
{                                           \
     ListNode* _temp = head;                \
     ListNode* _last = _temp;               \
     while (_temp != NULL) {                \
        if (_temp == _target) {              \
            _res = _target;                   \
            break;                          \
        }                                   \
        _last = _temp;                      \
        _temp = _temp->next;                \
     }                                      \
}
/**4.ɾ��
    �û�����ɾ���ڵ�
*/
#define ListDelOneNode(head, _del)                           \
{                                                           \
    ListNode* _temp = head;                            \
    ListNode* _last = _temp;                                \
    while (_temp != NULL) {                  \
        if (_temp == (_del)) {                                  \
            break;                                          \
        }                                                   \
        _last = _temp;                                        \
        _temp = _temp->next;                                 \
    }                                                       \
    _last->next = (_del)->next;                                \
}
/**5.����
    �û�������Ҫ��������ͨ�������ʽ
    ListNode* curPos;
    ListForEach(head, curPos) {
        //��curPos���ɲ���
    }
*/
#define ListForEach(head, curPos)  for (curPos = head->next; curPos != NULL; curPos = curPos->next)
/**6.
    �û������ȡcurPos���ڵĽṹ������
    ��Ա��ַ - ��Ա�ڽṹ���е�ƫ��
    type* temp;
    temp = ListGetEntry(memberAddr, type, member);
    ANSI C��׼�����κ�ֵΪ0�ĳ�����ǿ��ת�����κ�һ�����͵�ָ�룬����ת�������һ��NULLָ�룬���((s*)0)�Ľ������һ������Ϊs*��NULLָ�롣
    ����������NULLָ��������s�ĳ�Ա��Ȼ�ǷǷ��ģ���&(((s*)0)->m)����ͼ�������ȡs�ֶ����ݣ��������Ǽ��㵱�ṹ��ʵ������ַΪ((s*)0)ʱm�ֶεĵ�ַ��
    �����ı����������Ͳ����ɷ���m�Ĵ��룬�������Ǹ���s���ڴ沼�ֺͽṹ��ʵ����ַ�ڱ����ڼ������(����)��ַ����������ȫ������ͨ��NULLָ������ڴ�����⡣
*/
#define ListGetEntry(memberAddr, type, member)  (type*)((char*)memberAddr - (char*)(&(((type*)0)->member)))

#endif // _LIST_H_
