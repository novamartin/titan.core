##############################################################################
# Copyright (c) 2000-2017 Ericsson Telecom AB
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v10.html
#
# Contributors:
#   Baranyi, Botond – initial implementation
#
##############################################################################
TOPDIR := ../..
include $(TOPDIR)/Makefile.regression

.PHONY: all clean dep

TTCN3_LIB := ttcn3$(RT2_SUFFIX)$(DYNAMIC_SUFFIX)

MODULES := M.ttcn

USER_SOURCES := ext.cc

GENERATED_SOURCES := $(MODULES:.ttcn=.cc)
GENERATED_HEADERS := $(GENERATED_SOURCES:.cc=.hh)
ifdef CODE_SPLIT
GENERATED_SOURCES := $(foreach file, $(GENERATED_SOURCES:.cc=), $(addprefix $(file), .cc _seq.cc _set.cc  _seqof.cc _setof.cc _union.cc))
else ifdef SPLIT_TO_SLICES
POSTFIXES := $(foreach file, $(SPLIT_TO_SLICES), $(addsuffix $(file), _part_))
POSTFIXES := $(foreach file, $(POSTFIXES), $(addprefix $(file), .cc))
GENERATED_SOURCES2 := $(foreach file, $(GENERATED_SOURCES:.cc=), $(addprefix $(file), $(POSTFIXES)))
GENERATED_SOURCES += $(GENERATED_SOURCES2)
endif

OBJECTS := $(GENERATED_SOURCES:.cc=.o) $(USER_SOURCES:.cc=.o)

TARGET := deterministic$(EXESUFFIX)

all: $(TARGET) ;

$(TARGET): $(GENERATED_SOURCES) $(USER_SOURCES)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ -L$(TTCN3_DIR)/lib -l$(TTCN3_LIB) \
	-L$(OPENSSL_DIR)/lib -lcrypto $($(PLATFORM)_LIBS)

$(GENERATED_SOURCES) $(GENERATED_HEADERS): compile
	@if [ ! -f $@ ]; then $(RM) compile; $(MAKE) compile; fi

compile: $(MODULES)
	$(TTCN3_COMPILER) $(COMPILER_FLAGS) $^ - $?
	touch $@

clean distclean:
	-$(RM) $(TARGET) $(OBJECTS) $(GENERATED_HEADERS) \
	$(GENERATED_SOURCES) compile *.log Makefile.bak

dep: $(GENERATED_SOURCES) $(USER_SOURCES)
	makedepend $(CPPFLAGS) $(USER_SOURCES) $(GENERATED_SOURCES)
