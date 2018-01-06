/*
  Stack of Integers
*/

class InStack {
    int *element;
    int max_size;
    int top_index;

public:
    InStack(int s) {
        max_size = s;
        top_index = -1;
        element = new int[s];
    }

    ~InStack() {
        delete [] element; 
    }

    void push(int x) {
        if (top_index == max_size -1)
          throw std::runtime_error("stack_full");
        top_index++;
        element[top_index] = x;         
    }

    void pop() {
        if (top_index == -1) 
          throw std::runtime_error("empty stack");
        top_index--;
    }

    int top() {
        if (top_index == -1) 
          throw std::runtime_error("empty stack");
        return element[top_index];
    }

    bool empty() {
        return (top_index == -1);
    }

}
