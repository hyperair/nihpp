#include <nihpp/singleton.hh>
#include <cassert>

namespace
{
    bool in_main;
    bool constructed;

    class TestSingleton : public nihpp::Singleton<TestSingleton>
    {
    public:
        TestSingleton ()
        {
            assert (in_main);
            assert (!constructed);

            constructed = true;
        }

        ~TestSingleton ()
        {
            assert (!in_main);
        }
    };
}

int main ()
{
    in_main = true;
    TestSingleton &first = TestSingleton::instance ();
    TestSingleton &second = TestSingleton::instance ();

    assert (&first == &second);

    in_main = false;

    return 0;
}
