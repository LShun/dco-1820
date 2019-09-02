# C6: Inheritance & Polymorphism

## 1. Inheritance

- **Foundation principle of OOP**: Creation of hierarchical classification
- Define a **general class** that defines common traits to set of related items
- **Add properties and behaviors** unique to them

## 2. Superclass & Subclass

- **Subclass:** A class derived/inherited from another class
  - Inherits all data members & methods
  - Usually have more functionality than superclass
  - Inherits all `public` methods and variables. 
  - Do not inherit `private` method & variables.
    - However, those variables can be accessed via getter/setters declared in superclass.
    - Put it simply, unless an indirect method of accessing is already provided by the superclass, the subclass has no access to the `private` methods & variables in superclass.
- **Superclass:** A parent of a subclass

- `extends` keyword: Makes a subclass extend a superclass

  - Syntax:

    ```java
    class subClass extends superClass {
        ...
    }
    ```

    

## 3. Rationale for Inheritance

### 3.1 Reuse

- Allow reusing of code without starting from scratch
- May be slightly different, but can build on what is done previously

### 3.2 Class Hierarchy

- Allow building hierarchy among class

## Extra Notes

1. **A subclass** is not a subset of superclass. It **is an extension**, containing more information.
2. **Inheritance models the *is-a* relationship**. Must have *is-a* relationship between subclass and superclass.
3. **Only single inheritance** is allowed, multiple inheritance is not.

## 4. Superclass constructors

- **Not inherited** by subclass
- Each have own constructor (default/explicit)
  - Superclass constructor :tractor: superclass portion
  - Subclass constructor :tractor: subclass portion
- **Must be invoked** by subclass in first line either:
  - **implicit/automatic**: superclass *no-arg* constructor. Implicitly using `super()`.
    - Reason why to always have *no-arg* constructor in every class, prevents errors.
  - **explicit/manual**: Explicitly using `super(arguments)`

## 5. Constructor chaining

- Constructing an instance of class invokes all constructors up the entire inheritance chain

## 6. Overriding methods in superclass

- **Method overriding**: Define superclass methods with same return type signature under subclass
  - If return/signature different, then simply *overloaded*
- Calling methods from subclass **always refer to closest version** first.
- **Can only override accessible methods**, means cannot override `private`
  - `private` superclass methods are unrelated to methods in subclass
- Can override `static` methods
  - access superclass's via `SuperClassName.staticMethodName(args)`

## 7. Calling Superclass methods

- use `super` keyword: `super.methods(args)`
- `super` is similar to `this` except always refer to `superclass`

- **Can you invoke super.super.p()**? Answer: No, super can only go one level higher.

## `Object class`

- Implicit inheritance if no inheritance specified.

## 7.1 `toString()`

- returns string representation of object
- default: returns `ObjectClassName@ObjectHashCode`
- Usually override cause not helpful

## 7.2 `equals()`

- Compares contents of two objects

- Default:

  ```java
  public boolean equals(Object obj) {
      return (this == obj); // true if same reference
  }
  ```

### `==` comparison operator

- compare primitive data types
- determine if two objects same *references*
  - For *contents*, use `equals`

## 9. Polymorphism

- definition:
  - in Greek: of many forms
  - allow methods with same name but different behavior inside class
- a subclass is a specialization of superclass
  - *is-a relationship:* object of subclass like object  superclass
  - can assign subclass instance to reference variable of superclass
- enables extensible and maintainable design and implementation of problems
- **parametric polymorphism:** Object of subclass's type can be used whenever superclass's type value required.

- **dynamic blending**: Implementation determined dynamically by JVM at runtime. Closest, most suitable method is invoked. (Eg. when String is passed will use method that takes in String).
- **generic programming:** Writing methods that can be used generically for wide range of arguments. 
  - **example:** Passing subclass *objects* (i.e. Circle) to superclass *parameters* (i.e. `public int getInt(Object O)`)

###  10. Method Matching vs Binding

#### Method Matching

- **Matches method signature**
- Compiler finds matching method: same *parameter type, number, order* at compile time.

#### Method binding

- **dynamically bind** implementation to reference call.
- **actual class of object** referenced decides binding.

## 11. Casting Objects

- Converts one object to another

### Implicit Cast

- **Definition:** Casting performed by compiler without programmer's assistance. 
- Objects of *subclass* can be implicitly converted to object of *superclass*, A.K.A. **upcasted**
  - **Example:** `Object o = new Student();`
  - Keep in mind that `java.lang.Object` is implicitly superclass if no explicit superclass is defined.

### Explicit casting

- **Definition:** Casting performed by the programmer.
- Objects of *superclass* must be explicitly converted to objects of *subclass*, A.K.A. **downcasted**
- Otherwise, compilation error will occur, because compiler cannot say for certain that is really an object of *subclass* (even though, you know it is, for certain)
- Example:
  - `Student b = (Student) o;`

### Downcasting Objects

- Casting an object of superclass to an object of subclass
- Must be done explicitly, otherwise will cause compilation error.
- Must have `is-a` relationship in between, otherwise `ClassCastException`
- Objects can only cast to own type or superclass (can go back and forth, but never to another subclass).
  - to check, use `instanceof` (yes, you read that right, no camel casing, similar to `elif`)

## 12. `protected` Modifier

- `protected` method, accessible by same package / subclasses

| Modifiers   | Visibility         |                              |                    |                    |
| ----------- | ------------------ | ---------------------------- | ------------------ | ------------------ |
|             | In any package     | Subclasses (outside package) | In same package    | In declaring class |
| `public`    | :heavy_check_mark: | :heavy_check_mark:           | :heavy_check_mark: | :heavy_check_mark: |
| `protected` | :x:                | :heavy_check_mark:           | :heavy_check_mark: | :heavy_check_mark: |
| `default`   | :x:                | :x:                          | :heavy_check_mark: | :heavy_check_mark: |
| `private`   | :x:                | :x:                          | :x:                | :heavy_check_mark: |

## 13. `final` modifier - extra

- cannot be extended
- is a constant
- cannot be overridden by subclass