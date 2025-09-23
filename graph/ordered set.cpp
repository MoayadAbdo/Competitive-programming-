// C++ program to demonstrate the
// ordered set in GNU C++
#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// Driver program to test above functions
int main()
{
    // Ordered set declared with name o_set 
    //O(logn) each
    ordered_set o_set;

    // insert function to insert in
    // ordered set same as SET STL
    o_set.insert(5);
    o_set.insert(1);
    o_set.insert(2);

    // Finding the second smallest element
    // in the set using * because
    //  find_by_order returns an iterator
    cout << *(o_set.find_by_order(1)) 
         << endl;

    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4) 
         << endl;

    // Finding the count of elements less 
    // than or equal to 4 i.e. strictly less
    // than 5 if integers are present
    cout << o_set.order_of_key(5) 
         << endl;

    // Deleting 2 from the set if it exists
    if (o_set.find(2) != o_set.end())
        o_set.erase(o_set.find(2));

    // Now after deleting 2 from the set
    // Finding the second smallest element in the set
    cout << *(o_set.find_by_order(1)) 
         << endl;

    // Finding the number of
    // elements strictly less than k=4
    cout << o_set.order_of_key(4) 
         << endl;

    return 0;
}

ordered_set s;
s.insert(8);
*(s.find_by_order(0)
s.order_of_key(8)
if (s.find(2) != s.end()) 
    s.erase(s.find(2)); 
*/



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class OrderedSet {
private:
    typedef tree<long long,
            null_type,
            less_equal<long long>,
            rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;
    ordered_set s;
 
public:
    void Insert(long long x) {
        s.insert(x);
    }
 
    bool Exist(long long x) {
        if (s.upper_bound(x) == s.end()) {
            return false;
        }
        return (*s.upper_bound(x)) == x;
    }
 
    void Erase(long long x) {
        if (Exist(x)) {
            s.erase(s.upper_bound(x));
        }
    }
 
    int Idx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        return s.order_of_key(x);
    }
 
    int LastIdx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        if (*s.find_by_order(s.size() - 1) == x) {
            return s.size() - 1;
        }
        return Idx(*s.lower_bound(x)) - 1;
    }
 
    long long Value(int index) {
        return *s.find_by_order(index);
    }
 
    int Count(long long x) {
        if (!Exist(x)) {
            return 0;
        }
        return LastIdx(x) - Idx(x) + 1;
    }
 
    void Clear() {
        s.clear();
    }
 
    int Size() {
        return s.size();
    }
 
    int Lower_bound(int x)
    {
 
            return *s.upper_bound(x);
    }
 
    int Upper_bound(int x)
    {
 
            return *s.lower_bound(x);
    }
};
