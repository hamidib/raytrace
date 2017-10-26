#
# Copyright (c) 2006 Michael Shafae <mshafae at ics dot uci dot edu>.
# All rights reserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# $Id: Makefile 978 2008-09-03 20:37:31Z mshafae $
#

INCLUDES += -I ~/github/TitanOpenGLKit/TitanOpenGLKit_osx/include -L ~/github/TitanOpenGLKit/TitanOpenGLKit_osx/lib

#
# Add or remove the -DNDEBUG to activate or deactivate your code
#
# ex. your code on:  CFLAGS += -g -DNDEBUG -Wall -pipe $(INCLUDES)
# or  your code off: CFLAGS += -g -Wall -pipe $(INCLUDES)
#
CFLAGS += -std=c++11 -g -DNDEBUG -Wall -pedantic -pipe $(INCLUDES)
LDFLAGS += -g -Wall -pipe -lfreeimageplus

TARGET = raytrace
# C Files
CPPFILES = raytrace.cpp Scene.cpp
CFILES = getopt_long.c
# Headers
HEADERS = Camera.h Group.h Hit.h Image.h Material.hRay.h Scene.h common.h getopt.h


OBJECTS = $(CPPFILES:.cpp=.o) $(CFILES:.c=.o)

DEP = $(CPPFILES:.cpp=.d) $(CFILES:.c=.d)

default all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LLDLIBS)

-include $(DEP)

%.d: %.c
	set -e; $(CXX) -MM $(CFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
	[ -s $@ ] || rm -f $@

%.d: %.cpp
	set -e; $(CXX) -MM $(CFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
	[ -s $@ ] || rm -f $@

%.o: %.c
	$(CXX) $(CFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	-rm -f $(OBJECTS) core $(TARGET).core *~

spotless: clean
	-rm -f $(TARGET) $(DEP)

