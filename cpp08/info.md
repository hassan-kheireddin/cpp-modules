**Sequence Containers:**

    These containers maintain the order of elements as they are inserted. The elements are stored sequentially in memory. 

std::vector: 

    A dynamic array that grows automatically when new elements are added.
    Provides fast random access to elements using indices.
    Insertion at the end is efficient (amortized constant time), but insertion in the middle or front is slower.

std::deque (Double-Ended Queue): 

    Allows fast insertion and deletion at both the beginning and the end.

std::list: 

    A doubly-linked list where each element points to the next and previous elements.
    Insertion and deletion are efficient anywhere in the list, but random access is slow.


**Associative Containers:**

    These containers store elements in a specific order (usually sorted) and allow fast retrieval of elements based on keys.

std::set: 

    Stores unique elements in a sorted order.
    Implemented as a balanced binary search tree (e.g., Red-Black Tree).

std::multiset: 

    Similar to std::set, but allows duplicate elements.

std::map: 

    Stores key-value pairs in a sorted order based on the keys.
    Keys are unique, and values can be accessed using the corresponding key.

std::multimap: 

    Similar to std::map, but allows multiple values for the same key.


**Unordered Containers:**

    These containers use hash tables for storage and do not maintain any specific order of elements. They provide faster average-case performance for insertion, deletion, and lookup compared to associative containers.

std::unordered_set: 

    Stores unique elements in no particular order.
    Uses hashing for fast lookups.

std::unordered_multiset: 

    Similar to std::unordered_set, but allows duplicate elements

std::unordered_map: 

    Stores key-value pairs in no particular order.
    Keys are unique, and values can be accessed using the corresponding key.


Use std::vector when you need a dynamic array with fast random access.
Use std::deque when you need fast insertion/removal at both ends.
Use std::list when you need frequent insertions/deletions in the middle of the collection.
Use std::set/std::map when you need sorted elements or keys.
Use std::unordered_set/std::unordered_map when you need fast lookups and don't care about ordering.



**Overview of the <algorithm> Library**

These functions do not modify the elements in the range but may read or analyze them. 

    std::find: Finds the first occurrence of a value in a range.
    std::count: Counts occurrences of a specific value.
    std::equal: Compares two ranges for equality.
    std::mismatch: Finds the first mismatch between two ranges.
    std::search: Searches for a subsequence within a range.
     
These functions modify the elements in the range. 

    std::copy: Copies elements from one range to another.
    std::transform: Applies a function to a range and stores the result in another range.
    std::replace: Replaces occurrences of a value with another value.
    std::fill: Assigns a specific value to all elements in a range.
    std::remove: Removes elements equal to a specific value (logical removal).
     
These functions deal with sorting and partitioning. 

    std::sort: Sorts elements in ascending order.
    std::stable_sort: Sorts while maintaining the relative order of equivalent elements.
    std::partial_sort: Sorts the first N elements of a range.
    std::nth_element: Puts the nth element in its sorted position.
    std::merge: Merges two sorted ranges into one

These functions assume the input range is sorted. 

    std::binary_search: Checks if a value exists in a sorted range.
    std::lower_bound: Finds the first position where a value can be inserted without violating the order.
    std::upper_bound: Finds the last position where a value can be inserted without violating the order.
     

These functions maintain or manipulate a heap structure. 

    std::make_heap: Converts a range into a heap.
    std::push_heap: Adds an element to a heap.
    std::pop_heap: Removes the largest element from a heap.
    std::sort_heap: Sorts a heap.
     
These functions find minimum or maximum values. 

    std::min: Returns the smaller of two values.
    std::max: Returns the larger of two values.
    std::min_element: Finds the smallest element in a range.
    std::max_element: Finds the largest element in a range.
     