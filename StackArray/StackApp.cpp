#include "Stack.cpp"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	Stack <int, 100> st;
	string tekst;
	std::cout << "GIVE ME THE MODEL STRING: ";
	std::getline(std::cin, tekst);
	//std::cout << tekst<<std::endl;
	stringstream ss(tekst);
	string token;

	string sing;
	int first;
	int second;
	int result;

	while (ss >> token) {

		std::cout << token << std::endl;
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			//std::cout << token << " - operator" << std::endl;
			second = st.pop();
			first = st.pop();
			std::string expression = std::to_string(first) + token + std::to_string(second);
			std::cout << "Expression: " << expression << std::endl;

			if (token == "+") {
				result = first + second;
				st.push(result);
			}
			else if (token == "-") {
				result = first - second;
				st.push(result);
			}
			else if (token == "*") {
				result = first * second;
				st.push(result);
			}
			else if (token == "/") {
				if (second != 0) {
					result = first / second;
					st.push(result);
				}
				else {
					std::cout << "Error: Division by zero." << std::endl;
					return 1;
				}
			}
			else {
				std::cout << "Error: Unsupported operation." << std::endl;
				return 1;
			}

		}
		else {
			//std::cout << stoi(token) << " - number" << std::endl;
			int num = std::stoi(token);
			st.push(num);
		}
	}

	st.displayResult();

}