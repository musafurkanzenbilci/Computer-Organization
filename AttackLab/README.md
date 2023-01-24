# Attack Lab

This repository contains the solution for the Attack Lab of a computer organization class. The Attack Lab is a security exercise in which the goal is to exploit buffer overflow vulnerabilities and perform return-oriented attacks on vulnerable programs.

## Getting Started

1. Clone the repository and navigate to the attack lab directory.
2. Compile the vulnerable programs using the command: `make`
3. Use the gdb debug tool and the provided exploit scripts to perform buffer overflow and return-oriented attacks on the vulnerable programs.
4. Once the attacks have been successfully executed, the program will print out a flag indicating that the attack was successful.

## Tips

- Use the `info functions` command in gdb to see the list of functions in the binary.
- Use the `break *address` command in gdb to set a breakpoint at a specific memory address.
- Use the `x/x $esp` command in gdb to examine the top of the stack and find the location of the saved return address.
- Use the `pattern create` and `pattern offset` commands in gdb to create a unique input pattern and find the offset of the saved return address.
- Use the `find` command in gdb to search for a specific value in memory.
- Use the `shell` command in gdb to run shell commands.
- Use the `r < <(python -c "print 'A'*offset + 'B'*4 + 'C'*(1000-offset-4)")` command in gdb to feed the exploit input to the program.

## Note

- The solution is provided for educational purposes only and should not be used for cheating or academic dishonesty.
- The solution provided may not be the only or the best way to solve the lab.
- The solution is based on the Attack Lab provided by the Professor, the solution may not work with different versions or variations of the lab.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
