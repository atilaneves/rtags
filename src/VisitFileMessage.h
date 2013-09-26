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

#ifndef VisitFileMessage_h
#define VisitFileMessage_h

#include <rct/Message.h>
#include <rct/String.h>
#include "ClientMessage.h"

class VisitFileMessage : public ClientMessage
{
public:
    enum { MessageId = VisitFileId };

    VisitFileMessage(const Path &file = Path(), const Path &project = Path(), uint64_t id = 0)
        : ClientMessage(MessageId), mFile(file), mProject(project), mId(id)
    {
    }

    Path project() const { return mProject; }
    Path file() const { return mFile; }
    uint64_t id() const { return mId; }
    void encode(Serializer &serializer) const { serializer << mProject << mFile << mId; }
    void decode(Deserializer &deserializer) { deserializer >> mProject >> mFile >> mId; }
private:
    Path mFile, mProject;
    uint64_t mId;
};

#endif