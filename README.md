# Meanie
*The means to an end*

## Introduction
**Meanie** is a simple command-line tool written in C that computes common
means (arithmetic, geometric, etc.) of numbers provided via standard input.

## Installation
### Prerequisites
- GCC
- Make
- Criterion (for running tests)

### Build Instructions
Clone the repository and build the executable:
```bash
git clone https://github.com/cadusouza1/meanie.git
cd meanie
make
```
This will compile the code and put the binary under the `bin/` directory

## Usage
You can run `meanie` by providing numbers via stdin. Each line of input should contain numbers separated by spaces.
`meanie` receiveis its numbers via `stdin`. Each line of input should contain numbers separated by your defined separator (defaults to ' '). 
```bash
bin/meanie
```
Then enter your numbers, for example:
```
57 88 12 26 36 55 30 21 59 79
67 86 28 18 56 48 26 51 21 19
```
Press `Ctrl+D` to signal the end of input.


Alternatively, you can specify what tokens separates lines and numbers themselves
```bash
bin/meanie --input-line-sep=- --input-sep=+
57+88+12+26+36+55+30+21+59+79-67+86+28+18+56+48+26+51+21+19
```
This will behave the same way as with normal white space and newlines

Also, you can specify what tokens separates lines and numbers on `stdout`
```bash
bin/meanie -a -w --output-line-sep=- --output-sep=+
1 2 3
4 5 6
Ctrl-D
2.000000+1.000000-5.000000+4.000000
```

### Weighted Arithmetic Mean
For weighted arithmetic mean, the numbers will be taken in pairs (value weight):
```
1 2 3 4  # First number (1) has weight 2, second number (3) has weight 4
```

## Command Line Options
**Note:** The order in which you specify the options determines the order of
the output, so
```bash
bin/meanie -a -w
```
will produce a different output from
```bash
bin/meanie -w -a
```

## Development
### Running Tests
```bash
make test
```

**Note:** Tests make use of some POSIX features. If you can't compile them,
check to see if you are on a POSIX compliant enviroment

### Cleaning Build Files
```bash
make clean
```

## Contributing
Contributions are welcome. Please feel free to submit issues or pull requests.

## Contact
For questions or suggestions, please open an issue on the [GitHub repository](https://github.com/cadusouza1/meanie.git)
