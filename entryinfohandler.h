#ifndef ENTRYINFOHANDLER_H
#define ENTRYINFOHANDLER_H

#include "templateeventhandler.h"
#include <utility>
#include <vector>

class EntryInfo;

namespace Templar {

class EntryInfoHandler : public TemplateEventHandler
{
public:
    EntryInfoHandler(EntryInfo */*entryInfo*/) /*todo: unused : entryInfo(entryInfo)*/ {}
    virtual ~EntryInfoHandler() {}

    void handleEvent(const TraceEntry &entry);
    void undoEvent();
    void reset();
    void inspect(const TraceEntry& entry);
    void forward(const std::vector<TraceEntry> &vec);
    void rewind(unsigned int);

private:
    void showEntry(const TraceEntry &entry);

private:
    //todo: unused EntryInfo *entryInfo;

    std::vector<TraceEntry> undoStack;
};

} // namespace Templar

#endif // ENTRYINFOHANDLER_H
