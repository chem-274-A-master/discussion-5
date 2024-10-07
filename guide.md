Guide for Discussion 5
======================

C++ Const
---------

1. `const` is used:
  1. In returning a constant reference from the `get_component` function. This
     means the returned `Molecule` cannot be modified.
  2. The same function is marked `const` after the function arguments. This
     means the the `Reaction` object itself is not modified by this function.
  3. In the example code, a `const Molecule &` reference is created and
     set to the return value of a function call. This means that particular
     `Molecule` will not be modified.

2. Yes, you could have the `Molecule` object passed in as a constant
   reference. However, the function itself cannot be `const` as it must modify
   the `Reaction` object in order to work.

3. You can have it return a Molecule copy rather than a `const` reference. This
   may increase the memory requirements and be less performant, in some ways it
   can be safer as the returned `Molecule` is completely disconnected from the
   `Reaction` object.

4. It depends on how you want to design your class. This way, you can modify
   the `Molecule` that is returned in-place, but that can lead to unexpected
   behavior and inconsistencies. For example, changing the molecule would
   necessarily require changing it's coefficient, and users may forget to do that.

5. If the `Molecule` object that you are using the method on is `const`,
   the compiler will always use the first (`const`) one. Otherwise, it would
   use the second (non-`const`) version.


C++ Class Design
----------------

1. The main difference between C++ and Python classes is that C++ allows for
   very fine-grained access control via `private` and `public` methods and data.
   In addition, C++ classes can have multiple constructors, including copy
   constructors, whereas in Python you can only have one `__init__` function.

2. Some mistakes or bad decisions:

  1. `mol_` is of type `Molecule` but that is this class. There should be `coords_` and `num_atoms_`.

  2. Those fields should probably be `private`. In general, almost all data in a
     class is `private`.

  3. The second constructor handles a vector of coords. But what if the
     number of elements in the vector is not divisble by 3?

  4. `get_coords` returns a copy of the vector. This could be expensive if
     there is a large number of coordinates (although this could be safer).

  5. The `clear` function does not need to be called manually in the destructor - it
     will be done automatically.

3. Bonds could be represented as a vector of array or tuple. The array or tuple would contain the
   index of each atom, and then the bond order.

4. A flattened list is more performant, as all the memory is contiguous. The disadvantage is that
   indexing must be done manually - that is, you must map (atom, xyz) indices to a single number.

5. There are a lot. As mentioned above, bonding info might be nice. Translating/rotating the molecule,
   or computing various distances between atoms could be useful. Because there are constructors, you also
   probably want a copy constructor. 

6. See #2


C++ Templates
-------------

1. The difference is that all the info must be available at compile time for templates, but not for simply passing
   in an argument. So you can't use it to print a number a user gives you, for example.

2. It's used in `std::array`. The second part of the template is the size (ie, `std::array<int, 3>`)

3. ```C++
template<int I>
int factorial()
{
  int fac = 1;
  for(int i = 1; i <= I; i++)
    fac = fac * i;

  return fac;
}

int main(void)
{
  int f = factorial<5>();
  std::cout << "5! = " << f << std::endl;
}
```


4. ```C++
template<int I>
int factorial()
{
  return I*factorial<I-1>();
}

template<>
int factorial<0>()
{
  return 1;
}

int main(void)
{
  int f = factorial<7>();
  std::cout << "7! = " << f << std::endl;
}
```
