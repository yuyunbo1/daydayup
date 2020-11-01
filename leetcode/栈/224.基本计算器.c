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
int Step(char *s){
    int num = 0, i;
    int tmpret, sum;
    int len = strlen(s);
    char opData = '+'; // 初始化为'+'
    char buffer[STACK_WIDTH_SIZE] = {0};
    TokenStack_T stack = {0};
    char c;
    TokenStackInit(&stack);
    for (i = 0; i < len; i++) {
        c = s[i];
        s[i] = ' '; // 处理完用空格标记   主要是因为碰到左括号递归，避免当递归返回，又会继续处理同个字符
        if (isdigit(c) != 0) {
            num = num * 10 + (c - '0');
        }
        if (c == '(') { // 碰到左括号进行递归
            num = Step(&s[i + 1]);
            continue;
        }
        // 碰到下一个数字或者结束,将数字入栈
        if ((isdigit(c) == 0 && c != ' ') || i == len - 1) {
            switch (opData) {
                case '+':
                    sprintf(buffer, "%d", num);
                    TokenStackPush(&stack, buffer);
                    break;
                case '-':
                    sprintf(buffer, "%d", -num);
                    TokenStackPush(&stack, buffer);
                    break;
                case '*': // 碰到乘除直接计算完入栈
                    tmpret = atoi(TokenStackPop(&stack));
                    sprintf(buffer, "%d", tmpret * num);
                    TokenStackPush(&stack, buffer);
                    break;
                case '/':
                    tmpret = atoi(TokenStackPop(&stack));
                    sprintf(buffer, "%d", tmpret / num);
                    TokenStackPush(&stack, buffer);
                    break;
            }
            opData = c;
            num = 0;
        }
		// 碰到右括号结束递归
        if (c == ')') {
            break;
        }
    }
    sum = 0;
    while (TokenStackIsEmpty(&stack) != 1) {
        sum += atoi(TokenStackPop(&stack));
    }
    return sum;
}
int calculate(char * s)
{
    return Step(s);
}
