EnchantmentDriver:  Enchantment.o EnchantmentDriver.o
	g++ -g -Wall -std=c++11 -o EnchantmentDriver Enchantment.o EnchantmentDriver.o

Enchantment.o:  Enchantment.cpp Enchantment.h
	g++ -g -Wall -std=c++11 -c Enchantment.cpp

EnchantmentDriver.o:  EnchantmentDriver.cpp Enchantment.h
	g++ -g -Wall -std=c++11 -c EnchantmentDriver.cpp

EntityDriver:  Entity.o EntityDriver.o
	g++ -g -Wall -std=c++11 -o EntityDriver Entity.o EntityDriver.o

Entity.o:  Entity.cpp Entity.h
	g++ -g -Wall -std=c++11 -c Entity.cpp

EntityDriver.o:  EntityDriver.cpp Entity.h
	g++ -g -Wall -std=c++11 -c EntityDriver.cpp

