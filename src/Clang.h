/* This file is part of RTags.

   RTags is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   RTags is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with RTags.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef Clang_h
#define Clang_h

#include <Source.h>

class Clang
{
public:
    Clang() {}
    virtual ~Clang() {}
    bool index(const Source &source);

    struct Symbol {

    };

    enum RecurseMode {
        Abort,
        SkipChildren,
        RecurseChildren
    };
    virtual RecurseMode visit(const Symbol &symbol) { return RecurseChildren; }
};

#endif
