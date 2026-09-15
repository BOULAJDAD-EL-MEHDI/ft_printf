*This project has been created as part of the 42 curriculum by eboulajd.*

# ft_printf

A C static library that implements a subset of `printf`, writing formatted output directly to standard output with `write`. The project focuses on variadic functions, format parsing, recursive integer conversion, and accurate byte counting without allocating an output buffer.

```c
int ft_printf(const char *format, ...);
```

## Supported conversions

| Conversion | Argument type | Output |
| --- | --- | --- |
| `%c` | `int` (promoted character) | One byte, including a NUL byte |
| `%s` | `char *` | Characters up to the terminating NUL |
| `%d`, `%i` | `int` | Signed decimal |
| `%u` | `unsigned int` | Unsigned decimal |
| `%x` | `unsigned int` | Lowercase hexadecimal |
| `%X` | `unsigned int` | Uppercase hexadecimal |
| `%p` | `void *` | Lowercase hexadecimal address with `0x`; `(nil)` for null |
| `%%` | None | A literal `%` |

On success, `ft_printf` returns the number of bytes written, excluding string terminators. On a detected output failure, null format, or trailing unpaired `%`, it returns `-1`. Bytes already written remain visible.

### Scope and implementation details

- Flags, field widths, precision, length modifiers, floating point, and positional arguments are not implemented.
- A null `%s` argument produces no output. This is the existing project behavior; do not expect libc's platform-specific null-string placeholder.
- An unknown conversion consumes the `%` and the following character, emits nothing for that pair, and consumes no argument. For example, `ft_printf("a%qb")` prints `ab`. `ft_other_cases` exists separately but is not called by the parser.
- Arguments must match the format. Variadic arguments have no runtime type metadata, so missing arguments or incompatible types can cause undefined behavior.
- The implementation uses `long` for signed magnitudes and `unsigned long` for addresses. It targets Unix platforms where `long` is wider than `int` and can hold a pointer, as on the tested 64-bit Linux environment.

This repository does not include the project subject PDF. The behavior documented here describes the source, rather than claiming full libc compatibility or a particular subject revision's compliance.

## How it works

### Architecture and parsing

```text
Caller
  └── ft_printf(format, ...)
        ├── ordinary byte ──────────────── ft_print_char
        └── '%' + conversion ──────────── handle_format (static)
                                            └── type-specific printer
                                                  └── write(1, ...)
        ← successful byte counts or -1 propagate back to the caller
```

`ft_printf` scans the NUL-terminated format from left to right using an index. An ordinary character is written immediately. When the parser sees `%`, it advances to the next character and dispatches on that character. A check at this boundary prevents a trailing `%` from advancing the scan beyond the string.

The parser does not build a token list or syntax tree. Each supported conversion is handled as it is encountered. `handle_format` selects a printer, and the outer loop adds its successful byte count to the running total.

### Variadic arguments and type correctness

`va_start` initializes the argument cursor, `va_arg` retrieves the next value using the conversion's expected type, and `va_end` completes the traversal. The dispatcher receives a pointer to the caller's `va_list`, so each conversion advances the same cursor even on platforms where passing a `va_list` by value would copy its state. These operations follow C's [variadic argument interface](https://man7.org/linux/man-pages/man3/stdarg.3.html).

The type supplied to `va_arg` matters. A `char` is promoted to `int` when passed through `...`, so `%c` retrieves an `int` before the character printer converts it to a byte. Unsigned conversions retrieve `unsigned int`; pointer conversion retrieves `void *`. Callers should explicitly cast object pointers to `void *` for `%p`.

### Recursive base conversion

The numeric printers use division and remainder to emit digits in their natural order:

1. Divide by the base to obtain the remaining leading digits.
2. Recursively print that quotient when another digit is needed.
3. Print the current remainder as the final digit.

For decimal `123`, recursion visits `123 → 12 → 1`; output occurs as the calls return, producing `1`, `2`, then `3`. Decimal printers add `'0'` to a remainder between 0 and 9. Hexadecimal printers index either `"0123456789abcdef"` or `"0123456789ABCDEF"` with a remainder between 0 and 15. Uppercase conversion uses its uppercase printer at every recursive level.

Signed printers first copy the `int` into a `long`, then print a minus sign and negate the wider value. On the target platform, this makes the magnitude of `INT_MIN` representable. Zero reaches the base case and still prints one digit.

Pointer conversion uses a separate, file-local recursive helper taking `unsigned long`, retaining address bits that an `unsigned int` hexadecimal printer could discard. The returned count includes both bytes of `0x`.

### Data structures and memory management

The implementation's state consists of the format and string inputs, a `va_list`, scalar counters and numeric values, digit lookup strings, and recursive call frames. It needs no custom containers or heap allocations.

Input strings are borrowed: the library reads them without modifying or freeing them. Apart from the explicitly handled null cases, callers must supply valid, NUL-terminated strings. Recursion stores pending leading-digit work on the call stack instead of allocating a temporary conversion buffer.

For a number with `d` digits, conversion takes **O(d)** time and **O(d)** stack space, where `d` grows logarithmically with its magnitude. Overall work is linear in the format length plus the string bytes and numeric digits processed. The string printer makes one pass to count the string and another to emit it.

### Output, counting, and error propagation

Output goes to file descriptor `1`. Characters, string contents, and numeric digits are written one byte at a time; pointer prefixes and the null-pointer marker use short multi-byte writes. There is no library-managed output buffer.

