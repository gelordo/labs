#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// GENERAL
#define CONT { \
 clear_buffer();\
 SLEEP300;\
 printf("Press Enter key to continue.");\
 getchar();\
 system(CLEAR);\
}

////FOR WINDOWS////
#include<windows.h>
#define CLEAR "cls"
#define SLEEP650 Sleep(650)
#define SLEEP300 Sleep(300)

typedef enum {
    EINT, EFLOAT, EDOUBLE, ESTRING
} DataType;

typedef struct Node {
    void* value;
    DataType type;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
    int cap;
    int size;
} Stack;

typedef struct String {
    char val;
    struct String* next;
} String;

void clear_buffer();
void options();
void input(int* choice);
String* snode();
Node* createNode(void* data, DataType type, size_t size);
void add(String* old_node, char a);
String* create_string(char* a);
Stack* createStack(int cap);
int isEmpty(Stack* stack);
String* isEmpty_text(Stack* stack);
int isFull(Stack* stack);
String* isFull_text(Stack* stack);
void prints(String* string);
void print(const char* str, ...);
void push(Stack* stack, void* value, DataType type);
void* pop(Stack* stack);
String* create_string_input();
void peek(Stack* stack);
void freeStack(Stack* stack);

int stackDeclared = 0;

int main() {
    print("Hard Task, Lab-5");
    SLEEP300;
    print("Press Enter key continue.");
    getchar();
    
    Stack* stack = NULL;

Return:
    options();
    int choice;
    input(&choice);

    switch (choice) {
        case 1:
            system(CLEAR);
            print("Initializing stack...");
            SLEEP650;
            if (stackDeclared == 0) {
                printf("Choose stack capacity (integer): ");
                int n;
                input(&n);
                stack = createStack(n);
                print("Initializing a stack with %i elements", n);
                stackDeclared = 1;
                CONT;
            }
            else {
                print("Already initialized, skipping...");
                CONT;
            }
            break;

        case 2: //push
            system(CLEAR);
			if (stack){
            print("Which data type will you push?");
            print("[1] Integer");
            print("[2] Float");
            print("[3] Double");
            print("[4] String");
            print("[5] Cancel");

            int pushc;
            input(&pushc);
            switch (pushc) {
                case 1:
                    print("Pushing Int");
                    int myInt;
					scanf("%i", &myInt);
                    push(stack, &myInt, EINT);
                    break;
                case 2:
                    print("Pushing float");
                    float myFloat;
					scanf("%f", &myFloat);
                    push(stack, &myFloat, EFLOAT);
                    break;
                case 3:
                    print("Pushing double");
                    double myDouble;
					scanf("%d", &myDouble);
                    push(stack, &myDouble, EDOUBLE);
                    break;
                case 4:
                    print("Pushing string");
                    String* myString = create_string_input();
                    push(stack, myString, ESTRING);
                    break;
                case 5:
                    print("Canceling...");
                    SLEEP650;
                    break;
                default:
                    system(CLEAR);
                    print("Invalid input. Please enter a valid number.");
                    clear_buffer();
                    SLEEP650;
                    break;
            }

            CONT;
            break;
			}
			print("Stack not initialized");
			CONT;
			break;

        case 3: //pop
            system(CLEAR);
			if (stack){
            if (isEmpty(stack) == 0) {
                print("Popping first element.");
                pop(stack);
            }
            else
                print("The stack is already empty");
            CONT;
            break;

        case 4: //peek
            system(CLEAR);
            if (stack) {
                peek(stack);
            }
            else
                print("Stack not initialized.");
            CONT;
            break;
			}
			print("Stack not initialized");
			CONT;
			break;
        case 5: //check if empty
            system(CLEAR);
            if (stack) {
                prints(isEmpty_text(stack));
            }
            else
                print("Stack not initialized.");
            CONT;
            break;

        case 6: //check if full
            system(CLEAR);
            if (stack) {
                prints(isFull_text(stack));
            }
            else
                print("Stack not initialized.");
            CONT;
            break;

        case 7: //free
            system(CLEAR);
			if (stack){
            if (isEmpty(stack) == 0) {
                print("Freeing memory.");
                freeStack(stack);
            }
            else
                print("The stack is already empty");
            CONT;
            break;
			}
			print("Stack not initialized.");
            CONT;
            break;

        case 8: //exit
            print("Exiting program...");
			SLEEP650;
            goto Exit;
        default:
            system(CLEAR);
            print("Invalid input. Please enter a valid number.");
            clear_buffer();
            SLEEP650;
            break;
    }
    goto Return;
Exit:
    return 0;
}

