using namespace std;
#include <iostream>
#include <stack>
#include <string>
#include <fstream>

int StringToInt(string number) {
	return (int)stoi(number);
}

void printStack(stack<string>& s) {
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return;
}

int factoriel(int x) {
	int answer = 1;
	for (int i = 1; i <= x; i++) {
		answer *= i;
	}
	return answer;
}

int functionF(int x) {
	return ((x * x) % 100);
}
int functionG(int x) {
	int eval = (x % 5);
	int answer = factoriel(eval);
	return answer;
}
int functionM(int x,int y) {
	if (x < y)
		return x;
	return y;
}
int Evaluate() {
	ifstream InFile("test.txt");

	if (!InFile) {
		cerr << "Error while opening" << endl;
	}
	char number;
	InFile.get(number);
	InFile.get();
	int res = number - '0';
	int counter = 0;
	stack<string> expession;
	stack<int> numbers;
	string line;
	int sizeOfStack = 0;
	while (getline(InFile, line)) {
		cout << "Line is " << line << endl;
		int length = line.length();
		for (int i = 0; i < length; i++){
			if (line[i] == '(' || line[i] == ')'||line[i]==',') {
				continue;
			}
			if (line[i] == 'f' ) {
				string function(1, 'f');
				expession.push(function);
				++sizeOfStack;
			}
			else if (line[i] == 'g') {
				string function(1, 'g');
				expession.push(function);
				++sizeOfStack;
			}
			else if(line[i] == 'm') {
				string function(1, 'm');
				expession.push(function);
				++sizeOfStack;
			}

			if (line[i] >= '1' && line[i] <= '9') {
				int index = i+1;
				int cnt = 1;
				while (line[index] >= '1' && line[index] <= '9')
				{
					++cnt;
					++index;
				}
				int lenghtToCopy = abs(index - i);
				expession.push(line.substr(i,lenghtToCopy));
				i += cnt;
				++sizeOfStack;
			}
		}
		//printStack(expession);//it is with a &

		numbers.push(StringToInt(expession.top()));
		expession.pop();
		while (!expession.empty())
		{

			--sizeOfStack;
			if (expession.top() == "f") {
				expession.pop();
				int tempAnswer = functionF(numbers.top());
				numbers.pop();
				numbers.push(tempAnswer);
				continue;
			}
			else if (expession.top() == "g") {
				expession.pop();
				int tempAnswer = functionG(numbers.top());
				numbers.pop();
				numbers.push(tempAnswer);
				continue;
			}
			else if (expession.top() == "m") {
				expession.pop();
				int firstNumber = numbers.top();
				numbers.pop();
				int secondNumber = numbers.top();
				numbers.pop();
				int tempAnswer = functionM(firstNumber, secondNumber);
				numbers.push(tempAnswer);
				continue;
			}
			numbers.push(StringToInt(expession.top()));
			expession.pop();


		}
		cout << numbers.top()<<endl;



	}

	while (counter<res)
	{
		
	

		++counter;
	}


	return 0;
}
int main() {
	Evaluate();
	string line = "asfd";
	//cout<<line.substr(1, 2)<<endl;
	//cout << line;
	//string s(1, 'a');
	//int x = (int)s[0];
	//cout << x;
	//cout<<stoi("32afdfg23");
	return 0;
}