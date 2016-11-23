OUTDIR = out
ifeq ($(OS),Windows_NT)
	INCLUDE     = -Iinclude -I"F:/MiniProjects/TowerOfHanoi/include"
	LIBS        = -L"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib" -static-libstdc++ -static-libgcc "C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libopengl32.a" "C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libglu32.a" "C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libglut32.a"
	CFLAGS      = $(INCLUDE) -lglu32 -lglut32 -lopengl32 -lm 
	BIN         = toh.exe
else
	BIN         = toh
	INCLUDE     = -Iinclude
	CFLAGS      = $(INCLUDE) -lGL -lGLU -lglut -lm
endif

LIBSRC          = $(wildcard lib/*.c)
LIB             = $(LIBSRC:.c=.o)
MODELSRC        = $(wildcard src/model/*.c)
MODEL           = $(MODELSRC:.c=.o)
VIEWSRC        = $(wildcard src/view/*.c)
VIEW           = $(VIEWSRC:.c=.o)
VIEWMODELSRC    = $(wildcard src/viewmodel/*.c)
VIEWMODEL       = $(VIEWMODELSRC:.c=.o)
MODULES         = *.o

all: $(BIN) clean

$(BIN): $(LIB) $(MODEL) $(VIEW) $(VIEWMODEL)
	gcc $(INCLUDE) src/main.c $(MODULES) -o $(BIN) $(CFLAGS) $(LIBS)

%.o: %.c
	gcc -c $^ $(CFLAGS) -o $(basename $(<F)).o --std=c99

stringopstest:
	gcc -Iinclude lib/stringops.c tests/stringopstest.c -o tests/stringopstest.out

clean:
	rm *.o -rf
	rm .f* -rf