Each printer returns a successful byte count or `-1`. Recursive callers check failures before adding counts, and `ft_printf` stops on failure while still calling `va_end`. A NUL character printed through `%c` counts as one byte even though a terminal does not display it.

The implementation treats a short write as failure and does not retry it. A failed call can therefore leave a partial result on stdout. This follows the distinction between requested bytes and bytes actually transferred by [`write`](https://man7.org/linux/man-pages/man2/write.2.html).

### Static library integration

The Makefile compiles each source into an object file and uses `ar` to collect them into `libftprintf.a`. Applications provide their own `main` and link this archive. Header dependencies cause object files to rebuild when `libftprintf.h` changes; an unchanged build requires no recompilation.

## Technical challenges and learning outcomes

This project develops practical understanding of:

- **Keeping parsing and argument consumption aligned:** each recognized conversion retrieves exactly the expected value, while `%%` retrieves none.
- **Representing numeric boundaries:** handling zero, negative numbers, `INT_MIN`, unsigned limits, and addresses without losing digits.
- **Using recursion for output ordering:** printing the most significant digit first without reversing a temporary string.
- **Maintaining a return-value contract:** counting signs, pointer prefixes, and invisible NUL bytes, and propagating failures through several function calls.
- **Building reusable C code:** matching declarations to definitions, compiling with strict warnings, and linking a static archive into a separate program.

## Compilation

Requirements: a C compiler named `cc`, Make, `ar`, and a Unix/POSIX environment providing `write`.

```sh
make          # Build libftprintf.a with -Wall -Wextra -Werror
make clean    # Remove object files
make fclean   # Remove object files and the archive
make re       # Clean and rebuild
```

No external library installation is needed. The default build produces a library, not an executable.

## Usage

Save this as `example.c` in the project root:

```c
#include "libftprintf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s!\n", "42");
    if (count < 0)
        return (1);
    if (ft_printf("decimal=%d hex=%x/%X count=%d\n",
            -42, 255u, 255u, count) < 0)
        return (1);
    return (0);
}
```

Compile and run it, placing the library after the caller's source:

```sh
cc -Wall -Wextra -Werror example.c -L. -lftprintf -o example
./example
```

Expected output:

```text
Hello, 42!
decimal=-42 hex=ff/FF count=11
```

For an address, use `ft_printf("%p\n", (void *)&count);`. Its value varies between executions.

## Project structure

| File | Role |
| --- | --- |
| `Makefile` | Object compilation, static archive creation, cleanup |
| `libftprintf.h` | Function declarations and required system headers |
| `ft_printf.c` | Public entry point, format scan, static conversion dispatcher |
| `ft_print_char.c` | Single-byte output |
| `ft_print_string.c` | String length helper and string output |
| `ft_print_decimal.c` | Recursive signed decimal conversion for `%d` and `%i` |
| `print_unsigned_decimal.c` | Recursive unsigned decimal conversion for `%u` |
| `ft_print_lhex.c`, `ft_print_uhex.c` | Recursive hexadecimal conversion |
| `ft_print_pointer.c` | Null-pointer marker, address prefix, full-width hexadecimal helper |
| `ft_print_number.c` | Additional signed printer, named `ft_print_nomber` in the source |
| `ft_other_cases.c` | Helper that prints `%` followed by a supplied character |
| `ft_strlen.c` | Standalone string-length function returning `size_t` |

The last three helpers are retained in the archive but are not used by the `ft_printf` conversion path.

## Testing

The repository has no committed automated test suite or `make test` target. During this review, a temporary external harness passed **1,152 checks** against the built archive and again with AddressSanitizer and UndefinedBehaviorSanitizer enabled. Coverage included:

- Byte-for-byte output and return-count comparisons with libc `snprintf` for supported, valid formats, including 1,000 deterministic mixed-argument cases.
- Signed and unsigned boundaries, zero, lowercase and uppercase hexadecimal, multiple pointers, empty strings, `%%`, and embedded NUL characters.
- Project-specific behavior for null strings and unknown conversions, checked separately from libc.
- Null formats and trailing `%`, plus injected output failures at successive byte positions, including short pointer writes.

Separate probes verified output-error handling with stdout closed. These checks establish the tested cases, not complete libc compatibility or a 42 evaluation result. Norminette was not available in the review environment.

To perform a local smoke test, build and run the usage example above. For a sanitizer build of that example and the library sources:

```sh
cc -Wall -Wextra -Werror -g -fsanitize=address,undefined \
    example.c ft_printf.c ft_print_char.c ft_print_string.c \
    ft_print_decimal.c print_unsigned_decimal.c ft_print_lhex.c \
    ft_print_uhex.c ft_print_pointer.c ft_print_number.c \
    ft_other_cases.c ft_strlen.c -o example_san
./example_san
```

When extending comparisons, check both bytes and return values; use a byte-aware comparison for `%c` with zero. Invalid formats and null strings are not portable libc reference cases.

## Resources

- [Linux manual: `printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — conversion syntax, argument types, and return semantics of the standard function.
- [Linux manual: `stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — variable-argument traversal and default argument promotions.
- [Linux manual: `write`](https://man7.org/linux/man-pages/man2/write.2.html) — file descriptors, transferred byte counts, and output failures.
- The project subject available through the 42 intranet is the reference for your assigned requirements; it is not bundled here.

