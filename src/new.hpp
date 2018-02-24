//
// Created by Eric Yanush on 2018-02-22.
//

#ifndef FERMTROLLER_NEW_HPP
#define FERMTROLLER_NEW_HPP

// Default placement versions of operator new.
inline void* operator new(std::size_t, void* __p) throw() { return __p; }
inline void* operator new[](std::size_t, void* __p) throw() { return __p; }

// Default placement versions of operator delete.
inline void  operator delete  (void*, void*) throw() { }
inline void  operator delete[](void*, void*) throw() { }

#endif //FERMTROLLER_NEW_HPP
