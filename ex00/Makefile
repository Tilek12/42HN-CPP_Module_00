# Color codes
GREEN = \033[0;32m
VIOLET = \033[0;35m
RESET = \033[0m

# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
TARGET = megaphone
SRC = megaphone.cpp

# Default target
all: $(TARGET)

# Compilation rule
$(TARGET): $(SRC)
	@echo "$(GREEN)$(TARGET) created.$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) > /dev/null 2>&1

# Cleaning rule
clean:
	@echo "$(VIOLET)$(TARGET) deleted.$(RESET)"
	@rm -f $(TARGET) > /dev/null 2>&1

# Phony target
.PHONY: all clean
