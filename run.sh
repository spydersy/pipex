#clang-9 -Wall -Werror -Wextra -g3  -fsanitize=address *.c ./*/*.c -o pipex
clang-9 -Wall -Werror -Wextra -g3 *.c ./*/*.c -o pipex
