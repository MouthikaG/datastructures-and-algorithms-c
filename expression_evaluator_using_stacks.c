#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Stack {
    int top;
    double *arr;
    int capacity;
};

void initStack(struct Stack *stack, int capacity) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (double *)malloc(capacity * sizeof(double));
}


int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}


int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}


void push(struct Stack *stack, double value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
    } else {
        stack->arr[++stack->top] = value;
    }
}


double pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; 
    } else {
        return stack->arr[stack->top--];
    }
}


double peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return -1; 
    } else {
        return stack->arr[stack->top];
    }
}


int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}


double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}


double evaluateInfix(char* expression) {
    struct Stack valueStack;
    struct Stack operatorStack;
    
    initStack(&valueStack, 100);
    initStack(&operatorStack, 100);
    
    int i = 0;
    while (expression[i] != '\0') {
        
        if (isdigit(expression[i])) {
            double value = 0;
            while (isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            push(&valueStack, value);
        }
       
        else if (expression[i] == '(') {
            push(&operatorStack, expression[i]);
            i++;
        }
        
        else if (expression[i] == ')') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                double val2 = pop(&valueStack);
                double val1 = pop(&valueStack);
                char op = (char)pop(&operatorStack);
                push(&valueStack, applyOperator(val1, val2, op));
            }
            pop(&operatorStack); 
            i++;
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
            while (!isEmpty(&operatorStack) && precedence(peek(&operatorStack)) >= precedence(expression[i])) {
                double val2 = pop(&valueStack);
                double val1 = pop(&valueStack);
                char op = (char)pop(&operatorStack);
                push(&valueStack, applyOperator(val1, val2, op));
            }
            push(&operatorStack, expression[i]);
            i++;
        }
        else {
            i++;
        }
    }

    while (!isEmpty(&operatorStack)) {
        double val2 = pop(&valueStack);
        double val1 = pop(&valueStack);
        char op = (char)pop(&operatorStack);
        push(&valueStack, applyOperator(val1, val2, op));
    }

    return pop(&valueStack);
}

int main() {
    char expression[100];
    printf("Enter an infix expression: ");
    scanf("%s", expression);
    
    printf("Postfix expression: ");
    printf("%s\n", expression);
    
    double result = evaluateInfix(expression);
    printf("Result: %.2lf\n", result);
}     

