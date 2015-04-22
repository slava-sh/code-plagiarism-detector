CXX           = clang++ -Wall -std=c++11
CXX_FLAGS     =
PROG          = A
CHECK         = python3 check.py
PLOT          = python3 plot.py

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
	$(CHECK) $(sample)

.PHONY: plot
plot:
	$(PLOT) $(sample)
	open data/$(sample)/data.svg

ALL_SAMPLES = $(filter-out all, $(subst /,, $(subst data,, $(filter %/, $(wildcard data/*/)))))

.PHONY: score
score:
	$(CHECK) $(ALL_SAMPLES) >data/score.txt
	sed '/\//q' data/score.txt
