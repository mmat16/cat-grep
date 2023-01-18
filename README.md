# cat-grep
## school 21 studying project 
In this project i implemented cat and grep unix utilities in C programming language with standart of C11.

Code is checked for all possible memory leaks, conditional jumps and also follows the Google Style.

### cat
cat supports following flags: "-b" "-e" "-n" "-s" "-t" "-v" "-E" "-T" "--number" "--number-nonblank" "--squeeze-blank"

cat doesn't support input via stdin, files only

### grep
grep supports following flags "-e <pattern>" "-i" "-v" "-c" "-l" "-n" "-h" "-s" "-f <file>"

### build
utilities can be build using gcc and make. just go to src directory and type in make or make s21_grep or make s21_cat. it would build a binary in its directories:

s21_cat in cat directory, s21_grep in grep directory

you can also delete them using make clean and rebuild using make rebuild.

Hope you enjoy my work and waiting for some feedback!
