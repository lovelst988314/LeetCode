CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra
OBJS = main.o Account.o SavingsAccount.o CreditAccount.o AccountManager.o
TARGET = bank_system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

