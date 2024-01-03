# Proje ismi (yürütülebilir dosyanın adı)
PROJECT_NAME := main

# Kaynak (.cpp) ve header (.h) dosyalarını bul
SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.h)

# İşletim Sistemi tespiti
OS := MINGW32_NT-6.2

# Başlık ve kütüphane dosyalarının yolu
INCLUDE_PATH := ..\src
LIBRARY_PATH := ..\src

# Derleyici ve derleyici bayrakları
CXX := g++
CXXFLAGS := -std=c++17 -Wall -I$(INCLUDE_PATH)

# Linker bayrakları ve işletim sistemine özgü ayarlar
LDFLAGS := -L$(LIBRARY_PATH) -lraylib
ifeq ($(OS), Linux)
    LDFLAGS += -lGL -lm -lpthread -ldl -lrt -lX11
endif
ifeq ($(OS), Darwin) # macOS için
    LDFLAGS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif
ifeq ($(OS), MINGW32_NT-6.2) # Windows için, OS değeri sisteme göre değişebilir
    LDFLAGS += -lopengl32 -lgdi32 -lwinmm
endif

# Derleme hedefi
build: $(SOURCES) $(HEADERS) make_library
	$(CXX) $(CXXFLAGS) $(SOURCES) $(LDFLAGS) -o $(PROJECT_NAME)

# Çalıştırma hedefi

make_library:
	$(MAKE) -C $(LIBRARY_PATH) -f Makefile

run: build
	./$(PROJECT_NAME)

# Temizleme komutu
clean:
	del $(PROJECT_NAME)
	$(MAKE) -C $(LIBRARY_PATH) -f Makefile clean
