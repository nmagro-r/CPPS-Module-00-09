*This project has been created as part of the 42 curriculum by nmagro-r.*

# CPP Modules 00-09

Ten modules and 35 exercises that go from a first class to the STL in C++98. This is where I moved from C to object-oriented programming.

## Description

Each module focuses on one part of the language:

| Module | Topic | What is in it |
|---|---|---|
| [CPP00](CPP00) | Classes and member functions | `megaphone`, `PhoneBook` |
| [CPP01](CPP01) | Memory, references, pointers to members, file streams | `Zombie`, `Weapon` with `HumanA` and `HumanB`, `Harl` |
| [CPP02](CPP02) | Operator overloading and canonical form | `Fixed`, a fixed-point number class |
| [CPP03](CPP03) | Inheritance, including the diamond problem | `ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap` |
| [CPP04](CPP04) | Polymorphism, deep copies, abstract classes | `Animal`, `Dog`, `Cat`, `Brain` |
| [CPP05](CPP05) | Exceptions | `Bureaucrat`, `AForm`, `Intern` |
| [CPP06](CPP06) | C++ casts | `ScalarConverter`, `Serializer`, type identification |
| [CPP07](CPP07) | Templates | `swap`, `min`, `max`, `iter`, `Array` |
| [CPP08](CPP08) | STL containers, iterators and algorithms | `easyfind`, `Span`, `MutantStack` |
| [CPP09](CPP09) | The STL applied to real problems | See below |

## Instructions

Each exercise is self-contained, with its own Makefile. All of them compile with GCC 12 and Clang 14 using `-Wall -Wextra -Werror -std=c++98`.

```bash
cd CPP09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

```
42
```

## Three exercises worth a look

**`CPP03/ex03`: the diamond.** `DiamondTrap` inherits from both `ScavTrap` and `FragTrap`, which both inherit from `ClapTrap`. Without virtual inheritance it would contain two separate `ClapTrap` objects.

**`CPP06/ex02`: finding a type at runtime.** It uses `dynamic_cast` to work out which class is really behind a `Base` pointer or reference.

**`CPP09`: choosing a container for the job.**

- `ex00`, `btc`: finds the value of a quantity of bitcoin on a given date. Rates are kept in a `std::map`, which makes it easy to find the closest earlier date when there is no exact match. It reads the `data.csv` database provided with the project, which is not included here.
- `ex01`, `RPN`: a calculator for Reverse Polish Notation built on a `std::stack`.
- `ex02`, `PmergeMe`: sorts positive integers by merge-insertion. It groups the values in pairs, sorts the larger value of each pair recursively, then inserts the smaller values with binary search. It runs the same algorithm on a `std::vector` and a `std::deque` and prints how long each one took:

```
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 8 us
Time to process a range of 5 elements with std::deque : 10 us
```

## Resources

### References

- [cppreference](https://en.cppreference.com/w/cpp)
- [The rule of three](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Merge-insertion sort on Wikipedia](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Reverse Polish notation on Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation)

### AI Usage

AI assistants were used for two tasks, always with me reviewing and testing the result:

- **Bug fixing and cleanup:** making every exercise compile with both GCC and Clang, and removing compiled files from the repository.
- **Documentation:** this README, checked against the code.

The design decisions were mine, and I can explain every part of the code.
