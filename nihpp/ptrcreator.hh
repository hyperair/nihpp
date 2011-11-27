#ifndef _NIHPP_PTRCREATOR_HH_
#define _NIHPP_PTRCREATOR_HH_

#include <utility>
#include <memory>

#ifdef NIHPP_ENABLE_GLIB
#include <glibmm/refptr.h>
#endif

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

#ifdef NIHPP_ENABLE_GLIB
    namespace Glib
    {
        template <typename T>
        struct RefPtrCreator
        {
            typedef PtrCreator<T, ::Glib::RefPtr<T>> type;
        };
    }
#endif

}
#endif  // _NIH_PTRCREATOR_HH_
