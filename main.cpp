#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol940;

/*
Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
*/
tuple<string, int>
testFixture1()
{
  return make_tuple("abc", 7);
}

/*
Input: "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
*/
tuple<string, int>
testFixture2()
{
  return make_tuple("aba", 6);
}

/*
Input: "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
*/
tuple<string, int>
testFixture3()
{
  return make_tuple("aaa", 3);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.distinct(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.distinct(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.distinct(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}