#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

int count_word(const std::string&);
void swap(char&, char&);
void reverse_string(std::string &s, std::size_t begin, std::size_t end);
std::string& reverse_word(std::string &s);
void print(const std::string &s);

int main(int argc, char** argv)
{
	std::string s =
			"I have a book named Advanced Programming of UNIX Environment";
	reverse_word(s);
	print(s);

	return 0;
}

void print(const std::string &s)
{
	std::cout << s << std::endl;
}

void swap(char &a, char &b)
{
	char _tmp = a;
	a = b;
	b = _tmp;
}

void reverse_string(std::string &s, std::size_t begin, std::size_t end)
{
	assert(begin <= end);
	while (begin < end)
	{
		swap(s[begin++], s[end--]);
	}
}

std::string& reverse_word(std::string &s)
{
	bool flag = false;
	std::size_t first = 0;
	for (std::size_t ix = 0; ix != s.length(); ++ix)
	{
		if (s[ix] == ' ' && flag)
		{
			flag = false;
			reverse_string(s, first, ix - 1);
		}
		else if (!flag && isalpha(s[ix]))
		{
			flag = true;
			first = ix;
		}
		else if (ix == s.length() - 1 && flag)
		{
			flag = false;
			reverse_string(s, first, ix);
		}
	}
	reverse_string(s, 0, s.length() - 1);
	return s;
}

int count_word(const std::string &s)
{
	bool flag = false;
	std::size_t cnt = 0;
	std::vector<std::string> vec;
	std::size_t first = 0;
	for (std::size_t ix = 0; ix != s.length(); ++ix)
	{
		if (s[ix] == ' ' && flag)
		{
			flag = false;
			std::string tmp_s = s.substr(first, ix - first);
			vec.push_back(tmp_s);
			cnt++;
		}
		else if (!flag && isalnum(s[ix]))
		{
			flag = true;
			first = ix;
		}
		else if (ix == s.length() - 1 && flag)
		{
			std::string tmp_s = s.substr(first, ix - first + 1);
			vec.push_back(tmp_s);
			cnt++;
		}
	}
	std::vector<std::string>::const_iterator iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	return cnt;

}