void push(Stack* stack, void* value, DataType type) {
    if (isFull(stack) == 0) {
        Node* newNode = createNode(value, type, sizeof(value));
        newNode->next = stack->head;
        stack->head = newNode;
        stack->size++;
    } else {
        print("Stack is full");
    }
}

void peek(Stack* stack) {
	if (stack){
		if (isEmpty(stack)) {
			print("The stack is empty");
			return;
		}
	
    switch (stack->head->type) {
        case EINT:
            print("%i", *(int*)(stack->head->value));
            break;
        case EFLOAT:
            print("%f", *(float*)(stack->head->value));
            break;
        case EDOUBLE:
            print("%f", *(double*)(stack->head->value));
            break;
        case ESTRING:
            prints((stack->head->value));
            break;
    }
	}
	print("Stack is NULL");
	return;
}

void* pop(Stack* stack) {
    if (isEmpty(stack)) {
        print("The stack is empty");
        return NULL;
    }

    Node* temp = stack->head;
    stack->head = temp->next;
    void* value = temp->value;
    free(temp);
    stack->size--;
    return value;
}

Node* createNode(void* data, DataType type, size_t size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = malloc(size);
    newNode->type = type;
    memcpy(newNode->value, data, size);
    newNode->next = NULL;
    return newNode;
}

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->cap = cap;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

String* isEmpty_text(Stack* stack) {
    String* yes = create_string("Yes, it's empty.\n");
    String* no = create_string("No, it's not empty.\n");
    return stack->size == 0 ? yes : no;
}

int isFull(Stack* stack) {
    return stack->size >= stack->cap;
}

String* isFull_text(Stack* stack) {
    String* yes = create_string("Yes, it's full.\n");
    String* no = create_string("No, it's not full.\n");
    return stack->size >= stack->cap ? yes : no;
}

void prints(String* string) {
    while (string != NULL) {
        printf("%c", string->val);
        string = string->next;
    }
    printf("\n");
}

void print(const char* str, ...) {
    va_list args;
    va_start(args, str);
    vprintf(str, args);
    va_end(args);
    printf("\n");
}

String* snode() {
    String* string = (String*)malloc(sizeof(String));
    string->val = '\0';
    string->next = NULL;
    return string;
}

void add(String* old_node, char a) {
    String* new_node = snode();
    new_node->val = a;
    while (old_node->next) {
        old_node = old_node->next;
    }
    old_node->next = new_node;
}


String* create_string(char* a) {
    String* string = snode();
    int i = 0;
    while (a[i] != '\0') {
        add(string, a[i]);
        i++;
    }
    return string;
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void options() {
    print("Enter your choice (1-8): ");
    print("[1] Initialize the stack");
    print("[2] Push");
    print("[3] Pop");
    print("[4] Peek");
    print("[5] Check if it's empty");
    print("[6] Check if it's full");
    print("[7] Free stack");
    print("[8] Exit program");
}

void input(int* choice) {
    while (1) {
        if (scanf("%i", choice) == 1) {
            break;
        } else {
            system(CLEAR);
            print("Invalid input. Please enter a valid number.");
            SLEEP650;
            options();
            clear_buffer();
        }
    }
}

String* create_string_input() {
    String* string = snode();
    char buffer[100];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int i = 0;
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            add(string, buffer[i]);
            i++;
        }
    } else {
        fprintf(stderr, "Error reading input.\n");
    }

    return string;
}

void freeStack(Stack* stack) {
    while (stack->head) {
        Node* temp = stack->head;
        stack->head = stack->head->next;
        free(temp->value);
        free(temp);
    }
	stackDeclared = 0;
}