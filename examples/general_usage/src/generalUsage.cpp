#include <cstdio>
#include <cwchar>
#include <cado/errors.hpp>
#include <io.h>
#include <fcntl.h>
using namespace cado::errors;

Error fooerr("im foo error");

void foo(Error &err) {
  Errors::MakeReferenceOf(err, fooerr);
  return;
}

class A {
public:
  A() {
    barerr = Error("im bar error");
  }    
  Error barerr;
  void bar(Error &err) {
    //Errors::MakeReferenceOf(err, barerr);
    err = Error(barerr);
    return;
  }
};


WError foowerr = Errors::Format(L"im wfoo error, %s", L"АБВГ");

void wfoo(WError &err) {
  Errors::MakeReferenceOf(err, foowerr);
  return;
}

class WA {
public:
  WA() {
    barwerr = Errors::Format(L"im wbar error, %s", L"世界");
  }    
  WError barwerr;
  void bar(WError &err) {
    Errors::MakeReferenceOf(err, barwerr);
    return;
  }    
};

int wmain(int argc, wchar_t* argv[]) {
  //_setmode(_fileno(stdout), _O_U8TEXT);
  Error err;
  printf("%d\n", err.Is());
  foo(err);
  printf("%d %d %s\n", err.Is(), err == fooerr, err.What().c_str());
  A a;
  a.bar(err);
  printf("%d %d %d %s\n", err.Is(), err == fooerr, Errors::IsReferenceOf(err, a.barerr) ,err.What().c_str());
  //printf("%d %d %d %s\n", err.Is(), err == fooerr, err == a.barerr ,err.What().c_str());
  _setmode(_fileno(stdout), _O_U16TEXT);
  WError werr;
  wprintf(L"%d\n", werr.Is());
  wfoo(werr);
  wprintf(L"%d %d %s\n", werr.Is(), werr == foowerr, werr.What().c_str());
  WA wa;
  wa.bar(werr);
  wprintf(L"%d %d %d %s\n", werr.Is(), werr == foowerr, Errors::IsReferenceOf(werr, wa.barwerr) ,werr.What().c_str());
  return 0;
  }  
