CXX       = clang++ -Wall -std=c++11
CXX_FLAGS =
PROG      = A
CHECKER   = python3 check.py

ifdef DEBUG
	CXX_FLAGS += -DDEBUG
endif

.DEFAULT_GOAL = sample

.PHONY: run
solution:
	$(CXX) $(CXX_FLAGS) $(PROG).cpp -o data/$(PROG)

.PHONY: sample
run: solution
	cd data/$(sample)/sources && ../../$(PROG)
	$(CHECKER) $(sample)
