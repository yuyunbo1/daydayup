#ifndef _LIST_H_
#define _LIST_H_
/**用这一条宏定义可以很好的组织链表，可以不管用户定义的结构是啥样的，都可以用这些接口，这里暂时没有使用pre*/
typedef struct TagListNode {
    struct TagListNode* pre;
    struct TagListNode* next;
}ListNode;
/**1.
    用户界面声明创建了一个名为oneList的空链表操作如下
    ListNode* userList = NULL;
    ListCreate(userList);
*/
#define ListCreate(head)                                    \
{                                                           \
    head = (ListNode*)calloc(1, sizeof(ListNode));          \
    head->next = NULL;                                      \
    head->pre = NULL;                                       \
}
/**2.添加
    用户界面在头节点后增加节点
    ListAddTohead(userList, &Type.listNode)
*/
#define ListAddTohead(head, add)                            \
{                                                           \
    ListNode* _temp = NULL;                                  \
    _temp = head->next;                                      \
    head->next = (add);                                     \
    (add)->next = _temp;                                     \
}
/**3.查找
    ListNode* res = NULL;
    ListFind(head, targetNode, res);
    上层判断res是否是NULL,来判断节点是否在链表中
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
/**4.删除
    用户界面删除节点
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
/**5.遍历
    用户界面想要遍历可以通过这个方式
    ListNode* curPos;
    ListForEach(head, curPos) {
        //对curPos即可操作
    }
*/
#define ListForEach(head, curPos)  for (curPos = head->next; curPos != NULL; curPos = curPos->next)
/**6.
    用户界面获取curPos所在的结构体的入口
    成员地址 - 成员在结构体中的偏移
    type* temp;
    temp = ListGetEntry(memberAddr, type, member);
    ANSI C标准允许任何值为0的常量被强制转换成任何一种类型的指针，并且转换结果是一个NULL指针，因此((s*)0)的结果就是一个类型为s*的NULL指针。
    如果利用这个NULL指针来访问s的成员当然是非法的，但&(((s*)0)->m)的意图并非想存取s字段内容，而仅仅是计算当结构体实例的首址为((s*)0)时m字段的地址。
    聪明的编译器根本就不生成访问m的代码，而仅仅是根据s的内存布局和结构体实例首址在编译期计算这个(常量)地址，这样就完全避免了通过NULL指针访问内存的问题。
*/
#define ListGetEntry(memberAddr, type, member)  (type*)((char*)memberAddr - (char*)(&(((type*)0)->member)))

#endif // _LIST_H_
