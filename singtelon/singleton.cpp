#include <iostream>
#include <string>

class Singleton
{
    private:
        Singleton(){ };
        Singleton(const Singleton &); // not implement
        Singleton& operator=(const Singleton &); // not implement

    public:
        static Singleton &get_instance();
};

Singleton& Singleton::get_instance()
{
    static Singleton instance;
    return instance;
}

int main()
{
    Singleton &s1 = Singleton::get_instance();
    Singleton &s2 = Singleton::get_instance();

    Singleton *p1 = &s1;
    Singleton *p2 = &s2;
    std::cout << (p1 == p2) << std::endl;

    return 0;

}
