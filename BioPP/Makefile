
vpath %.cpp src
vpath %.hpp include

.SUFFIXES:
.SUFFIXES: .cpp .hpp

SHELL         = /bin/sh

COMPILERWARN  = -Wall -Wextra -pedantic
OPTIMIZATIONS = -O3 -mtune=intel -march=skylake -mavx2
BUILDFLAGS    =    $(COMPILERWARN) $(OPTIMIZATIONS)

CC            =  gcc
CXX           =  g++
CFLAGS        = -std=c11   $(BUILDFLAGS)
CXXFLAGS      = -std=c++17 $(BUILDFLAGS)

SOURCES_DIR   = src
INCLUDES_DIR  = include

SRC_HEADERS   = -I $(INCLUDES_DIR)
INCLUDEDIRS   =    $(SRC_HEADERS)

BOOST_OPTS    = -lboost_program_options
BOOST_LIBS    =    $(BOOST_OPTS)
IPPLIB        = -L $(IPPLIBDIR)   -lippcc -lippcore
IPPCPLIB      = -L $(IPPCPLIBDIR) -lippcp
REQLIBS       =    $(BOOST_LIBS)

SRCS          = BioPerl.cpp Nucleotides.cpp
HEADERS       = $(patsubst %.cpp, %.hpp, $(SRCS))
OBJS          = $(patsubst %.cpp, %.o, $(SRCS))
PROGRAM       = bio

OUTPUT_OPTION = -o $@
TARGET_ARCH   = 

COMPILE.cpp   = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEDIRS) $(TARGET_ARCH) -c
LINK.o        = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEDIRS) $(TARGET_ARCH) $(LDFLAGS) 

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LINK.o) $(OUTPUT_OPTION) $^ $(REQLIBS)

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $^ 

.PHONY: clean
clean:
	$(RM) $(OBJS) $(PROGRAM)
