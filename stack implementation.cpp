#include<iostream>
#include<limits>
//swap two integers 
void swap(int &num1,int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
//class for stack
class stack{
    private:
        int top;
        int size = 10;
        int* arr = new int[size];
    public:
        //constructor to initialize the stack 
        stack(){
            top = -1;
            for(int i=0;i<size;i++){
                arr[i] = 0;
            }
        }
        //destructor to clean up dynamically allocated memeory
        ~stack(){
            delete[] arr;
        }
        //check is the stack is full
        bool isFull(){
            if(top + 1 == size){
                return true;
            }
            return false;
        }
        //check if the stack is empty
        bool isEmpty(){
            if(top == -1){
                return true;
            }
            return false;
        }
        //add a value to the stack 
        void push(int value){
            if(isFull()){
                std::cout<< "The stack is full"<<std::endl;
                return;
            }
            else{
                top++;
                arr[top] = value;
            }
        }
        //remove the top value from the stack 
        int pop(){
            int temp;
            if(isEmpty()){
                std::cout<< "There is nothing to pop. The stack is empty"<<std::endl;
                return -1;
            }
            else{
                temp = arr[top];
                top--;
            }
            return temp;
        }
        //return the top value of the stack
        int peek(){
            return arr[top];
        }
        //display the number of elements in the stack
        int count(){
            return top + 1;
        }
        //display the stack 
        void display(){
            for(int i=top;i>=0;i--){
                std::cout<< "\t\t"<<arr[i] << std::endl;
            }
        }
        //return the maximum value in the stack
        int maxValue(){
            if(isEmpty()){
                std::cout<<"the stack is empty"<<std::endl;
                return -1;
            }
            int max = arr[0];
            for(int i=0;i<=top;i++){
                if(max<arr[i]){
                    max = arr[i];
                }
            }
            return max;
        }
        //return the minimum value in the stack 
        int minValue(){
            if(isEmpty()){
                std::cout<< "The stack si empty"<<std::endl;
                return -1;
            }
            int min = arr[0];
            for(int i=0;i<=top;i++){
                if(min>arr[i]){
                    min = arr[i];
                }
            }
            return min;
        }
        //reverse the order of the elements in the stack
        void reverse(){
            int j = top;
            for(int i=0;i<=(top/2);i++){
                swap(arr[i],arr[j]);
                j--;
            }
        }
        //order the elementsof the stack in descending order 
        void order(){
            for(int i=0;i<=top;i++){
                for(int j=i;j<=top;j++){
                    if(arr[i]>arr[j]){
                        swap(arr[i],arr[j]);
                    }
                }
            }
        }
        //resize the satck to double its current size
        void resize(){
            int newSize = size*2;
            int* newArr = new int[newSize];
            for(int i=0;i<size;i++){
                newArr[i] = arr[i];
            }
            arr = newArr;
            size = newSize;
            delete[] newArr;
        }
};
//reverse the stack order using temporary stack 
void reverseStack(stack* s1){
    stack* s2= new stack;
    stack* s3 = new stack;
    while(!s1->isEmpty()){
        s2->push(s1->pop());
    }
    while(!s2->isEmpty()){
        s3->push(s2->pop());
    }
    while(!s3->isEmpty()){
        s1->push(s3->pop());
    }
    delete s2;
    delete s3;
}
//validate the entered integer by user 
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Invalid input!Please try again"<<std::endl;
        }
        else{
            return num;
        }
    }
}
int main(){
    stack s1;
    int op,value;
    bool leave = false;
    while(leave!=true){
        std::cout<< "###################Operations####################"<<std::endl;
        std::cout<<"1.is the stack empty?\n2.is the stack full?\n3.push a value to stack\n4.pop a value from the stack\n5.peek the top value of the stack\n6.the number of elements in the stack\n7.display the stack\n8.revesre the stack\n9.reverse the stack using a temp stack\n10.whats the min value in the stack?\n11.whats the max value in the stack?\n12.order the stack in descending order\n13.resize the size of your stack.\n14.leave"<<std::endl;
        std::cout<< "Enter the number of the operation"<<std::endl;
        op = valid(op);
        while(op>14 || op<1){
            std::cout<< "Invalid number of operation!Please try again"<<std::endl;
            op = valid(op);
        }
        switch(op){
            case 1:
                std::cout<< "Is the stack empty? "<<s1.isEmpty()<<std::endl;
                break;
            case 2:
                std::cout<< "Is the stack Full? "<<s1.isFull()<<std::endl;
                break;
            case 3:
                std::cout<< "Enter the value you want to push"<<std::endl;
                value = valid(value);
                s1.push(value);
                std::cout<< "You have pushed the value "<<value<<std::endl;
                break;
            case 4:
                std::cout<< "You have popped the value " <<s1.pop()<<std::endl;
                break;
            case 5:
                std::cout<<"You have peeked for the value "<<s1.peek()<<std::endl;
                break;
            case 6:
                std::cout<< "You have "<<s1.count() << " elements in your stack "<<std::endl;
                break;
            case 7:
                std::cout<< "The stack displayment "<<std::endl;
                s1.display();
                break;
            case 8:
                s1.reverse();
                std::cout<< "You have reversed your stack"<<std::endl;
                break;
            case 9:
                reverseStack(&s1);
                std::cout<< "You have revesred your stack using temporary stack"<<std::endl;
                break;
            case 10:
                std::cout<< "The minimum value in the stack is "<<s1.minValue()<<std::endl;
                break;
            case 11:
                std::cout<< "The maximum value in the stack is "<<s1.maxValue()<<std::endl;
                break;
            case 12:
                s1.order();
                std::cout<< "You have ordered your list in descending order"<<std::endl;
                break;
            case 13:
                std::cout<< "You have increased the size of your stack"<<std::endl;
                s1.resize();
                break;
            case 14:
                leave = true;
                std::cout<< "Bye!"<<std::endl;
                break;
        }
    }
    return 0;
}