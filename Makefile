build:
	g++ lanParty.cpp ListOfTeams.cpp Player.cpp Team.cpp Queue.cpp Stack.cpp utils.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm lanParty