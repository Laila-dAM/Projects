#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct{
    double data[MAX];
    int top;
} OperandStack;

typedef struct {
    char data[MAX];
    int top;
} OperatorStack;

void initOperandStack(OperandStack *stack){
    stack->top = -1;
}
void initOperatorStack(OperatorStack *stack){
    stack->top = -1;
}
int isOperandStackEmpty(OperandStack *stack){
    return stack->top == -1;
}
int isOperatorStackEmpty(OperatorStack *stack){
    return stack->top == -1;
}
void pushOperand(OperandStack *stack, double value){
    if(stack->top < MAX -1){
        stack->data[++stack->top] = value;
    }
    else {
        printf("Error: Operand stack overflow\n");
    }
}
double popOperand(OperandStack *stack){
    if(!isOperandStackEmpty(stack)){
        return stack->data[stack->top--];
    } 
    else {
        printf("Error: Operand stack underflow\n");
        return 0;
    }
}
void pushOperator(OperatorStack *stack, char value){
    if(stack->top < MAX - 1){
        stack->data[++stack->top] = value;
    } else {
        printf("Error: Operator stack overflow\n");
    }
}
char popOperator(OperatorStack *stack) {
    if (!isOperatorStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    else {
        printf("Error: Operator stack underflow\n");
        return '\0';
    }
}
int precedence(char op){
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
int isOperator(char ch){
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
void infixToPostfix(char *infix, char *postfix) {
    OperatorStack operatorStack;
    initOperatorStack(&operatorStack);
    int i = 0, j = 0;

while(infix[i] !='\0'){
    if(isdigit(infix[i]) || infix[i] == '.') {
        postfix[j++] = infix[i];
    }
    else if (isOperator(infix[i])) {
        postfix[j++] = ' ';
            while (!isOperatorStackEmpty(&operatorStack) && precedence(operatorStack.data[operatorStack.top]) >= precedence(infix[i])) {

                postfix[j++] = popOperator(&operatorStack);
    postfix[j++] = ' ';
        
    }
pushOperator(&operatorStack, infix[i]);
        
} else if (infix[i] == '('){
        pushOperator(&operatorStack, infix[i]);
}
    else if(infix[i] == ')'){
            while (!isOperatorStackEmpty(&operatorStack) && operatorStack.data[operatorStack.top] != '(') {
postfix[j++] = popOperator(&operatorStack);
    postfix[j++] = ' ';
}
popOperator(&operatorStack);
    }
    i++;
    
}
while(!isOperatorStackEmpty(&operatorStack)){
    postfix[j++] = ' ';
    postfix[j++] = popOperator(&operatorStack);
}
    postfix[j] = '\0';
    }
double evaluatePostfix(char *postfix){
    OperandStack operandStack;
    initOperandStack(&operandStack);
    int i = 0;
    char buffer[MAX];

while(postfix[i] != '\0'){
    if(isdigit(postfix[i]) || postfix[i] == '.'){
        int j = 0;

while(isdigit(postfix[i]) || postfix[i] == '.'){
    buffer[j++] = postfix[i++];
}
    buffer[j] = '\0';
    pushOperand(&operandStack, atof(buffer));
    }
else if (isOperator(postfix[i])){
    double b = popOperand(&operandStack);
    double a = popOperand(&operandStack);
    switch(postfix[i]) {
        case '+': pushOperand(&operandStack, a + b); break;
        case '-': pushOperand(&operandStack, a - b); break;
        case '*': pushOperand(&operandStack, a * b); break;
        case '/': pushOperand(&operandStack, a / b); break;
        case '^': pushOperand(&operandStack, pow(a, b)); break;
   
}
    i++;
} 
    else {
        i++;
        
    }
}
    return popOperand(&operandStack);
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %lf\n", evaluatePostfix(postfix));
    return 0;
}