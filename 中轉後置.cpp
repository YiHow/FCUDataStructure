#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    char key;
} element;
element stack[MAX];
int top;
void push(char item){
    if(top >= MAX)
    {
        printf("Stack is full, can't add element\n\n");
    }
    stack[++top].key = item;
}
element pop(){
    if(top == -1)
    {
        printf("Stack is empty\n\n");
    }
    else{
        return stack[top--];
    }
}

int priority(char op){				//Àu¥ýÅv
    switch(op){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
void infixToPostfix(char* in, char* post){
    int i, j, k;
    for(i = 0, j = 0, top = -1; in[i] != '\0' ; i++){
        switch(in[i]){
        case '(':
            push(in[i]);
            break;
        case '+':case '-':case '*':case '/':
            while(priority(stack[top].key) >= priority(in[i])){
                post[j++] = pop().key;
            }
            push(in[i]);
            break;
        case ')':
            while(pop().key != '('){
                top++;
                post[j++] = pop().key;
            }
            break;
        default:
            post[j++] = in[i];
        }
    }
    while(top >= 0){
        post[j++] = pop().key;
    }
}
int main()
{
    char input[MAX] = {'\0'};
    char output[MAX] = {'\0'};
    int i;
    printf("Infix : \n");
    scanf("%s", input);
    infixToPostfix(input, output);
    printf("Postfix : \n");
    for(i = 0 ; output[i] != '\0' ; i++)
    {
        printf("%c", output[i]);
    }
    return 0;
}

