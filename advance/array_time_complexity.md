The time complexity of the methods in the 'array' class can be explained as follows:

1. Linear Search: The linear search method iterates through each element of the array until it finds the target element or reaches the end of the array. The time complexity of linear search is O(n), where n is the number of elements in the array.

2. Sorting: The sorting method used in the code is a simple bubble sort algorithm. Bubble sort compares adjacent elements and swaps them if they are in the wrong order. The time complexity of bubble sort is O(n^2) in the worst case, where n is the number of elements in the array.

3. Binary Search: The binary search method uses the binary search algorithm, which requires the array to be sorted in ascending order. Binary search compares the target element with the middle element of the array and halves the search range based on the comparison result. The time complexity of binary search is O(log n) in the best case, where n is the number of elements in the array.

4. Insertion: The insertion method iterates through the array to find the correct position for the new element and shifts the subsequent elements to make space. The time complexity of insertion is O(n), where n is the number of elements in the array.

5. Deletion by Index: The deletion by index method iterates through the array to find the element at the specified index and shifts the subsequent elements to fill the gap. The time complexity of deletion by index is O(n), where n is the number of elements in the array.

6. Deletion by Value: The deletion by value method uses the binary search algorithm to find the index of the first occurrence of the target value. After finding the index, it shifts the subsequent elements to fill the gap. The time complexity of deletion by value is O(log n) for the binary search and O(n) for shifting the elements, resulting in a total time complexity of O(n + log n) or O(n log n).

Please note that the time complexity of the deletion by value method depends on the implementation of the binary search algorithm. If the binary search algorithm is implemented with a time complexity of O(log n), then the deletion by value method will also have a time complexity of O(log n) for finding the index. However, the shifting of elements will still have a time complexity of O(n), resulting in a total time complexity of O(n + log n) or O(n log n).