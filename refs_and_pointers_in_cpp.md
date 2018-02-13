Behind the scenes references are implemented using pointers. So, as far as the compiler is concerned references in C++ are just
const pointers. 

In order to prevent confusion, some things to keep in mind: 
1. In situations where a function does not alter its params of a built in or a pointer type, value params can be used. 
2. When a function explicitly must change the values of its arguments, a pointer param is preferred. These pointers should be
preferrably be the the function's intial params. 
3. When a function doesn't change the value of its class or struct type arguments, or if the modification of the argumemnt is 
a trivial side effect, references can be used. Const references should be used if the function doesn't modify the argument. 
4. References should be used to pass large objects to a function which may or may not change it. (use const if it doesn't change
the object) 

References could result in extremely "ugly" code. A function may return a reference to a variable, as in the following example: 

```
int &func()
{
  static int value;
  return value;
}

This allows the use of the following constructions: 

func() = 20;
func() += func();

### Rvalue references

The C++ ref should be considered an lvalue reference. They can be constrasted to rvalue references(notation `typename &&`)

`TO DO`
