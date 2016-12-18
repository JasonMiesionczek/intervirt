#ifndef INTERVIRTUTIL_H
#define INTERVIRTUTIL_H

#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <spdlog/spdlog.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <vector>

#define MKSHRD(T, PARAMS...) std::make_shared<T>(PARAMS)

#define SHRDPTR(T) std::shared_ptr<T>

#endif /* INTERVIRTUTIL_H */
