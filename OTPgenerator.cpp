#include <bits/stdc++.h>

// upper bound on number of elements in our array
#define MAXN 11

// choices for position to insert our element in
#define ver 2

// An auxilary space (To reduce space complexity used MAXN)
int hashtable[ver][MAXN];

// Array to store possible positions for a key
int pos[ver];

// Initialise hash table with dummy values
void initTable()
{
    for (int j = 0; j < MAXN; j++)
        for (int i = 0; i < ver; i++)
            hashtable[i][j] = INT_MIN;
}

// returns the hashed value of a key(the position in the hash table where key can be placed)
int hash(int function, int key)
{
    switch (function)
    {
    case 1:
        return key % MAXN;
    case 2:
        return (key / MAXN) % MAXN;
    }
}

// It places the key in the appropriate position.If 1st array is full then shifts the current element into position defined by hash function in 2nd array and then inserts the element in the 1st array
void place(int key, int tableID, int cnt, int n)
{
    if (cnt == n)
    {
        return;
    }

    for (int i = 0; i < ver; i++)
    {
        pos[i] = hash(i + 1, key);
        if (hashtable[i][pos[i]] == key)
            return;
    }

    if (hashtable[tableID][pos[tableID]] != INT_MIN)
    {
        int dis = hashtable[tableID][pos[tableID]];
        hashtable[tableID][pos[tableID]] = key;
        place(dis, (tableID + 1) % ver, cnt + 1, n);
    }
    else
        hashtable[tableID][pos[tableID]] = key;
}

// prints our OTP(10 digits)(Position of the elements (if no element found then 0))

void printTable()
{

    for (int i = 0; i < ver; i++)
        for (int j = 0; j < MAXN; j++)
            (hashtable[i][j] == INT_MIN) ? printf("") :
                                         //  printf("%d ", hashtable[i][j]);
                printf("%d", j);

    // printf("\n");
}

//Main function that implements all the above functions
void cuckoo(int keys[], int n)
{
    //initialise hashtable
    initTable();

    //place keys in hashtable
    for (int i = 0, cnt = 0; i < n; i++, cnt = 0)
        place(keys[i], 0, cnt, n);

    //print OTP
    printTable();
}

// function to generate requestid(so that same otp is not sent for every same number)
std::string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
            "0123456789";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

int main()
{
    //user may need to input number but since we dont have database we cant store it. So directly we generate requestID and send OTP.
    std::string s = random_string(20);
    int keys_1[11];

    for (int i = 0, j = 0; i < s.size(), j < 10; i += 2, j++)
    {
        std::stringstream geek(s.substr(i, 2));
        int x = 0;
        geek >> x;
        keys_1[j] = x;
    }

    int n = sizeof(keys_1) / sizeof(int);

    cuckoo(keys_1, n);

    return 0;
}
