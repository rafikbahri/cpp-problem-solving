# C++ Pointers Tricky Parts - Quick Reference

A comprehensive guide to common pitfalls and tricky aspects of C++ programming.

---

## 1. Pointers and Memory Management

### Always Initialize Pointers
```cpp
// ❌ WRONG - Undefined behavior
int* ptr;
*ptr = 5;  // Could crash or corrupt memory

Solution* sol;
sol->method();  // Bus error or segmentation fault

// ✅ RIGHT
int* ptr = nullptr;
if (ptr) *ptr = 5;  // Safe check

Solution sol;  // Stack allocation (preferred)
sol.method();

Solution* sol = new Solution();  // Heap allocation
sol->method();
delete sol;  // Must cleanup!
```

### Stack vs Heap Allocation
```cpp
// Stack (automatic cleanup, faster)
Solution sol;
TreeNode node(5);

// Heap (manual cleanup, flexible lifetime)
Solution* sol = new Solution();
TreeNode* node = new TreeNode(5);
delete sol;
delete node;
```

**Rule of thumb**: Use stack allocation unless you specifically need heap allocation.

---

## 2. Common Memory Errors

### Null Pointer Dereference
```cpp
TreeNode* root = nullptr;
cout << root->val;  // ❌ Crash!

// ✅ Always check
if (root) {
    cout << root->val;
}
```

### Use After Free
```cpp
TreeNode* node = new TreeNode(5);
delete node;
cout << node->val;  // ❌ Undefined behavior!

// ✅ Set to nullptr after delete
delete node;
node = nullptr;
```

### Memory Leaks
```cpp
// ❌ Memory leak
void createTree() {
    TreeNode* root = new TreeNode(5);
    // Function ends, pointer lost, memory never freed
}

// ✅ Clean up before function ends
void createTree() {
    TreeNode* root = new TreeNode(5);
    // ... use root ...
    delete root;
}
```

### Dangling Pointers
```cpp
TreeNode* getNode() {
    TreeNode node(5);  // Stack allocated
    return &node;      // ❌ Returns address of destroyed object
}

// ✅ Return heap-allocated or by value
TreeNode* getNode() {
    return new TreeNode(5);  // Caller must delete
}
```

---

## 3. References vs Pointers

```cpp
// Pointer (can be null, can be reassigned)
TreeNode* ptr = nullptr;
ptr = new TreeNode(5);
ptr = new TreeNode(10);  // Can point to different objects

// Reference (must be initialized, cannot be reassigned)
TreeNode node(5);
TreeNode& ref = node;  // Must initialize
// ref = anotherNode;  // This copies values, doesn't rebind reference
```

**When to use what:**
- **Reference**: When you need an alias that always refers to the same object
- **Pointer**: When you need nullability or reassignment

---

## 4. Pass by Value vs Reference vs Pointer

```cpp
// Pass by value (copies the object)
void func1(TreeNode node) {  // Expensive for large objects
    node.val = 10;  // Modifies local copy
}

// Pass by reference (no copy, can modify original)
void func2(TreeNode& node) {  // Efficient
    node.val = 10;  // Modifies original
}

// Pass by const reference (no copy, cannot modify)
void func3(const TreeNode& node) {  // Efficient and safe
    cout << node.val;  // Read only
}

// Pass by pointer (can be null, can modify)
void func4(TreeNode* node) {
    if (node) node->val = 10;
}
```

**Best practices:**
- Use **const reference** for read-only large objects
- Use **reference** when you need to modify
- Use **pointer** when null is a valid input
- Use **value** only for small types (int, bool, etc.)

---

## 5. Constructors and Initialization

### Member Initialization List
```cpp
// ❌ Less efficient
TreeNode(int x) {
    val = x;  // Assignment after default construction
    left = nullptr;
    right = nullptr;
}

// ✅ More efficient
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    // Direct initialization
}
```

### Default Member Values (C++11)
```cpp
class Solution {
public:
    int count = 0;      // ✅ Default initialized
    int res = 0;
    vector<int> arr;    // Empty vector by default
};
```

---

## 6. The `this` Pointer

```cpp
class Solution {
public:
    int val;
    
    void setValue(int val) {
        this->val = val;  // Disambiguate parameter from member
    }
    
    Solution* getThis() {
        return this;  // Return pointer to current object
    }
};
```

---

## 7. Undefined Behavior (UB)

### What is Undefined Behavior?
Code that compiles but has unpredictable behavior. It might:
- Work perfectly
- Crash immediately
- Crash randomly
- Corrupt data silently
- Work in debug but fail in release

### Common Sources of UB
```cpp
// Uninitialized variables
int x;
cout << x;  // ❌ UB

// Out of bounds access
int arr[5];
arr[10] = 5;  // ❌ UB

// Dereferencing invalid pointers
int* ptr;
*ptr = 5;  // ❌ UB

// Accessing deleted memory
int* ptr = new int(5);
delete ptr;
cout << *ptr;  // ❌ UB

// Integer overflow (signed)
int x = INT_MAX;
x++;  // ❌ UB
```

