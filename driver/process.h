#pragma once

class Process final {
  HANDLE process_;

public:
  Process(HANDLE Pid, ACCESS_MASK desiredAccess);
  ~Process();
  operator bool() const;
  operator HANDLE() const;
};

class EProcess final {
  PEPROCESS obj_;

public:
  EProcess(HANDLE Pid);
  ~EProcess();
  operator bool() const;
  operator PKPROCESS();
  const char *ProcessName() const;
  void *SectionBase() const;
  void SearchVad(const wchar_t *filename) const;
};

class EThread final {
  PETHREAD obj_;

public:
  EThread(HANDLE Tid);
  ~EThread();
  operator bool() const;
  operator PKTHREAD();
  int CountThreadList() const;
};
