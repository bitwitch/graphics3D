LIBRARIES = -framework Cocoa -framework Quartz -framework OpenGL -lcocoawindowing_s -lpng
LIBDIR = -L ./bin
INCLUDEDIR = -I ./include
CPPFLAGS = -std=c++14 -Wall -Wno-missing-braces

all:
	clang++ -arch x86_64 $(CPPFLAGS) $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) *.cpp -o demo
clean:
	-rm demo
