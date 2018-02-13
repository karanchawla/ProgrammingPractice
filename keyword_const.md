## Using the Keyword const

```
char const *buf
```
buf is a pointer variable pointing to chars. Whatever is pointed to by buf may not be changed through buf, the chars are 
declared as const. The pointer buf itself however may be changed. 
```
char const *const buf
```
is also possible; here, neither the pointer not what it points to may be changed. 

#### Rule of thumbn for the placement of the keyword const is the following: whatever occurs to the left to the keyword may not
be changed. 
However, this rule produces conflicting results. A better definition or declaration should always be read from the variable or 
function identifier back to the type identifier.

"Buf is a const pointer to const characters."

READ POINTER DELARATIONS RIGHT TO LEFT. 

This advice can be improved upon in the following ways: 
1. start reading at the variable's name
2. read as dar as possible until you reach the end of the declaration or a closing paren 
3. return to the point where you started reading, and read backwards until you reach the begining of the declaration or a matchign
opening paren
4. if you reached an opening paren, cont. to step 2 beyond the paren where you prev stopped. 
