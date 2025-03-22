#ifndef AUTOPTR_H
#define AUTOPTR_H

namespace atlas {
    template <typename T>
    class auto_ptr {
    private:
        T* m_ptr; 
    public:
        explicit auto_ptr(T* p = nullptr);
        ~auto_ptr();

        auto_ptr(auto_ptr&);
        auto_ptr& operator=(auto_ptr&);

        T& operator*() const;

        T* operator->() const;
        T* get() const;
        T* release();
        void reset(T* p = nullptr);
    };
} // namespace atlas

#include "auto_ptr.cpp"

#endif
