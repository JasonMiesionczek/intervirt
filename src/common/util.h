#ifndef INTERVIRTUTIL_H
#define INTERVIRTUTIL_H

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>

#define MKSHRD(T, PARAMS...) \
    std::make_shared<T>(PARAMS)

#define SHRDPTR(T) \
    std::shared_ptr<T>

#endif /* INTERVIRTUTIL_H */
