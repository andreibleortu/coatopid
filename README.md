# COAtoPID
CLI tool for converting Microsoft COA codes to Product IDs. Completely cross-platform.

## Input format
COA codes are read from a file named `coa.txt` and the resulting Product IDs will be written in `pids.txt`. Multiple COAs can be placed in the input file, one per line.

## Output example
`12345 678 912 345` is converted to `01234-56789-12345-AAOEM`. Each Product ID will be output on a separate line.
