#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

class Queue
{
public:

	bool is_empty() const;
	void append_tail(std::string);
	std::string delete_head();

private:
	std::stack<std::string> st1;
	std::stack<std::string> st2;
};

bool Queue::is_empty() const
{
	return st1.empty() && st2.empty();
}

void Queue::append_tail(std::string s)
{
	st1.push(s);
}

std::string Queue::delete_head()
{
	if(is_empty())
		throw std::runtime_error("stack empty");
	if(st2.empty())
	{
		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
	}

	std::string _ret = st2.top();
	st2.pop();
	return _ret;

}

int main(int argc, char const *argv[])
{
	
	Queue q;
	q.append_tail("hello");
	q.append_tail("world");

	std::cout << q.delete_head() << std::endl;
	std::cout << q.delete_head() << std::endl;
	std::cout << q.delete_head() << std::endl;
	return 0;
}