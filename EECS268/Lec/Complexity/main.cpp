#include <iostream>
#include <cstring>
using namespace std;

struct a
{
    int b[2];
    string name[1];
};

int main()
{
    a a1;
    a1.b[0] = 666;
    a1.name[0] = "laotie";

    cout << a1.name[0] << a1.b[0] << endl;

    return 0;
}

/*
Time complexity
-Not clock-on-the-wall time
-but the number of instructions

Space complexity
-Memory allocations

Big-O Notation
-Identify if there is a problem size, n, that makes the time or space complexity scale a certain way
O(1) - constant complexity
O(n) - Linear complexity
O(n^2) - quadratic complexity (two loops on n / nested loops)

Array: 55|17|3|8|2|10|20

Bubble Sort (Iterative)
-按顺序两两交换，直到从小到大排列

Selection Sort (Iterative)
-(ascending order) Find the min value from index 0 to size-1, then swap that value into index 0 (repeat the process)

Insertion Sort (Iterative)
-break into sorted and unsorted section, expand sorted section (add one element every time) 比较排序 and shrink the unsorted section (repeat the process)

Merge Sort (recursive)
-uses two funcs
 1)recursive function in charge of bearking the array in half (individual element(array of size 1)) over and over (mid = size / 2)
 2)non-recursive (iterative) func called merge
 -Merge takes two arrays that is assumes to be already sorted, it then merges then into a single sorted array (将两个array的元素比较后合并)

Quick Sort (recursive)
-using a non-recursive helper function (Partition)
-To partition (隔断) an array
 1)Choose a pivot value
 2)Arrange all the values in the array such that everything less than the pivot value is on the left side of the pivot and everything greater than or equal to is on its right
 55 17 3 8 2 10 20 <- pivot value
 L           R
 swap
 10 17 3 8 2 55 20 <- pivot value
             LR
 swap
 10 17 3 8 2 20 55 <- pivot value 
 10 17 3 8 2 <- pivot value 20 55 
 L       R   
 2 <- pivot value 17 3 8 10 20 55 
 LR  

Complexity of Sorts
 Iterative Sorts
  TIem complexity (average case)    
  -Bubble, Selection, nad Insertion: O(n^2) NOTE:Certain cases can lead to better complexities (e.g. Bubble can achieve O(n))
  Space complexity (all cases)
  -Bubble, Selection, nad Insertion: O(1) (No buffers, just a function call)
 The complexity of a single call to partiton on an array of size n: O(n)
 Overall time complexity :O(n*(log 2 (n)))
 Space complexity: log 2 (n)

 Worst 
 Space: O(n)
 Time: O(n^2)

 To combat bad pivot, take the median of the first, middle, and last values in an array and make it the pivot

Recursive Sorts
 Merge Sort:
 1) Times to break: k = log 2 n
 2) Time Complecity: O(n)
    Space Complecity: O(n)

Overall Complecity


 

*/