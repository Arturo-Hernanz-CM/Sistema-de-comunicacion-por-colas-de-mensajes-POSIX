# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -g -fPIC -pthread -lrt

# Archivos fuente
SRCS_SERVER = servidor-mq.c claves.c
SRCS_PROXY = proxy-mq.c
SRCS_CLIENT = app-cliente.c

# Archivos objeto
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_PROXY = $(SRCS_PROXY:.c=.o)

# Librería compartida
LIB_NAME = libclaves.so

# Ejecutables
TARGET_SERVER = servidor
TARGET_CLIENT = app-cliente

# Regla por defecto: compilar todo
all: $(TARGET_SERVER) $(LIB_NAME) $(TARGET_CLIENT)

# Compilar el servidor
$(TARGET_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $(OBJS_SERVER)

# Crear la librería compartida
$(LIB_NAME): $(OBJS_PROXY)
	$(CC) -shared -o $(LIB_NAME) $(OBJS_PROXY)

# Compilar el cliente y vincular la librería
$(TARGET_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT) $(SRCS_CLIENT) -L. -lclaves

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS_SERVER) $(OBJS_PROXY) $(TARGET_SERVER) $(TARGET_CLIENT) $(LIB_NAME)