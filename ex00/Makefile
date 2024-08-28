# Variables de fichiers
SRCS = $(wildcard *.cpp)
HPP = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)
EXEC = Bureaucrat

ANSI_RESET   = \x1b[0m
ANSI_RED     = \x1b[31m
ANSI_GREEN   = \x1b[32m
ANSI_YELLOW  = \x1b[33m
ANSI_BLUE    = \x1b[34m
ANSI_MAGENTA = \x1b[35m
ANSI_CYAN    = \033[0;96m
ANSI_WHITE   = \x1b[37m


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(EXEC)
	@echo "$(ANSI_GREEN)Compilation terminée avec succès!$(ANSI_RESET)"

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)
	@sleep 0.5
	@echo "$(ANSI_BLUE)Linking terminé!$(ANSI_RESET)"

%.o: %.cpp $(HPP)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@sleep 0.5
	@echo "$(ANSI_CYAN)Compilation de $< terminée.$(ANSI_RESET)"

clean:
	rm -f $(OBJS)
	@sleep 0.5
	@echo "$(ANSI_RED)Fichiers objets supprimés.$(ANSI_RESET)"

fclean: clean
	rm -f $(EXEC)
	@sleep 0.5
	@echo "$(ANSI_RED)Exécutable supprimé.$(ANSI_RESET)"

re: fclean all
