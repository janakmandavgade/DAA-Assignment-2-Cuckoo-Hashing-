# DAA Assignment 2 (Cuckoo Hashing)


##### Name     - Janak Mandavgade
##### Sec      - A
##### Roll No. - 43
##### Year/Sem - 3rd Yr/Vth Sem
##### Subject  - DAA
##### Branch   - CSE - 1

### PROBLEM STATEMENT

*Give an application and its implementation to demonstrate the use of the Cuckoo Hashing algorithm.*

### Working of Cuckoo Hashing

1. Cuckoo hashing applies the idea of multiple-choice and relocation together and guarantees O(1) worst case lookup time! 

2. Multiple-choice: We give a key two choices the h1(key) and h2(key) for residing.
3.Relocation: It may happen that h1(key) and h2(key) are preoccupied. This is resolved by imitating the Cuckoo bird: it pushes the other eggs or young out of the nest when it hatches. 
4. Analogously, inserting a new key into a cuckoo hashing table may push an older key to a different location. This leaves us with the problem of re-placing the older key. 
5. If the alternate position of older key is vacant, there is no problem.
6. Otherwise, the older key displaces another key. This continues until the procedure finds a vacant position, or enters a cycle. 
7. In the case of a cycle, new hash functions are chosen and the whole data structure is ‘rehashed’. Multiple rehashes might be necessary before Cuckoo succeeds.

### Example 

Let The I/P Array Be {20, 50, 53, 75, 100, 67, 105, 3, 36, 39}

Let the two hash functions be 1. h1(key) = key%11
                              2. h2(key) = (key/11)%11

Let's Insert 20 in first table

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch2.png)

Insert 50

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch3.png)

Insert 53 : h1(53) = 9. But 20 is already there at 9. We place 53 in table 1 & 20 in table 2 at h2(20) 

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch4.png)

Insert 75 :  h1(75) = 9. But 53 is already there at 9. We place 75 in table 1 & 53 in table 2 at h2(53) 

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch6.png)

Insert 100

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch.png)

Insert 67 : h1(67) = 1. But 100 is already there at 1. We place 67 in table 1 & 100 in table 2 

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch8.png)

Insert 105: h1(105) = 6. But 50 is already there at 6. We place 105 in table 1 & 50 in table 2 at h2(50) = 4. Now 53 has been displaced. h1(53) = 9. 75 displaced: h2(75) = 6.

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch9.png)

Insert 3

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch10.png)

Insert 36

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch11.png)

Insert 39 : h1(39) = 6. h2(105) = 9. h1(100) = 1. h2(67) = 6. h1(75) = 9. h2(53) = 4. h1(50) = 6. h2(39) = 3.

![Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ch12.png)

Application:

OTP(One Time Password Generation)
1. We First generate a requestID. 
2. We then generate an array based on the request id.
3. Then the array is passed to Cuckoo Hashing function where it hashes the array.
4. After that based on values in Hash table an OTP is generated.

Implementation:

Refer File in the repository, named OTPgenerator.cpp

