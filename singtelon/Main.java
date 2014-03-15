public class Main
{
    public static void main(String[] args)
    {
        Singleton1 s1 = Singleton1.getInstance();
        Singleton1 s2 = Singleton1.getInstance();

        System.out.println(s1 == s2);

        Singleton2 s3 = Singleton2.getInstance();
        Singleton2 s4 = Singleton2.getInstance();

        System.out.println(s3 == s4);
    }


}

class Singleton1
{
    private static Singleton1 instance = new Singleton1();
    public static Singleton1 getInstance()
    {
        return instance;
    }
    
    private Singleton1()
    {
    }


}

class Singleton2
{
    private static Singleton2 instance;

    public static synchronized Singleton2 getInstance()
    {
        
        if (instance == null)
        {
            instance = new Singleton2();
        }
        return instance;
    }

    private Singleton2()
    {
    
    }

}
