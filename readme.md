# Password Strength Checker (C Language)

A simple terminal-based program in C that checks the strength of user-entered passwords. Strong passwords are stored in memory and saved to a `passwords.txt` file so they persist across runs.

## Features

- Password strength checks:
  - Minimum length (8+ characters)
  - At least one uppercase letter
  - At least one lowercase letter
  - At least one digit
  - At least one special character
- Saves strong passwords to a local `passwords.txt` file
- Stores passwords in memory using a linked list
- Handles invalid menu input gracefully

## How to Run

1. Make sure you have a C compiler installed (like `gcc`, `clang`, or an IDE like Code::Blocks).
2. Compile the code using your preferred method.
3. Run the compiled executable.

## Example Test Passwords

| Password        | Strength   |
|-----------------|------------|
| `1234567`       | Weak       |
| `Hello123`      | Moderate   |
| `pass@123`      | Fair       |
| `Strong1!`      | Strong     |
| `P@ssw0rd2025`  | Strong     |