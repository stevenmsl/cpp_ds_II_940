#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol940;
using namespace std;

/*takeaways
  - use DP
    - count[0] number of distinct subsequences end with char 'a'
    - count[1] number of distinct subsequences end with char 'b'
    - count[25] number of distinct subsequences end with char 'z'

  - use S="aba" as an example
  - scan in S[0], we are looking at "a"
    - you have one subsequence end with 'a', which is "a"
    - total no. of subsequnces : count[0]=1
  - scan in S[1], we are looking at "ab"
    - we introduce one more subsequences (longer)that ends with 'b'
    - count[1] = (1 + all subsequences generated from "a" )
      - since we introduce a extra 'b' so all the previous subsequences
        can be extended by one letter 'b'
        - "a" -> "ab"
      - plus one: the single char 'b' we just introduced which
        itself is subsequence
    - count[1] = 2
      - b, ab
  - scan in S[2], we are now looking at "aba"
   - "a" -> "aa" (this is the plus one for)
     - this is the key that we can have distinct subsequnences
       - if there is no 'a' char introduced before the plus
         one means "a"
       - if there is 'a' char introduced before, the plus one
         means "aa"
   - count(0) = 1 + (count(0)+count(1))  = 1 + (1 +2) = 4
     - "aa", "a", "ba", "aba"
  - so find total you just add up all subsequences
    count(0) + count(1) = 4 +2 = 6

*/

int Solution::distinct(string S)
{
  const int mode = 1e9 + 7;
  auto count = vector<int>(26);

  for (auto c : S)
    count[c - 'a'] = accumulate(begin(count), end(count), 1L) % mode;

  return accumulate(begin(count), end(count), 0L) % mode;
}