#ifndef SHARED
#define SHARED

#include "entry.h"
#include "verilogcode.h"
#include "verilogjjparser.h"

struct SharedState
{
  std::shared_ptr<Entry> current_root;
  std::shared_ptr<Entry> tempEntry;
  std::shared_ptr<Entry> lastEntity;
  std::shared_ptr<Entry> lastCompound;
  std::shared_ptr<Entry> current;
  std::string currName;
  std::string fileName;
  std::vector<std::shared_ptr<Entry>> shvec;
  VerilogCodeParser *m_Code = 0;
  DefineList defList;
  FileDef *fdd;

  void updateClassEntry()
  {
    if (shvec.empty())
    {
      lastEntity = NULL;
    }
    else
    {
      lastEntity = shvec.back();
    }
  }

  void insertClassEntry(std::shared_ptr<Entry> e)
  {
    shvec.emplace_back(e);
    updateClassEntry();
  }

  void delClassEntry()
  {
    if (!shvec.empty())
    {
      shvec.pop_back();
      updateClassEntry();
    }
  }

  QCString getClassName()
  {

    QCString q;

    if (shvec.empty())
    {
      return q;
    }

    if (shvec.size() == 1)
    {
      return shvec.at(0)->name;
    }

    if (shvec.size() == 2)
      return shvec.at(0)->name + "::" + shvec.at(1)->name;

    q = shvec.at(0)->name;

    for (size_t l = 1; l < shvec.size(); l++)
    {
      q.append("::");
      q.append(shvec.at(l)->name);
    }

    return q;
  }
};

#endif