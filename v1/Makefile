# possible choices for variant to compile
  Variant= USE_MY_OWN_IMPLEMENTATION
# other choices - (un-)comment accordingly
# Variant= USE_FAILING_AI_IMPLEMENTATION
# Variant= USE_IMPROVED_AI_IMPLEMENTATION

Compile= g++ -std=c++17 -D$(Variant)
TestDriver= assert_based

default: run-tests

run-tests: assert_based
	@./$(TestDriver)
run-demo-app: demo_app
	@./demo_app

$(TestDriver) demo_app: ChainCounter.h ChainCounter.cpp

$(TestDriver): Counter_Test.cpp ChainCounter.cpp
	$(Compile) -o $@ Counter_Test.cpp ChainCounter.cpp

demo_app: Counter_App.cpp
	$(Compile) -o $@ Counter_App.cpp ChainCounter.cpp

clean:
	rm -f $(TestDriver) demo_app
realclean: clean
	rm -f a.out core *.o


.PHONY: default
.PHONY: run-tests
.PHONY: run-demo-app
.PHONY: clean
.PHONY: realclean
