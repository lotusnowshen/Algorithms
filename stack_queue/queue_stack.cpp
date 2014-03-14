#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>

class Stack
{
public:
	Stack();

	bool is_empty() const;
	void push(std::string);
	std::string top();
	void pop();

private:

	std::queue<std::string> qe1;
	std::queue<std::string> qe2;
	std::queue<std::string> *p_choice;
	std::queue<std::string> *p_no_choice;

	Stack(const Stack&);  //forbiden copy object

	void swap(std::queue<std::string> *&left, std::queue<std::string> *&right)
	{
		std::queue<std::string> *temp = left;
		left = right;
		right = temp;
	}

};

Stack::Stack()
{
	p_choice = &qe1;
	p_no_choice = &qe2;
}

bool Stack::is_empty() const
{
	return p_choice->empty() && p_no_choice->empty();
}

void Stack::push(std::string s)
{
	p_choice->push(s);
}

//anytimes there is a queue which is empty
std::string Stack::top()
{
	if(is_empty())
		throw std::runtime_error("queue empty!");
	std::string _ret;
	while(!p_choice->empty())
	{
		std::string _tmp = p_choice->front();
		p_choice->pop();
		if(p_choice->empty())
		{
			_ret = _tmp;
		}
		p_no_choice->push(_tmp);
	}
	swap(p_choice, p_no_choice);
	return _ret;
}
void Stack::pop()
{
	if(is_empty())
		throw std::runtime_error("queue empty!");
	std::string _ret;
	while(!p_choice->empty())
	{
		std::string _tmp = p_choice->front();
		p_choice->pop();
		if(p_choice->empty())
		{
			_ret = _tmp;
		}else{
			p_no_choice->push(_tmp);
		}
	}
	swap(p_choice, p_no_choice);
}


int main(int argc, char const *argv[])
{
	Stack st;
	st.push("hello");
	st.push("world");
	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	st.pop();
	return 0;
}