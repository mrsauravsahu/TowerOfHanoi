OUTDIR = out
ifeq ($(OS),Windows_NT)
	INCLUDE     = -Iinclude -I"F:/MiniProjects/TowerOfHanoi/include"
	LIBS        = -L"C:/Program Files (x86)/Dev-Cpp/MinGW32/lib" -static-libstdc++ -static-libgcc "C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libopengl32.a" "C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libglu32.a" "C:/Program Files (x86)/Dev-Cpp/MinGW32/lib/libglut32.a"
	CFLAGS      = $(INCLUDE) -lglu32 -lglut32 -lopengl32 -lm 
	BIN         = $(OUTDIR)/toh.exe
else
	BIN         = $(OUTDIR)/toh.out
	INCLUDE     = -Iinclude
	CFLAGS      = $(INCLUDE) -lGL -lGLU -lglut -lm
endif

LIBSRC          = $(wildcard lib/*.c)
LIB             = $(LIBSRC:.c=.o)
MODELSRC        = $(wildcard src/model/*.c)
MODEL           = $(MODELSRC:.c=.o)
VIEWMODELSRC    = $(wildcard src/viewmodel/*.c)
VIEWMODEL       = $(VIEWMODELSRC:.c=.o)
MODULES         = out/*.o

all: $(BIN) clean

$(BIN): $(LIB) $(MODEL) $(VIEWMODEL)
	gcc -g $(INCLUDE) src/main.c $(MODULES) -o $(BIN) $(CFLAGS) $(LIBS)

%.o: %.c
	gcc -g -c $^ $(CFLAGS) -o out/$(basename $(<F)).o --std=c99

clean:
	rm $(OUTDIR)/*.o -rf
	rm $(OUTDIR)/.f* -rf

cleano:
	rm out/*.o