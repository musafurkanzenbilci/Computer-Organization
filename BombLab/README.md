# Bomb Lab

This repository contains the solution for the Bomb Lab of a computer organization class. The Bomb Lab is a reverse engineering exercise in which the goal is to defuse a "binary bomb" by analyzing its assembly code and identifying the correct inputs that will defuse it.

## Getting Started

1. Clone the repository and navigate to the bomb lab directory.
2. Compile the bomb binary using the command: `gcc -g -O2 -o bomb bomb.c`
3. Run the bomb binary using the command: `./bomb`
4. Use the gdb debug tool to analyze the assembly code and identify the correct inputs.
5. Once all the correct inputs have been found, enter them one at a time to defuse the bomb.

## Tips

- Use the `disas` command in gdb to disassemble the code and see the assembly instructions.
- Use the `break` command in gdb to set breakpoints at specific instructions.
- Use the `stepi` command in gdb to step through the instructions one at a time.
- Use the `info registers` command in gdb to see the values of the registers.
- Use the `x` command in gdb to examine memory at a specific address.
- Use the `info functions` command in gdb to see the list of functions in the binary.
- Use the `help` command in gdb to see a list of all the commands.

## Note

- The solution is provided for educational purposes only and should not be used for cheating or academic dishonesty.
- The solution provided may not be the only or the best way to solve the lab.
- The solution is based on the Bomb Lab provided by the Professor, the solution may not work with different versions or variations of the lab.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
