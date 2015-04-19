CXX=clang++ -Wall -std=c++11
SOLUTION=A

.PHONY: sample
sample:
	$(CXX) $(SOLUTION).cpp -o $(SOLUTION)
	cd $(sample) && ../$(SOLUTION) && cat output.txt
