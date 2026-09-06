


// (Insertion Sort) INSERTION(A, N).
// This algorithm sorts the array A with N elements.
// 1. Set A[0] =  - infinity [Initializes sentinel element ]
// 2. Repeat Steps 3 to 5 for K = 2, 3, ..., N.
// 3. Set TEMP = A[K] and PTR = K-1.
// 4. Repeat while TEMP < A[PTR]:
// (a) Set A[PTR + 1] = A[PTR], [Moves element forward]
// (b) Set PTR = PTR - 1.
// [End of loop.]
// 5. Set A[PTR + 1] = TEMP. [Inserts element in proper place.]
// (End of Step 2 loop.]
// 6. Return