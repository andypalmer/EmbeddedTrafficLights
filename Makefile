#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = test_arduino
TARGET_LIB = \
  lib/lib$(COMPONENT_NAME).a

TEST_TARGET = \
  $(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPP_PLATFORM = Gcc

CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_WARNINGFLAGS += -Wall
CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wswitch-default
CPPUTEST_WARNINGFLAGS += -Wswitch-enum
CPPUTEST_WARNINGFLAGS += -Wno-unused-parameter
CPPUTEST_CFLAGS += -std=c89
CPPUTEST_CFLAGS += -Wextra
CPPUTEST_CFLAGS += -pedantic
CPPUTEST_CFLAGS += -Wstrict-prototypes

SRC_DIRS = \
  src/*\

TEST_SRC_DIRS = \
  tests \
  tests/util \
  tests/devices \
  tests/HomeAutomation\
  mocks

INCLUDE_DIRS =\
  $(CPPUTEST_HOME)/include/\
  include/*\
  mocks

include ./MakefileWorker.mk
