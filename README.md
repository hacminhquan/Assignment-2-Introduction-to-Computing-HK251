# Assignment-2-Introduction-to-Computing-HK251
## Say It in Hawaiian (C++ String Processing)

<p align="center">
  <img src="https://img.shields.io/badge/C++-17-blue?logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/Focus-String%20Processing-lightgrey" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen" />
</p>

---

## Overview

This project implements a C++ program that processes Hawaiian words and evaluates them based on phonetic rules.

The assignment focuses on:

* Character-by-character string processing
* Rule-based validation
* Handling vowel groups and syllables
* Applying control structures (loops, conditionals)

According to the specification, Hawaiian words follow strict pronunciation rules using a limited alphabet and defined vowel combinations. 

---

## Objective

* Validate input using the Hawaiian alphabet
* Identify vowels, consonants, and special characters
* Detect vowel groups (e.g., ai, ae, ou, ui)
* Process the string sequentially without using replace()
* Compute syllables based on pronunciation rules

---

## Core Logic

### Valid Characters

Allowed:

* Vowels: a, e, i, o, u
* Consonants: p, k, h, l, m, n, w
* Special:

  * Space `' '`
  * Apostrophe `'`

Invalid characters cause immediate termination.

---

### Vowel Rules

Each vowel represents one syllable:

```text id="r9n3fx"
a → ah
e → eh
i → ee
o → oh
u → oo
```

---

### Vowel Groups

Special combinations form a single syllable:

```text id="p9c1ru"
ai, ae → eye
ao, au, ou → ow
ei → ay
eu → eh-oo
iu → ew
oi → oy
ui → ooey
```

---

### Processing Strategy

The program:

* Iterates through the string using an index
* Converts characters to lowercase
* Checks:

  * vowel
  * consonant
  * vowel pair
* Skips characters accordingly
* Counts syllables

From the implementation:

```cpp
for (size_t i = 0; i < s.size(); ) {
    ...
}
```

This ensures full control over index movement. 

---

## Features

* Case-insensitive input handling
* Efficient lookup using `unordered_set`
* Support for vowel groups
* Space and apostrophe preservation
* Early invalid input detection (returns -1)
* Linear time complexity O(n)

---

## Requirements

* C++17 compiler
* Standard libraries:

  * `<iostream>`
  * `<string>`
  * `<unordered_set>`
  * `<cctype>`

---

## How to Run

### Compile

```bash id="5rkjba"
g++ -std=c++17 hmq_hawaiiFinal.cpp -o main
```

### Run

```bash id="6rdy2l"
./main
```

---

## Input

Single line string:

```text id="px6x9v"
aloha
```

---

## Output

Example:

```text id="5j6zgs"
3
```

Meaning:

* The word contains 3 syllables

---

## Example Behavior

| Input  | Output |
| ------ | ------ |
| aloha  | 3      |
| maui   | 2      |
| keiki  | 2      |
| a'i    | 2      |
| abc123 | -1     |

---

## Project Structure

```text id="0u1ojq"
.
├── hmq_hawaiiFinal.cpp
├── 251_NMDT_Ass2_EN.pdf
└── README.md
```

---

## Key Concepts Demonstrated

* String traversal with manual indexing
* Pattern recognition (vowel groups)
* Use of hash sets for fast lookup
* Input validation
* Clean and efficient control flow

---

## Limitations

* Only counts syllables (does not output full pronunciation)
* Does not handle advanced linguistic exceptions
* No GUI or interactive interface

---

## Author

Hắc Minh Quân

---

## License

This project is intended for academic and educational use.

