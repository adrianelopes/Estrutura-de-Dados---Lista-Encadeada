# Nome do executável
EXEC = programa

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -std=c++11

# Arquivos-fonte
SRCS = main.cpp Lista.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra principal: compilar o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para rodar o programa
run: $(EXEC)
	./$(EXEC)

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJS) $(EXEC)