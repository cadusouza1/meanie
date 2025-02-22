# Meanie
*The means to an end*

## Introduction
**Meanie** is a simple command-line tool written in C that computes common means (arithmetic, geometric, etc.) of numbers provided via standard input. It's a handy utility for quick statistical calculations directly from your terminal.

**Note:** Future versions will support additional means and command-line switches to enhance user experience.

## Features
- Calculates common means:
  - Arithmetic Mean
  - Geometric Mean
  - Harmonic Mean
  - Weighted Arithmetic Mean
  - Median

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
This will compile the source code and produce an executable named `meanie`.

## Usage
You can run **Meanie** by providing numbers via standard input. Each line of input should contain numbers separated by spaces.
```bash
bin/meanie
```
Then enter your numbers, for example:
```
57 88 12 26 36 55 30 21 59 79
67 86 28 18 56 48 26 51 21 19
```
Press `Ctrl+D` to signal the end of input.

Alternatively, you can feed the input via stdin:
```bash
bin/meanie < test.txt
```

### Weighted Arithmetic Mean
For weighted arithmetic mean, provide numbers in pairs (value weight):
```
1 2 3 4  # First number (1) has weight 2, second number (3) has weight 4
```

## Command-Line Options
**Meanie** supports command-line switches to specify which means to calculate:

- `-a`: Calculate the **arithmetic mean**
- `-g`: Calculate the **geometric mean**
- `-h`: Calculate the **harmonic mean**
- `-w`: Calculate the **weighted arithmetic mean**
- `-m`: Calculate the **median**

**Note:** The order in which you specify the options determines the order of the output. If no options are provided, **Meanie** will calculate all available means in the default order.

## Development
### Running Tests
```bash
make test
```

### Cleaning Build Files
```bash
make clean
```

## Contributing
Contributions are welcome! Please feel free to submit issues or pull requests.

## Contact
For questions or suggestions, please open an issue on the [GitHub repository](https://github.com/cadusouza1/meanie.git)

## Acknowledgments
- Inspired by the need for quick statistical calculations in command-line environments.
