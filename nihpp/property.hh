#ifndef _NIHPP_PROPERTY_HH
#define _NIHPP_PROPERTY_HH

#include <functional>
#include <memory>
#include <type_traits>

namespace nih
{
    template <typename T>
    class DataProperty
    {
    private:
        typedef typename std::remove_reference<T>::type type;
        typedef typename std::shared_ptr<type> ptr;

    public:
        // For shared_ptr
        DataProperty (const ptr &data = ptr (new type)) : data (data) {}

        // For unmanaged ptrs (pass shared_ptr an empty destructor)
        DataProperty (T *data) : data (data, [](T*){}) {}

        DataProperty (const DataProperty &) = default;

        // setter
        template <typename U>
        void operator() (U &&value) {*data = std::forward<U> (value);}

        // getter
        const T &operator() () const {return *data;}

    private:
        std::shared_ptr<type> data;
    };


    template <typename T>
    class ROProperty
    {
    private:
        typedef typename std::remove_reference<T>::type type;
        std::function<T()> getter;

    public:
        ROProperty (std::function<T()> getter) : getter (getter) {}
        ROProperty (const ROProperty &) = delete;

        T operator() () const {return getter();}
        operator T () const {return getter();}
    };


    template <typename T>
    class WOProperty
    {
    public:
        typedef typename std::remove_reference<T>::type type;

        WOProperty (std::function<void(T)> setter) : setter (setter) {}
        WOProperty (const WOProperty<T> &) = delete;
        WOProperty &operator= (const WOProperty &) = delete;

        template <typename U>
        void operator() (U &&value) {setter (std::forward<U> (value));}

        template <typename U>
        U &&operator= (U &&value) {setter (std::forward<U> (value));}

    private:
        std::function<void(T)> setter;
    };


    template <typename T>
    class Property : public ROProperty<T>, public WOProperty<T>
    {
    public:
        Property (std::function<T()> getter,
                  std::function<void (T)> setter) :
            ROProperty<T> (getter),
            WOProperty<T> (setter) {}

        Property (DataProperty<T> backend = DataProperty<T> ()) :
            ROProperty<T> (backend),
            WOProperty<T> (backend) {}

        Property (const Property &) = delete;
        Property &operator= (const Property &) = delete;

        using WOProperty<T>::operator();
        using WOProperty<T>::operator=;
        using ROProperty<T>::operator();
        using ROProperty<T>::operator T;

        // TODO: overload operators for r/w things, e.g. +=, -= /= *=
    };
}

#endif  // _NIHPP_PROPERTY_HH
