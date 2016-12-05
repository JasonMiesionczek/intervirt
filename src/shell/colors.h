#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#include <ostream>
namespace Color {
    enum Code {
        FG_DEFAULT  = 39,
        FG_BLACK = 30, 
        FG_RED = 31, 
        FG_GREEN = 32, 
        FG_YELLOW = 33, 
        FG_BLUE = 34, 
        FG_MAGENTA = 35, 
        FG_CYAN = 36, 
        FG_LIGHT_GRAY = 37, 
        FG_DARK_GRAY = 90, 
        FG_LIGHT_RED = 91, 
        FG_LIGHT_GREEN = 92, 
        FG_LIGHT_YELLOW = 93, 
        FG_LIGHT_BLUE = 94, 
        FG_LIGHT_MAGENTA = 95, 
        FG_LIGHT_CYAN = 96, 
        FG_WHITE = 97, 
        BG_RED = 41, 
        BG_GREEN = 42, 
        BG_BLUE = 44, 
        BG_DEFAULT = 49,
        BOLD = 1,
        RESET = 0
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}


#endif  /* _COLORS_ */