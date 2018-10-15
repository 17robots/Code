#include "myString.hpp"
#include <cstring>
#include <iosfwd>
#include <string>
#include <iostream>
#include <cassert>

using namespace umm;

struct Test_string
{
  void default_ctor()
  {
    // Check the default contructor.
    myString s;
    assert(s.empty());
  }

  void string_ctor()
  {
    char const* str = "hello";
    myString s = str;
    assert(s.data() != str);
    assert(strcmp(s.data(), str) == 0);
  }


  void copy_ctor()
  {
    myString s1 = "hello";
    myString s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  void copy_assign()
  {
    myString s1 = "hello";
    myString s2;
    s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  void string_assign()
  {
    myString s;
    s = "hello";
    assert(!strcmp(s.data(), "hello"));
  }

  void self_assign()
  {
    myString s1 = "hello";
    s1 = s1;
  }

  void empty()
  {
    myString const s1;
    assert(s1.empty());
    myString const s2 = "";
    assert(s2.empty());
  }

  void access()
  {
    myString s1 = "hello";
    s1[0] = 'a';
    assert(s1[0] == 'a');

    myString const s2 = "test";
    assert(s2[0] == 't');

    // assert(s1[-1]);
    // assert(s2[-1]);
  }

  void find()
  {
    myString const s1 = "abcdef";
    assert(s1.find('c') == 2);
    assert(s1.find('z') == s1.npos);
  }

  void substr()
  {
    myString const s1 = "abcdef";
    myString s2 = s1.substr(0, 3);
    myString s3 = s1.substr(3, 6);
    assert (s2 == "abc");
    assert (s3 == "def");
  }

  void equality()
  {
    myString const s1 = "hello";
    myString const s2 = "goodbye";
    assert(s1 == s1);
    assert(s1 != s2);
  }

  void ordering()
  {
    myString s1 = "abc";
    myString s2 = "def";
    assert(s1 < s2);
    assert(s2 > s1);
    assert(s1 <= s1);
    assert(s1 >= s1);
  }

  void concatenation()
  {
    myString s1 = "abc";
    myString s2 = "def";
    myString s3 = s1 + s2;
    myString s4 = "abcdef";
    assert(s3 == s4);
  }

  void self_concatenation()
  {
    myString s1 = "abc";
    s1 += s1;
    myString s2 = "abcabc";
    assert(s1 == s2);
  }

  // The assert test runner for this test class.
  void run()
  {
    default_ctor();
    string_ctor();

    copy_assign();
    string_assign();
    self_assign();
    empty();
    access();
    find();
    substr();
    equality();
    ordering();
    concatenation();
    self_concatenation();
  }
};


int
main()
{
  Test_string test;
  test.run();
  return 0;
}
