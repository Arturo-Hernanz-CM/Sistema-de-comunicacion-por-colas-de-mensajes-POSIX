# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -g -fPIC -pthread -lrt

# Archivos fuente
SRCS_SERVER = servidor-mq.c claves.c
SRCS_PROXY = proxy-mq.c
SRCS_CLIENT0 = app-cliente0.c
SRCS_CLIENT1 = app-cliente1.c
SRCS_CLIENT2 = app-cliente2.c
SRCS_CLIENT3 = app-cliente3.c
SRCS_CLIENT4 = app-cliente4.c
SRCS_CLIENT5 = app-cliente5.c

# Archivos objeto
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_PROXY = $(SRCS_PROXY:.c=.o)

# Librería compartida
LIB_NAME = libclaves.so

# Ejecutables
TARGET_SERVER = servidor
TARGET_CLIENT0 = app-cliente0
TARGET_CLIENT1 = app-cliente1
TARGET_CLIENT2 = app-cliente2
TARGET_CLIENT3 = app-cliente3
TARGET_CLIENT4 = app-cliente4
TARGET_CLIENT5 = app-cliente5

# Regla por defecto: compilar todo
all: $(TARGET_SERVER) $(LIB_NAME) $(TARGET_CLIENT0) $(TARGET_CLIENT1) $(TARGET_CLIENT2) $(TARGET_CLIENT3) $(TARGET_CLIENT4) $(TARGET_CLIENT5)

# Compilar el servidor
$(TARGET_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $(OBJS_SERVER)

# Crear la librería compartida
$(LIB_NAME): $(OBJS_PROXY)
	$(CC) -shared -o $(LIB_NAME) $(OBJS_PROXY)

# Compilar los clientes y vincular la librería
$(TARGET_CLIENT0): $(SRCS_CLIENT0)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT0) $(SRCS_CLIENT0) -L. -lclaves

$(TARGET_CLIENT1): $(SRCS_CLIENT1)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT1) $(SRCS_CLIENT1) -L. -lclaves

$(TARGET_CLIENT2): $(SRCS_CLIENT2)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT2) $(SRCS_CLIENT2) -L. -lclaves

$(TARGET_CLIENT3): $(SRCS_CLIENT3)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT3) $(SRCS_CLIENT3) -L. -lclaves

$(TARGET_CLIENT4): $(SRCS_CLIENT4)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT4) $(SRCS_CLIENT4) -L. -lclaves

$(TARGET_CLIENT5): $(SRCS_CLIENT5)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT5) $(SRCS_CLIENT5) -L. -lclaves

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS_SERVER) $(OBJS_PROXY) $(TARGET_SERVER) $(TARGET_CLIENT0) $(TARGET_CLIENT1) $(TARGET_CLIENT2) $(TARGET_CLIENT3) $(TARGET_CLIENT4) $(TARGET_CLIENT5) $(LIB_NAME)