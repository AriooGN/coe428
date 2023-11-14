Question 1:

So since the betterSort function has 3 paramenters and we want to implement it into mySort, what we could do is set the "first" perameter to zero as in our case we want to sort the whole array so it needs to start at the first index.
Next we can pass through the numbOfElements variable through to the "last perameter", so it sorts till the end of the array. and lastly pass the array through the first parameter.

Eg.

mySort(int d[], unsigned int n){

	betterSort(d[], 0, n);
}

Comments:

Everything works perfectly. The first parts commands is "testSort" and the second parts commands is "testSort2".

-Arian Fooladray
