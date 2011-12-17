#ifndef _NIHPP_SINGLETON_HH_
#define _NIHPP_SINGLETON_HH_

namespace nihpp
{
    template <typename T>
    class Singleton
    {
    public:
        static T &instance ()
        {
            static T inst;

            return inst;
        }
    };
}

#endif  // _NIHPP_SINGLETON_HH_
