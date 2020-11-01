/*一般的表达式称为中缀表达式，及操作符在中间，如a+b,逆波兰表达式也叫后缀表达式，如a b + .

基本思想:
遍历后缀表达式，将碰到的数字字符入栈，每次碰到操作符都将弹出2个操作数进行运算将结果压入栈中。最后将栈中元素弹出即为结果。知得注意的是当碰到操作符“-”或者“/”时，后出栈的操作数是被减数或者被除数。
代码：*/

#define STACK_WIDTH_SIZE 20
#define STACK_HEIGHT_SIZE 10000
typedef struct tokenStack {
    char tokenStack[STACK_HEIGHT_SIZE][STACK_WIDTH_SIZE];
    int top;
}TokenStack_T;

void TokenStackInit(TokenStack_T* stack)
{
    stack->top = -1;
    memset(stack->tokenStack, 0, sizeof(char) * STACK_WIDTH_SIZE * STACK_HEIGHT_SIZE);
}
int TokenStackIsFull(TokenStack_T* stack)
{
    return stack->top == STACK_HEIGHT_SIZE ? 1 : 0;
}
int TokenStackIsEmpty(TokenStack_T* stack)
{
    return stack->top == -1 ? 1 : 0;
}
char* TokenPop(TokenStack_T* stack)
{
    if (TokenStackIsEmpty(stack) != 1) {
        return stack->tokenStack[stack->top--];
    }
    return NULL;
}

void TokenPush(TokenStack_T* stack, char* str)
{
    if (TokenStackIsFull(stack) != 1) {
        stack->top++;
        memcpy(&stack->tokenStack[stack->top], str, strlen(str) + 1);
    }
}
int TokenIsDigtal(char* str)
{
    if (strcmp("+", str) == 0 || strcmp("-", str) == 0 || strcmp("*", str) == 0 || strcmp("/", str) == 0 ||
        strcmp("(", str) == 0 || strcmp(")", str) == 0) {
            return 0;
    }
    return 1;
}
// ["2", "1", "+", "3", "*"]
int evalRPN(char ** tokens, int tokensSize)
{
    int tempRet, i;
    int input1, input2;
    TokenStack_T stack = {0};
    TokenStackInit(&stack);
    char buffer[STACK_WIDTH_SIZE] = {0};
    if (tokens == NULL || *tokens == NULL || tokensSize == 0) {
        return 0;
    }
    for (i = 0; i < tokensSize; i++) {
        if (TokenIsDigtal(tokens[i]) == 1) {
            TokenPush(&stack, tokens[i]);
        } else {
            input1 = atoi(TokenPop(&stack));
            input2 = atoi(TokenPop(&stack));
            switch (tokens[i][0]) {
                case '+':
                    sprintf(buffer, "%d", input2 + input1);
                    TokenPush(&stack, buffer);
                    break;
                case '-':
                    sprintf(buffer, "%d", input2 - input1); // 这个一定是后出栈的是被减数
                    TokenPush(&stack, buffer);
                    break;
                case '*':
                    sprintf(buffer, "%d", input2 * input1);
                    TokenPush(&stack, buffer);
                    break;
                case '/':
                    sprintf(buffer, "%d", input2 / input1);// 这个一定是后出栈的是被除数
                    TokenPush(&stack, buffer);
                    break;
                default:
                    break;
            }
        }
    }
    return atoi(TokenPop(&stack));
}
