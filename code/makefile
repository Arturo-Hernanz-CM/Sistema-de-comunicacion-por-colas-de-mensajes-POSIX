# Nombre del ejecutable
TARGET = servidor

# Archivos fuente
SRCS = servidor-mq.c claves.c

# Archivos objeto (los .o)
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -g -pthread -lrt

# Regla principal: compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos .c en archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)
