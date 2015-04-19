CXX=clang++ -Wall -std=c++11
SOLUTION=A
CHECKER=python3 checker.py

.DEFAULT_GOAL=sample

.PHONY: solution
solution:
	$(CXX) $(SOLUTION).cpp -o $(SOLUTION)

.PHONY: sample
sample: solution
	cd $(sample) && ../$(SOLUTION)
	$(CHECKER) $(sample)

SAMPLES:=01 02 03 04 05 06 07 08 09 10

.PHONY: all
all: solution
	$(foreach sample,$(SAMPLES),(cd $(sample) && /bin/echo -n "$(sample) " && ../$(SOLUTION));)
	$(CHECKER) $(SAMPLES)
