CROSS_COMPILE = 
CXX = $(CROSS_COMPILE)g++ $(CFLAGS)
CPPFLAGS = -Wall -g

TARGET = sample









INCLUDES = -I./include
INCLUDES += ${shell pkg-config opencv --cflags}




LINKLIBS = -L./depends/lib -lMVSDK -lImageConvert

LINKLIBS += ${shell pkg-config opencv --libs}




SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

$(TARGET):$(OBJECTS)
	$(CXX) $(INCLUDES) $(CPPFLAGS) $(OBJECTS) $(LINKLIBS) -o $(TARGET)
	rm -f $(OBJECTS)
	
.cpp.o:
	$(CXX) $(INCLUDES) -c $(CPPFLAGS) $< -o $@
	
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET)

	
