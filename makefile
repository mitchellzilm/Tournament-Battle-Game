#subject: OOP
#major programming practical
#group members - Duddlie Yu, Emerson Yu, Mitchell Zilm
#makefile for the player constructor 

#default target is all
all: main

#main function links the object files together
main: players.o weapons.o heavyweapon.o lightweapon.o rangeweapon.o armour.o main.o player_weapon_function.o armour_choice_function.o userValidation.o battle_function.o
	clang++ players.o weapons.o heavyweapon.o lightweapon.o rangeweapon.o armour.o main.o player_weapon_function.o armour_choice_function.o userValidation.o battle_function.o -o main

#if either players.h or players.cpp are edited, 
#players.o will need to be recompiled to ensure these changes are accounted for.
players.o: players.cpp players.h 
	clang++ -c players.cpp -o players.o

#if either weapons.h or weapons.cpp are edited, 
#weapons.o will need to be recompiled to ensure these changes are accounted for.
weapons.o: weapons.cpp weapons.h 
	clang++ -c weapons.cpp -o weapons.o

#if either heavyweapon.h or heavyweapon.cpp are edited, 
#heavyweapon.o will need to be recompiled to ensure these changes are accounted for.
heavyweapon.o: heavyweapon.cpp heavyweapon.h 
	clang++ -c heavyweapon.cpp -o heavyweapon.o

#if either lightweapon.h or lightweapon.cpp are edited, 
#lightweapon.o will need to be recompiled to ensure these changes are accounted for.
lightweapon.o: lightweapon.cpp lightweapon.h 
	clang++ -c lightweapon.cpp -o lightweapon.o

#if either rangeweapon.h or rangeweapon.cpp are edited, 
#rangeweapon.o will need to be recompiled to ensure these changes are accounted for.
rangeweapon.o: rangeweapon.cpp rangeweapon.h 
	clang++ -c rangeweapon.cpp -o rangeweapon.o

#if either armour.h or armour.cpp are edited, 
#armour.o will need to be recompiled to ensure these changes are accounted for.
armour.o: Armour.cpp Armour.h 
	clang++ -c Armour.cpp -o armour.o


#if either main.cpp or any of the .h files are edited, 
#main.o will need to be recompiled to ensure these changes are accounted for.

main.o: main.cpp players.h weapons.h heavyweapon.h lightweapon.h rangeweapon.h Armour.h
	clang++ -c main.cpp -o main.o

#testing
battleTest: battleTest.o
	clang++ -c battleTest.cpp -o battleTest

ArmourTest: ArmourTest.o
	clang++ -c ArmourTest.cpp -o ArmourTest

weapTest: weapTest.cpp
	clang++ -c weapTest.cpp -o weapTest

weapTest2: weapTest2.cpp
	clang++ -c weapTest2.cpp -o weapTest2
	
weapTestHW: weapTestHW.cpp
	clang++ -c weapTestHW.cpp -o weapTestHW

weapTestLW: weapTestHW.cpp
	clang++ -c weapTestHW.cpp -o weapTestLW

weapTestRW: weapTestHW.cpp
	clang++ -c weapTestHW.cpp -o weapTestRW
	
	
#Testing output for main classes
playersTest: players.o
	./playersTest < players_input.txt | diff - players_output.txt

weaponsTest: weapons.o
	./weapTest < weapons_input.txt | diff - weapon_output.txt

armTest: armour.o
	./ArmourTest < armour_input.txt	| diff - armour_output.txt

#the clean will remove each individual object and the compiled code
clean:
	rm -f *.o main


