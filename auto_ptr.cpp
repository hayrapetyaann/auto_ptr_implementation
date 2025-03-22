#include "auto_ptr.h"

namespace atlas {
    template <typename T>
    auto_ptr<T>::auto_ptr(T* p) : m_ptr(p) {}

    template <typename T>
    auto_ptr<T>::~auto_ptr() {
        delete m_ptr;
    }

    template <typename T>
    auto_ptr<T>::auto_ptr(auto_ptr& other) {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    template <typename T>
    auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr& other) {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    template <typename T>
    T& auto_ptr<T>::operator*() const {
        return *m_ptr;
    }

    template <typename T>
    T* auto_ptr<T>::operator->() const {
        return *m_ptr;
    }

    template <typename T>
    T* auto_ptr<T>::get() const {
        return m_ptr;
    }

    template <typename T>
    T* auto_ptr<T>::release() {
        delete m_ptr;
        m_ptr = nullptr;
    }

    template <typename T>
    void auto_ptr<T>::reset(T* p) {
        T* temp = m_ptr;
        m_ptr = p;
        delete temp;
        temp = nullptr;
    }
    
} // namespace atlas
