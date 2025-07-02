# Password Strength Checker in C

This project is a terminal-based password evaluation and storage system implemented in the C programming language. It provides functionality to analyze user-supplied passwords based on predefined strength metrics, and stores those that meet security criteria in both memory and a persistent text file.

## Overview

The core purpose of this project is to demonstrate foundational programming techniques in C, including:

- Input validation and safe handling of user input
- Use of custom data structures (arrays and linked lists)
- Dynamic memory allocation
- File I/O for persistent storage
- Basic password strength analysis algorithms

Passwords that meet strong security requirements are stored in memory using a singly linked list and are also appended to a `passwords.txt` file for long-term storage across program executions.

## Features

- Evaluates passwords based on five key criteria:
  - Minimum length of 8 characters
  - Contains at least one uppercase letter
  - Contains at least one lowercase letter
  - Contains at least one numerical digit
  - Contains at least one special character from a defined set
- Categorizes password strength into five levels: very weak, weak, moderate, fair, and strong
- Accepts input interactively from the user via a menu-based interface
- Validates input to prevent crashes or unexpected behavior from invalid entries
- Stores strong passwords in a file (`passwords.txt`)
- Uses dynamic memory (linked list) to store session data for efficient password listing

## Example Test Passwords

| Password        | Strength   |
|-----------------|------------|
| `1234567`       | Weak       |
| `Hello123`      | Moderate   |
| `pass@123`      | Fair       |
| `Strong1!`      | Strong     |
| `P@ssw0rd2025`  | Strong     |