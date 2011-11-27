#ifndef _NIHPP_PTRCREATOR_HH_
#define _NIHPP_PTRCREATOR_HH_

#include <utility>
#include <memory>

namespace nihpp
{
    template <typename T, typename U = T*>
    class PtrCreator
    {
    public:
        typedef U Ptr;

        static Ptr create ()
        { return Ptr (new T); }

        template <typename... Args>
        static Ptr create (Args&&... args)
        { return Ptr (new T (std::forward<Args> (args)...)); }
    };

    template <typename T>
    struct SharedPtrCreator
    {
        typedef PtrCreator<T, std::shared_ptr<T>> type;
    };
}
#endif  // _NIH_PTRCREATOR_HH_
