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
    char opData = '+'; // ��ʼ��Ϊ'+'
    char buffer[STACK_WIDTH_SIZE] = {0};
    TokenStack_T stack = {0};
    char c;
    TokenStackInit(&stack);
    for (i = 0; i < len; i++) {
        c = s[i];
        s[i] = ' '; // �������ÿո���   ��Ҫ����Ϊ���������ŵݹ飬���⵱�ݹ鷵�أ��ֻ��������ͬ���ַ�
        if (isdigit(c) != 0) {
            num = num * 10 + (c - '0');
        }
        if (c == '(') { // ���������Ž��еݹ�
            num = Step(&s[i + 1]);
            continue;
        }
        // ������һ�����ֻ��߽���,��������ջ
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
                case '*': // �����˳�ֱ�Ӽ�������ջ
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
		// ���������Ž����ݹ�
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
