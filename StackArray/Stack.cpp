#include <array>
#include <stdexcept>
#include <iostream>
#include <string>
template < typename T, int size>
class Stack {
	std::array<T, size> arr;
	int top = -1;

public:
	Stack() {
		top = -1;
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == size - 1;
	}

	void push(T element) {
		if (isFull()) {
			throw std::overflow_error("Stack is full");
		}
		top++;
		arr[top] = element;
	}

	T pop() {
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty");
		}
		T element = arr[top];
		top--;
		return element;
	}

	int getSize() {
		return top + 1;
	}

	void Peek(int index) {
		std::count << arr[index];
	}


	void displayResult() {
		if (isEmpty()) {
			std::cout << "Stack is empty." << std::endl;
			return;
		}
		std::cout << "Stack Result:" << std::endl;
		for (int i = 0; i <= top; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}


};