---

## 8. Vector Pitfalls

### Iterator Invalidation
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// ❌ Iterator invalidated after push_back
for (auto it = v.begin(); it != v.end(); ++it) {
    v.push_back(*it);  // May invalidate iterator!
}

// ✅ Use index-based loop
for (size_t i = 0; i < v.size(); ++i) {
    // Be careful: size() changes during loop
}
```

### Out of Bounds Access
```cpp
vector<int> v = {1, 2, 3};

v[5] = 10;     // ❌ UB - no bounds checking
v.at(5) = 10;  // ✅ Throws exception
```

---

## 9. Common Runtime Errors

### Segmentation Fault (Segfault)
- Accessing memory you don't have permission to access
- Dereferencing null or invalid pointers
- Stack overflow (infinite recursion)

```cpp
int* ptr = nullptr;
*ptr = 5;  // Segfault
```

### Bus Error
- Misaligned memory access
- Accessing freed memory
- Hardware memory issues

```cpp
char buffer[10];
int* ptr = (int*)(buffer + 1);  // Misaligned
*ptr = 5;  // May cause bus error on some architectures
```

### Stack Overflow
```cpp
void recursive() {
    recursive();  // Infinite recursion → stack overflow
}
```

---

## 10. Class Member Variables

### Static vs Instance Members
```cpp
class Solution {
public:
    int instanceVar;           // Each object has its own copy
    static int staticVar;      // Shared across all objects
    
    void instanceMethod() {    // Needs an object to call
        cout << instanceVar;
    }
    
    static void staticMethod() {  // Can call without object
        cout << staticVar;
        // cout << instanceVar;  // ❌ Error: no 'this' pointer
    }
};

// Must define static members outside class
int Solution::staticVar = 0;
```

---

## 11. Const Correctness

```cpp
class TreeNode {
public:
    int val;
    
    // Non-const method (can modify object)
    void setValue(int v) {
        val = v;
    }
    
    // Const method (cannot modify object)
    int getValue() const {
        return val;
    }
};

// Const object
const TreeNode node(5);
node.getValue();   // ✅ OK
node.setValue(10); // ❌ Error: cannot call non-const method
```

---

## 12. Array Decay

```cpp
void printSize(int arr[]) {
    // arr is actually a pointer here!
    cout << sizeof(arr);  // Size of pointer, not array
}

int main() {
    int arr[10];
    cout << sizeof(arr);  // 40 (10 * 4 bytes)
    printSize(arr);       // 8 (pointer size on 64-bit)
}
```

**Solution**: Pass size explicitly or use `std::array`/`std::vector`

---

## 13. Common Compilation Errors vs Runtime Errors

### Compilation Errors (Caught by Compiler)
- Syntax errors
- Type mismatches
- Undeclared variables
- Missing semicolons

### Runtime Errors (Not Caught Until Execution)
- Null pointer dereference
- Out of bounds access
- Division by zero
- Stack overflow
- Memory leaks (not an error, but a problem)

---

## 14. Debugging Tools

### Compiler Warnings
```bash
g++ -Wall -Wextra -Wpedantic your_code.cpp
```

### Address Sanitizer (Detects Memory Errors)
```bash
g++ -fsanitize=address -g your_code.cpp
./a.out
```

### Valgrind (Memory Leak Detection)
```bash
valgrind --leak-check=full ./your_program
```

### GDB (Debugger)
```bash
g++ -g your_code.cpp
gdb ./a.out
```

---

## 15. Best Practices Summary

1. **Always initialize variables and pointers**
2. **Prefer stack allocation over heap allocation**
3. **Use smart pointers (`unique_ptr`, `shared_ptr`) for automatic memory management**
4. **Check pointers before dereferencing**
5. **Use const correctness**
6. **Pass large objects by reference, not by value**
7. **Enable compiler warnings and use sanitizers**
8. **Clean up all allocated memory (or use RAII)**
9. **Avoid manual memory management when possible (use STL containers)**
10. **When in doubt, prefer simplicity over clever code**

---

## Quick Checklist Before Running Code

- [ ] All pointers initialized?
- [ ] All allocated memory freed?
- [ ] No dangling pointers?
- [ ] Bounds checked for arrays/vectors?
- [ ] References properly initialized?
- [ ] No infinite recursion?
- [ ] Compiled with warnings enabled?

---

## When Things Go Wrong

1. **Enable compiler warnings**: `g++ -Wall -Wextra`
2. **Use Address Sanitizer**: `g++ -fsanitize=address -g`
3. **Run with debugger**: `gdb ./your_program`
4. **Check for memory leaks**: `valgrind ./your_program`
5. **Add print statements** to trace execution
6. **Simplify code** to isolate the problem

---

*Remember: If your code "works" but you're not sure why, it's probably relying on undefined behavior!*