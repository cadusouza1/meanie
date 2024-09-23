# Meanie

*The means to an end*

## Introduction

**Meanie** is a simple command-line tool written in C that computes common means (arithmetic, geometric, etc.) of numbers provided via standard input. It's a handy utility for quick statistical calculations directly from your terminal.

**Note:** Future versions will support additional means and command-line switches to enhance user experience.

## Features

- Calculates common means
- Processes multiple lines of input
- Lightweight and easy to use

### Upcoming Features

- Support for more types of means (e.g., harmonic mean, quadratic mean)
- Command-line switches for customized calculations and output formatting

## Installation

### Prerequisites

- GCC compiler
- Make

### Build Instructions

Clone the repository and build the executable:

```bash
git clone https://github.com/yourusername/meanie.git
cd meanie
make
```

This will compile the source code and produce an executable named `meanie`.

## Usage

You can run **Meanie** by providing numbers via standard input. Each line of input should contain numbers separated by spaces.

```bash
./meanie
```

Then enter your numbers, for example:

```
57 88 12 26 36 55 30 21 59 79
67 86 28 18 56 48 26 51 21 19
```

Press `Ctrl+D` (Unix/Linux) or `Ctrl+Z` followed by `Enter` (Windows) to signal the end of input.

Alternatively, you can feed the input via stdin:

```bash
./meanie < test.txt
```

Where `test.txt` contains:

```
57 88 12 26 36 55 30 21 59 79
67 86 28 18 56 48 26 51 21 19
```

## Output

By default, **Meanie** outputs the calculated means in the following order:

1. **Arithmetic Mean**
2. **Geometric Mean**
3. *(More means will be added here in future updates)*

Each line of output corresponds to the means of the numbers on the respective input line, printed in the order specified above.

### Example Output

Given the input:

```
57 88 12 26 36 55 30 21 59 79
67 86 28 18 56 48 26 51 21 19
```

**Meanie** will output:

```
46.299999 39.436623
42.000000 36.441391
```

As more means are implemented, they will appear in this output sequence.

## Command-Line Options (Planned)

In future updates, **Meanie** will include command-line switches to specify:

- Which means to calculate (e.g., `--arithmetic`, `--geometric`, `--harmonic`)
- Input and output file paths
- Precision of the output
- Help and version information

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## Contact

For questions or suggestions, please open an issue on the [GitHub repository](https://github.com/cadusouza1/meanie.git)

## Acknowledgments

- Inspired by the need for quick statistical calculations in command-line environments.
