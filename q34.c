//Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if(top == NULL) return 0;

    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    int i = 0, a, b, result;

    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0') {

        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            b = pop();
            a = pop();

            if(exp[i] == '+') result = a + b;
            else if(exp[i] == '-') result = a - b;
            else if(exp[i] == '*') result = a * b;
            else if(exp[i] == '/') result = a / b;

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}