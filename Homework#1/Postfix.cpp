/*CS256 - Assignment#1 (Calculator)
  Jong Woo Lee
  Due Date: 4/20/15
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class post_fix{
	int result;
	int size;
	string user_input_expression;
	double evaluated_result;
	stack<double> operand;

public:
	void set_expression(string);
	double evaluate();
	void post_fix::add_values(int, int);
	void post_fix::subtract_values(double, double);
	void post_fix::multiply_values(double, double);
	void post_fix::divide_values(double, double);
};

//Sets the expression that the user inputted into the string of the class
void post_fix::set_expression(string user_input){
	size = user_input.size();

	for (int i = 0; i < size; i++){
		user_input_expression = user_input;
	}
}

double post_fix::evaluate(){
	double value1, value2, test, result;

	for (int i = 0; i < size; i++){
		if ((double)user_input_expression[i] >= 48 && (double)user_input_expression[i] <= 57){
			//Casting to get the ASCII index and subtract by a 48 to retrieve the string amount
			test = (double) user_input_expression[i] - 48;
			operand.push(test);
		}

		//Use the addition function
		if (user_input_expression[i] == '+'){
			value1 = operand.top();
			operand.pop();
			value2 = operand.top();
			operand.pop();
			if (value2 == NULL){
				value2 = 0;
				add_values(value1, value2);
			}
			add_values(value1, value2);
		}

		//Use the subtraction function
		if (user_input_expression[i] == '-'){
			value1 = operand.top();
			operand.pop();
			value2 = operand.top();
			operand.pop();
			if (value2 == NULL){
				value2 = 0;
				subtract_values(value1, value2);
			}
			subtract_values(value1, value2);
		}

		//Use the multiplication function
		if (user_input_expression[i] == '*'){
			value1 = operand.top();
			operand.pop();
			value2 = operand.top();
			operand.pop();
			if (value2 == NULL){
				value2 = 0;
				multiply_values(value1, value2);
			}
			multiply_values(value1, value2);
		}

		//Use the division function
		if (user_input_expression[i] == '/'){
			value1 = operand.top();
			operand.pop();
			value2 = operand.top();
			operand.pop();
			if (value2 == NULL){
				value2 = 0;
				divide_values(value1, value2);
			}
			divide_values(value1, value2);
		}
	}
	result = operand.top();

	return result;
}

//Function to add the top values of the stack
void post_fix::add_values(int pop_value1, int pop_value2){
	double d = double(pop_value1 + pop_value2);
	cout << "The added value is: " << d << endl;
	operand.push(d);
}

//Function to subtract the top values of the stack
void post_fix::subtract_values(double pop_value1, double pop_value2){
	double d = pop_value2 - pop_value1;
	cout << "The subtracted value is: " << d << endl;
	operand.push(d);
}

//Function to multiply the top values of the stack
void post_fix::multiply_values(double pop_value1, double pop_value2){
	double d = pop_value1 * pop_value2;
	cout << "The multiplied value is: " << d << endl;
	operand.push(d);
}

//Function to divide the top values of the stack
void post_fix::divide_values(double pop_value1, double pop_value2){
	double d = pop_value2 / pop_value1;
	cout << "The divided value is: " << d << endl;
	operand.push(d);
}



int main(){
	string user_input;
	//Prompt the user to enter a Post-Fix Expression
	cout << "Please enter a Post-Fix Expression: " << endl;

	cin >> user_input;

	post_fix post;
	post.set_expression(user_input);
	post.evaluate();
	cout <<	"The result is: " << post.evaluate() << endl;

	//Pause the system so it doesn't close after program is done
	system("pause");
}