#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include <string.h> 

// GENERAL
#define CONT { \
 clear_buffer();\
 SLEEP300;\
 print("Press Enter key to continue.");\
 getchar();\
 system(CLEAR);\
}

////FOR WINDOWS////
#include<windows.h> 
#define CLEAR "cls" 
#define SLEEP650 Sleep(650) 
#define SLEEP300 Sleep(300) 

////FOR UNIX*////
// #include<unistd.h> 
//#define CLEAR "clear"
// #define SLEEP650 sleep(650) 
// #define SLEEP300 sleep(650) 


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

typedef struct string {
    char val;
    struct string *next;
}String;

typedef enum { 
    INT, FLOAT, DOUBLE, STRING 
} DataType; 
 

void clear_buffer();
void options();
void input();
String* snode();
Node *createNode(void *data, DataType type, size_t size);
void add(String *old_node, char a);
String* create_string(char* a);
Stack* createStack(int cap);
int isEmpty(Stack* stack);
String* isEmpty_text(Stack* stack);
int isFull(Stack* stack);
String* isFull_text(Stack* stack);
void prints(String *string);
void print(const char* str, ...);
void push(Stack* stack, void* value);
void* pop(Stack* stack);

int main(){
	print("Hard Task, Lab-5");
	SLEEP300;\
	print("Press Enter key continue.");\
	getchar();\
	int stackDeclared = 0;
	Stack* stack = NULL;
	Return:
	options();
	int choice;
	input(&choice);
	
	switch (choice){
	    case 1:
		system(CLEAR);
	    print("Initializing stack...");
		SLEEP650;
        if (stackDeclared == 0){
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
		CONT;}
	    break;
	    
	    case 2: //push
		system(CLEAR);
		print("Which data type will you push?");
		print("[1] Integer");
		print("[2] Float");
		print("[3] Char");
		print("[4] String");
		print("[5] Custom Structure");
		input();
		
		CONT;
            break;
			
	    case 3: //pop
		system(CLEAR);
		if (isEmpty(stack) == 0){
		print("Popping first element.");
		pop(stack);
		} else print("The stack is already empty");
		CONT;
	        break;
			
	    case 4: //peek
		system(CLEAR);
		print("No functionality yet..");
		CONT;
	        break;
			
	    case 5: //check if empty
		system(CLEAR);
		if (stack){
		prints(isEmpty_text(stack));}
		else print("Stack not initialized.");
		CONT;
	        break;
			
	    case 6: //check if full
		system(CLEAR);
		if (stack)
		prints(isFull_text(stack));
		else print("Stack not initialized.");
		CONT;
	        break;
		
		case 7: //exit
			getchar();
			print("Exiting program...");
			goto Exit;
	    default:
		system(CLEAR);
        printf("Invalid input. Please enter a valid number.\n");
		clear_buffer();
		SLEEP650;
	    break;
	}
	goto Return;
	Exit:
	print("Press Enter to confirm");
	getchar();
	return 0;
}

void push(Stack* stack, void* value) {
	if(isFull(stack) == 0){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
	stack->size = stack->size + 1;
	} else {
        print("Stack is full");
    }
}

void* peek(Stack* stack) {
    if (stack->head != NULL) {
        return stack->head->value;
    }
    return NULL;	  
}

void* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    Node* temp = stack->head;
    stack->head = temp->next;
    void* value = temp->value;
    free(temp);
    return value;
}

Node *createNode(void *data, DataType type, size_t size) { 
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = malloc(size); 
    newNode->type = type; 
    memcpy(newNode->data, data, size); 
    newNode->next = NULL; 
    return newNode; 
} 

Stack* createStack(int cap){
	Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
	stack->cap = cap;
	stack->size = 0;
	return stack;
}

int isEmpty(Stack* stack) {
    return stack->head == NULL; //false or true
}

String* isEmpty_text(Stack* stack){
    String* yes = create_string("Yes, its empty.");
    String* no = create_string("No, it's not empty.");
    if (stack->head == NULL) return yes;
    else return no;
}

int isFull(Stack* stack) {
    return stack->size >= stack->cap; //false or true
}

String* isFull_text(Stack* stack){
    String* yes = create_string("Yes, its full.");
    String* no = create_string("No, it's not full.");
    if (isFull(stack)) return yes;
    else return no;
}

void prints(String *string) {
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

String* snode(){
    String *string = (String*)malloc(sizeof(String));
    string->val = '\0';
    string->next = NULL;
    return string;
}

void add(String *old_node, char a){
    String* new_node = snode();
    new_node->val = a;
    while(old_node->next){
        old_node = old_node->next;
    }
    old_node->next = new_node;
}

String* create_string(char* a){
    String *string = snode();
    int i=0;
    while(a[i] != '\0'){
        add(string, a[i]);
        i++;
    }
    return string;
}

void clear_buffer(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

void options(){
	print("Enter your choice (1-7): ");
	print("[1] Initialize the stack");
	print("[2] Push");
	print("[3] Pop");
	print("[4] Peek");
	print("[5] Check if it's empty");
	print("[6] Check if it's full");
	print("[7] Exit program");
}

void input(int* choice){
	while (1) {
    if (scanf("%i", choice) == 1) 
	{
        break; 
    } else 
		{
		system(CLEAR);
        print("Invalid input. Please enter a valid number.");
		SLEEP650;
		options();
		clear_buffer();
		}
	}
}

