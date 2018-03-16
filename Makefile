NAME = test
CC = gcc
ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -Wextra -g -O0
else
	CFLAGS = -Ofast -march=native -Wall -Wextra
endif

SRC_MAIN = test.c
SRC_FT = ft_strcmp.c ft_asprintf.c
SRC_PRINT = generic_print_str.c generic_print_nbr.c generic_print_hex.c generic_vprintf.c vprintf_len.c
SRC_BUFFER = buffer.c buffer_fd_f.c buffer_fd.c
SRC_HASHMAP = hashmap_init_crc_0.c hashmap_init_crc_1.c hashmap_init_crc_2.c \
                hashmap_init.c hashmap_crc32.c hashmap.c hashmap_op.c
SRC_UNITTEST = unittest_assert.c unittest.c
HEADERS = ft.h print.h buffer.h hashmap.h unittest.h

SRC = $(SRC_FT) $(SRC_PRINT) $(SRC_BUFFER) $(SRC_MAIN) $(SRC_HASHMAP) $(SRC_UNITTEST)
OBJ_TMP = $(SRC:.c=.o)

VPATH = src/ft src/buffer src/print src/hashmap src/unittest
IFLAGS = -Isrc
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_TMP))

OBJ_TMP_TESTS = $(SRC_TESTS:.c=.o)
OBJ_TESTS = $(addprefix $(OBJ_DIR)/, $(OBJ_TMP_TESTS))

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $< $(IFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_TESTS)

fclean: clean
	rm -f $(NAME) test

re: fclean all

.PHONY: all, clean, fclean, re
