gcc -Wall -Werror -Wextra -g3  -fsanitize=address *.c ./*/*.c -o pipex
gcc -Wall -Werror -Wextra -g3 *.c ./*/*.c -o pipex
