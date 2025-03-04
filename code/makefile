# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -g -pthread -lrt

# Archivos fuente
SRCS_SERVER = servidor-mq.c claves.c
SRCS_PROXY = proxy-mq.c

# Archivos objeto
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_PROXY = $(SRCS_PROXY:.c=.o)

# Ejecutables
TARGET_SERVER = servidor
TARGET_PROXY = proxy

# Regla por defecto: compilar todo
all: $(TARGET_SERVER) $(TARGET_PROXY)

# Compilar el servidor
$(TARGET_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $(OBJS_SERVER)

# Compilar el PROXYe
$(TARGET_PROXY): $(OBJS_PROXY)
	$(CC) $(CFLAGS) -o $(TARGET_PROXY) $(OBJS_PROXY)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS_SERVER) $(OBJS_PROXY) $(TARGET_SERVER) $(TARGET_PROXY)